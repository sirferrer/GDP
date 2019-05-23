#include "commands.h"
#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/ExtendedState.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>

class commands
{
    // Refresh rate in Hz, 20 by default
    ros::Rate rate = ros::Rate(20);

    //-----   DATA STORES -----//
    // Store controller extended state
    mavros_msgs::ExtendedState extended_state;

    // Store controller state
    mavros_msgs::State current_state;

    //-----   CLIENTS -----//
    ros::ServiceClient set_mode_client;
    ros::ServiceClient arming_client;

    //-----   CALLBACKS -----//
    // State subscriber callback function
    void ext_state_cb(const mavros_msgs::ExtendedState::ConstPtr &msg)
    {
        extended_state = *msg;
    }

    // State subscriber callback function
    void state_cb(const mavros_msgs::State::ConstPtr &msg)
    {
        current_state = *msg;
    }

    //-----   METHODS -----//
    // Default constructor
    commands() {}

    // Overloaded constructor
    commands(int argc, char **argv, float _rate)
    {
        ros::init(argc, argv, "drone_node");
        ros::NodeHandle nh;

        // Subscribers
        ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_cb);
        ros::Subscriber state_sub_ext = nh.subscribe<mavros_msgs::ExtendedState>("mavros_msgs/extended_state", 10, ext_state_cb);

        // Service clients
        arming_client = nh.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
        set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");
        rate = ros::Rate(_rate);
    }

public:
    void await_Connection()
    {
        while (ros::ok() && !current_state.connected){ros::spinOnce();rate.sleep();}
    }

    void set_Offboard()
    {
        set_Mode("OFFBOARD");
    }

    void set_Armed()
    {
        set_Arm_Disarm(true);
    }

    void set_Disarmed()
    {
        set_Arm_Disarm(false);
    }

    void requestLanding(float velocity)
    {
        //TODO
    }
    void requestTakeoff(float altitude){
        //TODO
    }
    void requestHover(float time){
        //TODO
    }

private:
    void set_Mode(std::string _mode)
    {
        mavros_msgs::SetMode mode;
        mode.request.custom_mode = _mode;

        ros::Time last_request = ros::Time::now();
        while (ros::ok())
        {
            if (current_state.mode != _mode &&
                (ros::Time::now() - last_request > ros::Duration(0.25)))
            {
                if (set_mode_client.call(mode) && mode.response.mode_sent)
                {
                    ROS_INFO("%s enabled", _mode);
                }
                last_request = ros::Time::now();
                ros::spinOnce();
                rate.sleep();
            }
        }
    }

    void set_Arm_Disarm(bool _arm)
    {
        mavros_msgs::CommandBool arm_command;
        arm_command.request.value = _arm;
        ros::Time last_request = ros::Time::now();
        while (ros::ok())
        {
            if (!current_state.armed && (ros::Time::now() - last_request > ros::Duration(5.0)))
            {
                if (arming_client.call(arm_command) && arm_command.response.success && _arm)
                {
                    ROS_INFO("Vehicle Armed");
                }
                else if (arming_client.call(arm_command) && arm_command.response.success && !_arm)
                {
                    ROS_INFO("Vehicle Disarmed");
                }
                last_request = ros::Time::now();
            }
        }
    }
};