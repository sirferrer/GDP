#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>

class functions
{
public:
    float pi;
    functions();
    double DegToRad(float x);
    double RadToDeg(float x);
    static geometry_msgs::PoseStamped make_pose(float _x, float _y, float _z);
    static geometry_msgs::PoseStamped make_pose(float _x, float _y, float _z, float _qx, float _qy, float _qz, float _theta);
    static geometry_msgs::Twist make_twist(float _x, float _y, float _z, float _ax, float _ay, float _az);
};

#endif /* FUNCTIONS_H */