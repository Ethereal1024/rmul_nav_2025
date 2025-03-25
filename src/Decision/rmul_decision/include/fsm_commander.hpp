#pragma once

#include "rclcpp/rclcpp.hpp"
#include "pb_rm_interfaces/msg/event_data.hpp"
#include "pb_rm_interfaces/msg/robot_status.hpp"
#include "pb_rm_interfaces/msg/game_status.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "navigator_interfaces/msg/navigate.hpp"
#include <vector>

class Point {

    Point() = default;

    Point(const double& x, const double& y) : x(x), y(y) {}

    Point operator+(const Point& another) {
        return Point(x + another.x, y + another.y);
    }

    double x;
    double y;
};

class FSMCommander : public rclcpp::Node {

    enum class State {IDLE, DEPART, OCCUPY, ESCAPE, SNIPE};
    enum class Event {UNOCCUPIED, OCCUPIED_FRIEND, OCCUPIED_ENEMY, OCCUPIED_BOTH};

public:
    explicit FSMCommander(const rclcpp::NodeOptions& options);

private:
    void event_sub_callback(const pb_rm_interfaces::msg::EventData::SharedPtr msg);

    void robot_sub_callback(const pb_rm_interfaces::msg::EventData::SharedPtr msg);

    struct game_ {
        bool started;
    };

    struct self_ {
        Point position;
        int hp;
    };

    struct enemy_ {
        Point position;
    };

    std::vector<int> occupy_points_ = {
        Point(1, 2),
        Point(3, 4),
        Point(5, 6)};

    rclcpp::Publisher<navigator_interfaces::msg::Navigate>::SharedPtr nav_pub_;

    rclcpp::Subscription<pb_rm_interfaces::msg::EventData>::SharedPtr event_sub_;
    rclcpp::Subscription<pb_rm_interfaces::msg::RobotStatus>::SharedPtr robot_sub_;
    rclcpp::Subscriprion<geometry_msgs::msg::PoseStamped>::SharedPtr pose_pub_;

    rclcpp::TimerBase::SharedPtr timer_;

    State state_;
    Event event_;
};