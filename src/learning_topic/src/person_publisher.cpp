#include <ros/ros.h>
#include "learning_topic/Person.h"

/* 
*/

int main(int argc, char **argv)
{
    //init
    ros::init(argc, argv, "Person_publisher");
    ros::NodeHandle n;

    ros::Publisher person_info_pub = n.advertise<learning_topic::Person>("/person_info", 10);

    ros::Rate loop_rate(1);

    int count = 0;
    while (ros::ok())
    {
        learning_topic::Person person_msg;
        person_msg.name = "Tom";
        person_msg.age = 10;
        person_msg.sex = learning_topic::Person::male;

        person_info_pub.publish(person_msg);
        ROS_INFO("Publish Person Info: name: %s age: %d sex: %d",
                 person_msg.name.c_str(), person_msg.age, person_msg.sex);

        loop_rate.sleep();
    }
}