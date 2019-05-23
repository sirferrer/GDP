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
    geometry_msgs::PoseStamped make_pose(float x, float y, float z)
    {
        geometry_msgs::PoseStamped poseObj;
        poseObj.header.stamp = ros::Time::now();
        poseObj.pose.position.x = x;
        poseObj.pose.position.y = y;
        poseObj.pose.position.z = z;
        poseObj.pose.orientation.x = 0;
        poseObj.pose.orientation.y = 0;
        poseObj.pose.orientation.z = 1;
        poseObj.pose.orientation.w = 0;
        return poseObj;
    }
};
