#pragma once

#include "rclcpp/rclcpp.hpp"
#include "pb_rm_interfaces/msg/event_data.hpp"
#include "pb_rm_interfaces/msg/robot_status.hpp"
#include "pb_rm_interfaces/msg/game_status.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "navigator_interfaces/msg/navigate.hpp"
#include <vector>

class Point {
public:
    Point() = default;

    Point(const double& x, const double& y) : x(x), y(y) {}

    Point operator+(const Point& another) {
        return Point(x + another.x, y + another.y);
    }

    Point operator*(const double& k) {
        return Point(k * x, k * y);
    }

    double x;
    double y;
};

class FSMCommander : public rclcpp::Node {

    enum class State {IDLE, OCCUPY, ESCAPE, SNIPE};
    enum class Event {UNOCCUPIED, OCCUPIED_FRIEND, OCCUPIED_ENEMY, OCCUPIED_BOTH};

public:
    explicit FSMCommander(const rclcpp::NodeOptions& options);

private:
    void event_data_callback(const pb_rm_interfaces::msg::EventData::SharedPtr msg);

    void robot_status_callback(const pb_rm_interfaces::msg::RobotStatus::SharedPtr msg);

    void pose_callback(const geometry_msgs::msg::PoseStamped::SharedPtr msg);

    void idel_exec();

    void occupy_exec();

    void escape_exec();

    void snipe_exec();

    void nav_to_point(const double& x, const double& y);

    void nav_to_point(const Point& point);

    void timer_callback();

    struct Game {
        bool started;
        Event event;
    } game_;

    struct Self {
        Point position;
        int hp;
    } self_;

    // struct Enemy {
    //     bool tracking;
    //     Point position;
    // } enemy_;

    std::vector<const Point> OCCUPY_POINTS = { Point(1, 2), Point(3, 4), Point(5, 6)};
    std::vector<const Point> SNIPE_POINTS = {Point(9, 10), Point(11, 12), Point(13, 14)};
    const Point HOME = Point(7, 8);

    rclcpp::Subscription<pb_rm_interfaces::msg::EventData>::SharedPtr event_data_sub_;
    rclcpp::Subscription<pb_rm_interfaces::msg::RobotStatus>::SharedPtr robot_status_sub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr pose_sub_;

    rclcpp::Publisher<navigator_interfaces::msg::Navigate>::SharedPtr nav_pub_;

    rclcpp::TimerBase::SharedPtr timer_;

    State state_;

    int index_;
};