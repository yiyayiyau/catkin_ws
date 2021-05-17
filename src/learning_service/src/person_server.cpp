#include <ros/ros.h>
#include "learning_service/Person.h"

bool personCallback(learning_service::Person::Request &req,
                    learning_service::Person::Response &res)
{

    ROS_INFO("Person: name:%s, age:%d, sex:%d", req.name.c_str(), req.age, req.sex);

    res.result = "OK";

    return true;
}

/* This is Server, a request from Service is necessery(the request of Service comes from Client);
* person_server is Server; /show_person is Service; (person_client is Client); When Server get a 
* request from Service, it will call personCallback and give the ROS_INFO as response.
*/
int main(int argc, char **argv)
{

    ros::init(argc, argv, "person_server");

    ros::NodeHandle n;

    ros::ServiceServer person_service = n.advertiseService("/show_person", personCallback);

    ROS_INFO("Ready to show person information.");
    
    ros::spin();

    return 0;
}