from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
import os


def generate_launch_description():
    rmul_decision_node = Node(
        package="rmul_decision",
        name="rmul_decision_node",
        executable="rmul_decision_node",
        namespace="",
        output="screen",
    )

    return LaunchDescription([rmul_decision_node])
