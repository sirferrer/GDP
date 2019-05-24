#ifndef DATA_H
#define DATA_H

#include <ros/ros.h>
#include <mavros_msgs/Altitude.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/PoseStamped.h>


class data
{
public:
    // Data
    mavros_msgs::Altitude infrared_altitude;
    std_msgs::Float64 compass_heading;
    sensor_msgs::NavSatFix gps_raw;
    sensor_msgs::Imu imu;
    geometry_msgs::PoseStamped local_pose;
    geometry_msgs::TwistStamped local_velocity;

    // Constructors
    data(){};
    data(float _rate);

private:
    // Hidden methods
    ros::NodeHandle nh;
    ros::Rate rate = ros::Rate(25.0);

    ros::Subscriber compass_sub;
    ros::Subscriber altitude_sub;
    ros::Subscriber gps_sub;
    ros::Subscriber imu_sub;
    ros::Subscriber pose_sub;
    ros::Subscriber velocity_sub;

    void altitude_cb(const mavros_msgs::Altitude::ConstPtr& msg);
    void heading_cb(const std_msgs::Float64::ConstPtr& msg); 
    void gps_cb(const sensor_msgs::NavSatFix::ConstPtr& msg);
    void imu_cb(const sensor_msgs::Imu::ConstPtr& msg);
    void pose_cb(const geometry_msgs::PoseStamped::ConstPtr &msg);
    void velocity_cb(const geometry_msgs::TwistStamped::ConstPtr &msg);
};

#endif /* DATA_H */