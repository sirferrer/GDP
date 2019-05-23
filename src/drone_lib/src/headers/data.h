#ifndef DATA_H
#define DATA_H

#include <ros/ros.h>
#include <mavros_msgs/Altitude.h>
#include <std_msgs/Float64.h>

class data
{
public:
    mavros_msgs::Altitude infrared_altitude;
    std_msgs::Float64 compass_heading;
    data();
    data(int argc, char **argv, float _rate);
};

#endif /* DATA_H */