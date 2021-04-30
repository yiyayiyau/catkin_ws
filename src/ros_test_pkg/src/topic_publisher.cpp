#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv){
    ros::init(argc, argv, "topic_publisher"); // uint32_t => 4 Bytes; def a node
    ros::NodeHandle node_handle;

    // Initialize publisher object with topic name and the capacity of msgs in this topic.
    ros::Publisher pub_number = node_handle.advertise<std_msgs::Int32>("/count", 10);

    ros::Rate rate(1);
    int number_count = 0;
    while(ros::ok()){
        std_msgs::Int32 msg;
        msg.data = number_count;
        pub_number.publish(msg); // publisher this msg to topic

        ROS_INFO("%d", msg.data);

        ros::spinOnce();
        rate.sleep();
        number_count++;
    }

    return 0;

}