#include "headers/test.h"
#include <mavros_msgs/State.h>

mavros_msgs::State current_state_2;
void state_cb_2(const mavros_msgs::State::ConstPtr &msg)
{
    current_state_2 = *msg;
}

test::test(int argc, char **argv)
{
    //ros::init(argc, argv, "drone_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_cb_2);

    ros::Rate rate(20.0);
    while (ros::ok() && !current_state_2.connected)
    {
        ros::spinOnce();
        rate.sleep();
    }

    ROS_INFO("pene");
}