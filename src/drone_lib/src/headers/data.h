#ifndef DATA_H
#define DATA_H

#include <ros/ros.h>
#include <mavros_msgs/Altitude.h>
#include <std_msgs/Float64.h>

class data
{
public:
    ros::NodeHandle nh;
    ros::Rate rate = ros::Rate(25.0);
    mavros_msgs::Altitude infrared_altitude;
    std_msgs::Float64 compass_heading;

    ros::Subscriber compass_sub;
    ros::Subscriber altitude_sub;

    data(){};
    data(float _rate);

    void altitude_cb(const mavros_msgs::Altitude::ConstPtr &msg);
    void heading_cb(const std_msgs::Float64::ConstPtr &msg);
};

#endif /* DATA_H */