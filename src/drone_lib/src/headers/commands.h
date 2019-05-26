#ifndef COMMANDS_H
#define COMMANDS_H

#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ExtendedState.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <mavros_msgs/PositionTarget.h>
#include <mavros_msgs/GlobalPositionTarget.h>

class commands
{
public:
    //-----   PUBLIC METHODS -----//
    commands();
    commands(float _rate);

    void await_Connection();
    void set_Offboard();
    void set_Armed();
    void set_Disarmed();
    void request_Landing();
    void request_LandingAuto();
    void request_Takeoff(float _altitude, float _counter);
    void request_Hover(float _time);
    void move_Position_Local(float _x, float _y, float _z, float _yaw_angle_deg);
    void move_Velocity_Local(float _x, float _y, float _z, float _yaw_rate_deg_s);
    void move_Acceleration_Local(float _x, float _y, float _z);
    void move_Position_Global(float _latitude, float _longitude, float _altitude, float _yaw_angle_deg);
    void move_Velocity_Global(float _x, float _y, float _z, float _yaw_angle_deg_s);
    void move_Acceleration_Global(float _x, float _y, float _z, float _yaw_angle_deg_s);

private:
    //-----   PRIVATE PROPERTIES -----//
    ros::NodeHandle nh;
    ros::Rate rate = ros::Rate(25.0);

    //-----   PRIVATE DATA STORES -----//
    mavros_msgs::ExtendedState extended_state;
    mavros_msgs::State current_state;

    //-----   PRIVATE CLIENTS -----//
    ros::ServiceClient set_mode_client;
    ros::ServiceClient arming_client;

    //-----   PRIVATE PUBLISHERS -----//
    ros::Publisher position_pub;
    ros::Publisher velocity_pub;
    ros::Publisher acceleration_pub;
    ros::Publisher target_pub_local;
    ros::Publisher target_pub_global;

    //-----   PRIVATE SUBSCRIBERS -----//
    ros::Subscriber state_sub;
    ros::Subscriber state_sub_ext;

    //-----   PRIVATE METHODS -----//
    void set_Mode(std::string _mode);
    void set_Arm_Disarm(bool _arm);
    void ext_state_cb(const mavros_msgs::ExtendedState::ConstPtr &msg);
    void state_cb(const mavros_msgs::State::ConstPtr &msg);
};

#endif