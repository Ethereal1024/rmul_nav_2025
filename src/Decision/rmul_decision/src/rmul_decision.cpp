#include "fsm_commander.hpp"

FSMCommander::FSMCommander(const rclcpp::NodeOptions& options) : Node("fsm_commander", options) {
    game_ = {false, Event::UNOCCUPIED};
    self_ = {Point(0, 0), 600};
    // enemy_ = {false, Point(0, 0)};

    event_data_sub_ = this->create_subscription<pb_rm_interfaces::msg::EventData>(
        "referee/event_data", 10, std::bind(&FSMCommander::event_data_callback, this, std::placeholders::_1));
    robot_status_sub_ = this->create_subscription<pb_rm_interfaces::msg::RobotStatus>(
        "referee/robot_status", 10, std::bind(&FSMCommander::robot_status_callback, this, std::placeholders::_1));
    pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseStamped>(
        "referee/robot_status", 10, std::bind(&FSMCommander::pose_callback, this, std::placeholders::_1));

    nav_pub_ = this->create_publisher<navigator_interfaces::msg::Navigate>("to_navigator", 10);

    timer_ = this->create_wall_timer(std::chrono::seconds(4), std::bind(&FSMCommander::timer_callback, this));

    index_ = 0;
}

void FSMCommander::idel_exec() {
    return;
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
