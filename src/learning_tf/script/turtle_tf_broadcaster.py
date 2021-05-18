#! /usr/bin/env python3

from genpy.message import RosMsgUnicodeErrors
import roslib
roslib.load_manifest("learning_tf")
import rospy

import tf
import turtlesim.msg


def handle_turtle_pose(msg, turtlename):
    
    br = tf.TransformBroadcaster()

    br.sendTransform(
        (msg.x, msg.y, 0),
        tf.transformations.quaternion_from_euler(0, 0, msg.theta),
        rospy.Time.now(),
        turtlename,
        "world",
    )


if __name__ == "__main__":

    rospy.init_node('turtle_tf_broadcaster', anonymous=True)

    turtlename = rospy.get_param('~turtle')

    rospy.Subscriber(
        "/%s/pose" % turtlename, turtlesim.msg.Pose, handle_turtle_pose, turtlename
    )

    rospy.spin()

# catkin_make
# source devel/setup.bash
# roscore
# rosrun turtlesim turtlusim_node

# rosrun learning_tf turtle_tf_broadcaster.py __name:=turtle1_tf_broadcaster _turtle:=turtle1
# rosrun learning_tf turtle_tf_broadcaster.py __name:=turtle2_tf_broadcaster _turtle:=turtle2
# rosrun learning_tf turtle_tf_listener.py
# rosrun turtlesim turtle_teleop_key