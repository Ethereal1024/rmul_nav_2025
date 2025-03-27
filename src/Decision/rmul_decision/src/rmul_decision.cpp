#include "fsm_commander.hpp"

FSMCommander::FSMCommander(const rclcpp::NodeOptions& options) : Node("fsm_commander", options) {
    state_ = State::IDLE;
    next_state_ = State::IDLE;
    reset_ = true;

    game_ = {false, Event::UNOCCUPIED};
    self_ = {Point(0, 0), FULL_HP};
    // enemy_ = {false, Point(0, 0)};

    event_data_sub_ = this->create_subscription<pb_rm_interfaces::msg::EventData>(
        "referee/event_data", 10, std::bind(&FSMCommander::event_data_callback, this, std::placeholders::_1));
    robot_status_sub_ = this->create_subscription<pb_rm_interfaces::msg::RobotStatus>(
        "referee/robot_status", 10, std::bind(&FSMCommander::robot_status_callback, this, std::placeholders::_1));
    game_status_pub_ = this->create_subscription<pb_rm_interfaces::msg::GameStatus>(
        "referee/game_status", 10, std::bind(&FSMCommander::game_status_callback, this, std::placeholders::_1));
    pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
        "navigator/current_pose", 10, std::bind(&FSMCommander::pose_callback, this, std::placeholders::_1));

    nav_pub_ = this->create_publisher<navigator_interfaces::msg::Navigate>("to_navigator", 10);

    timer_ = this->create_wall_timer(std::chrono::seconds(4), std::bind(&FSMCommander::timer_callback, this));

    index_ = 0;
    ideling_ = true;
}

void FSMCommander::timer_callback() {
    switch (state_) {
    case State::IDLE:
        if (game_.started && self_.hp == FULL_HP) {
            if (game_.event == Event::UNOCCUPIED) {
                next_state_ = State::OCCUPY;
            } else {
                next_state_ = State::SNIPE;
            }
        }
        break;
    case State::OCCUPY:
        if (self_.hp < 0.35 * FULL_HP) {
            next_state_ = State::ESCAPE;
        } else {
            next_state_ = State::OCCUPY;
        }
        break;
    case State::ESCAPE:
        if ((self_.position - HOME).norm() < 0.05) {
            next_state_ = State::IDLE;
        } else {
            next_state_ = State::ESCAPE;
        }
        break;
    case State::SNIPE:
        if (self_.hp < 0.35 * FULL_HP) {
            next_state_ = State::ESCAPE;
        } else if (game_.event == Event::UNOCCUPIED) {
            next_state_ = State::OCCUPY;
        } else {
            next_state_ = State::SNIPE;
        }
        break;
    default:
        next_state_ = state_;
    }

    if (reset_) {
        state_ = State::IDLE;
        next_state_ = State::IDLE;
        game_ = {false, Event::UNOCCUPIED};
        self_ = {Point(0, 0), 600};
        index_ = 0;
        ideling_ = true;

        reset_ = false;
    } else {
        state_ = next_state_;
    }

    switch (state_) {
    case State::IDLE:
        idel_exec();
        break;
    case State::OCCUPY:
        ideling_ = false;
        occupy_exec();
    case State::ESCAPE:
        ideling_ = false;
        escape_exec();
    case State::SNIPE:
        ideling_ = false;
        snipe_exec();
    default:
        break;
    }
}

void FSMCommander::idel_exec() {
    if (!ideling_)
        nav_to_point(self_.position);
    ideling_ = true;
}

void FSMCommander::occupy_exec() {
    nav_to_point(OCCUPY_POINTS[(index_++) % OCCUPY_POINTS.size()]);
}

void FSMCommander::escape_exec() {
    nav_to_point(HOME);
}

void FSMCommander::snipe_exec() {
    nav_to_point(SNIPE_POINTS[(index_++) % SNIPE_POINTS.size()]);
}

void FSMCommander::event_data_callback(const pb_rm_interfaces::msg::EventData::SharedPtr msg) {
    switch (msg->center_gain_zone) {
    case 0:
        game_.event = Event::UNOCCUPIED;
        break;
    case 1:
        game_.event = Event::OCCUPIED_FRIEND;
        break;
    case 2:
        game_.event = Event::OCCUPIED_ENEMY;
        break;
    case 3:
        game_.event = Event::OCCUPIED_BOTH;
        break;
    default:
        break;
    }
}

void FSMCommander::robot_status_callback(const pb_rm_interfaces::msg::RobotStatus::SharedPtr msg) {
    self_.hp = msg->current_hp;
}

void FSMCommander::game_status_callback(const pb_rm_interfaces::msg::GameStatus::SharedPtr msg) {
    game_.started = (msg->game_progress == msg->RUNNING);
}

void FSMCommander::pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg) {
    self_.position = Point(msg->pose.position.x, msg->pose.position.y);
}

void FSMCommander::nav_to_point(const double& x, const double& y) {
    navigator_interfaces::msg::Navigate msg;
    msg.instant = true;
    msg.pose.header.stamp = this->now();
    msg.pose.header.frame_id = "map";
    msg.pose.pose.position.x = x;
    msg.pose.pose.position.y = y;
    msg.pose.pose.position.z = 0;
    msg.pose.pose.orientation.x = 0;
    msg.pose.pose.orientation.y = 0;
    msg.pose.pose.orientation.z = 0;
    msg.pose.pose.orientation.w = 1;
    nav_pub_->publish(msg);
}

void FSMCommander::nav_to_point(const Point& point) {
    nav_to_point(point.x, point.y);
}
