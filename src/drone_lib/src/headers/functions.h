#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>

class functions
{
public:
    mavros_msgs::Altitude infrared_altitude;
    std_msgs::Float64 compass_heading;
    functions();
};
#endif /* FUNCTIONS_H */