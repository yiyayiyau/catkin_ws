#include <ros/ros.h>
#include <std_msgs/Int32.h>

void num_callback(const std_msgs::Int32::ConstPtr& msg){
    ROS_INFO("Get Topic Msg: [%d]", msg->data);
}

/* Subscriber: increase of the number
*/
int main(int argc, char **argv){
    ros::init(argc, argv, "topic_subscriber");
    ros::NodeHandle node_handle;

    ros::Subscriber number_subscriber = node_handle.subscribe("/count", 10, num_callback);

    ros::spin();
    return 0;
}