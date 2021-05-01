#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
from turtlesim.msg import Pose


def poseCallback(msg):
    rospy.loginfo(
        "Turtle pose: linear_velocity:%0.6f, angular_velocity:%0.6f",
        msg.linear_velocity,
        msg.angular_velocity,
    )
    # ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->angular_velocity, msg->linear_velocity);


def pose_subscriber():
    rospy.init_node("pose_subscriber", anonymous=True)
    rospy.Subscriber("/turtle1/pose", Pose, poseCallback)
    rospy.spin()


if __name__ == "__main__":
    pose_subscriber()
