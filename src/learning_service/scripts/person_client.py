#! /usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
from learning_service.srv import Person, PersonRequest


def person_client():

    rospy.init_node("person_client")

    rospy.wait_for_service("/show_person")

    try:

        person_client = rospy.ServiceProxy("/show_person", Person)

        response = person_client("Tomi", 20, PersonRequest.female)

        return response.result

    except rospy.ServiceException as err:
        
        print("Service call failed: %s" % err)


if __name__ == "__main__":

    print("Show person result:%s" % (person_client()))
