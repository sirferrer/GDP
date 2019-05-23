#include "headers/functions.h"

class functions
{
private:
    const float pi = 3.1415926535;

public:
    double DegToRad(float x)
    {
        float ans = x / 180 * pi;
        return ans;
    }
    double RadToDeg(float x)
    {
        float ans = x * 180 / pi;
        return ans;
    }

    // Simplify pose creation
    // Overload 1 - No orientation
    static geometry_msgs::PoseStamped make_pose(float _x, float _y, float _z)
    {
        geometry_msgs::PoseStamped poseObj;
        poseObj.header.stamp = ros::Time::now();
        poseObj.pose.position.x = _x;
        poseObj.pose.position.y = _y;
        poseObj.pose.position.z = _z;
        poseObj.pose.orientation.x = 0;
        poseObj.pose.orientation.y = 0;
        poseObj.pose.orientation.z = 0;
        poseObj.pose.orientation.w = 0;
        return poseObj;
    }

    // Overload 2 - Euler Quaternion
    static geometry_msgs::PoseStamped make_pose(float _x, float _y, float _z, float _qx, float _qy, float _qz, float _theta)
    {
        geometry_msgs::PoseStamped poseObj = make_pose(_x, _y, _z);
        poseObj.pose.orientation.x = _qx;
        poseObj.pose.orientation.y = _qy;
        poseObj.pose.orientation.z = _qz;
        poseObj.pose.orientation.w = _theta;
        return poseObj;
    }

    // Set velocity message
    static geometry_msgs::Twist make_twist(float _x, float _y, float _z, float _ax, float _ay, float _az)
    {
        geometry_msgs::Twist velocityObj;
        velocityObj.linear.x  = _x; 
        velocityObj.linear.y  = _y; 
        velocityObj.linear.z  = _z;
        velocityObj.angular.x = _ax; 
        velocityObj.angular.y = _ay; 
        velocityObj.angular.z = _az;
    }
};
