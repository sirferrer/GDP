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

class commands
{
// VARIABLES
public:

    //-----   DATA STORES -----//
    // Store controller extended state
    mavros_msgs::ExtendedState extended_state;

    // Store controller state
    mavros_msgs::State current_state{};

    //-----   CLIENTS -----//
    ros::ServiceClient set_mode_client;
    ros::ServiceClient arming_client;

    //-----   PUBLISHERS -----//
    ros::Publisher position_pub;
    ros::Publisher twist_pub;

    // METHODS
    ros::NodeHandle nh;
    ros::Rate rate = ros::Rate(20.0);
    ros::Subscriber state_sub;
    ros::Subscriber state_sub_ext;

    commands(){};
    commands(float _rate);

    void await_Connection();
    void set_Offboard();
    void set_Armed();
    void set_Disarmed();
    void requestLanding();
    void requestTakeoff(float altitude);
    void requestHover(float time);
    void move_Position(float _x, float _y, float _z);
    void move_Position(float _x, float _y, float _z, float _qx, float _qy, float _qz, float _theta);
    void ext_state_cb(const mavros_msgs::ExtendedState::ConstPtr& msg);
    void state_cb(const mavros_msgs::State::ConstPtr& msg);

private:
    void set_Mode(std::string _mode);
    void set_Arm_Disarm(bool _arm);
    void set_Pose(geometry_msgs::PoseStamped _pose);
    void set_Velocity(geometry_msgs::Twist _twist);
};

#endif