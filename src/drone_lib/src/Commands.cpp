#include "headers/commands.h"
#include "headers/functions.h"
#include "headers/data.h"

//-----   METHODS -----//
// Default constructor
commands::commands(float _rate)
{
    rate = ros::Rate(_rate);

    // Subscribers
    state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, boost::bind(&commands::state_cb, this, _1));
    state_sub_ext = nh.subscribe<mavros_msgs::ExtendedState>("mavros/extended_state", 10, &commands::ext_state_cb, this);

    // Publishers
    position_pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);
    velocity_pub = nh.advertise<geometry_msgs::Twist>("mavros/setpoint_velocity/cmd_vel_unstamped", 10);
    acceleration_pub = nh.advertise<geometry_msgs::Vector3Stamped>("setpoint_accel/accel", 10);

    // Service clients
    arming_client = nh.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
    set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");
}

// Wait for connection from the drone
void commands::await_Connection()
{
    while (ros::ok() && !current_state.connected)
    {
        ros::spinOnce();
        rate.sleep();
    }

    ROS_INFO("GDPdrone: Connected");
}

void commands::start_dataStream()
{
    for (int i = 300; ros::ok() && i > 0; --i)
    {
        position_pub.publish(functions::make_pose(0, 0, 0));
        ros::spinOnce();
        rate.sleep();
    }
}

void commands::set_Offboard()
{
    set_Mode("OFFBOARD");
}

void commands::set_Armed()
{
    set_Arm_Disarm(true);
}

void commands::set_Disarmed()
{
    set_Arm_Disarm(false);
}

void commands::requestLandingAuto()
{
    ROS_INFO("GDPdrone: Autonomous Landing Requested");
    set_Mode("AUTO.LAND");
}

void commands::requestLanding()
{
    // This will trigger the landed failsafe and switch off the motors
    ROS_INFO("GDPdrone: Landing Requested");
    geometry_msgs::Twist velocity;
    velocity = functions::make_twist(0, 0, -0.3, 0, 0, 0);

    // TODO: extended state does not work
    while ((ros::ok() && extended_state.landed_state != 1))
    {
        set_Velocity(velocity);
    }
}

void commands::requestTakeoff(float altitude, float counter)
{

    ROS_INFO("GDPdrone: Takeoff Requested");
    for (int i = counter; i > 0; i--)
    {
        geometry_msgs::PoseStamped pose = functions::make_pose(0, 0, altitude);
        set_Pose(pose);
    }
    ROS_INFO("GDPdrone: GDPTakeoff Completed");
}

void commands::requestHover(float time)
{
    // TODO
}

//-----   MOVEMENT COMMANDS -----//
// Overload 1 - Move position with no orientation
void commands::move_Position(float _x, float _y, float _z)
{
    geometry_msgs::PoseStamped pose = functions::make_pose(_x, _y, _z);
    set_Pose(pose);
}

// Overload 2- Move position with orientation quaternion
void commands::move_Position(float _x, float _y, float _z, float _qx, float _qy, float _qz, float _theta)
{
    geometry_msgs::PoseStamped pose = functions::make_pose(_x, _y, _z, _qx, _qy, _qz, _theta);
    set_Pose(pose);
}

void commands::set_Mode(std::string _mode)
{
    mavros_msgs::SetMode mode;
    mode.request.custom_mode = _mode;

    ros::Time last_request = ros::Time::now();
    while (ros::ok() && current_state.mode != _mode)
    {
        if (ros::Time::now() - last_request > ros::Duration(0.25))
        {
            set_mode_client.call(mode);
            last_request = ros::Time::now();
            ros::spinOnce();
            rate.sleep();
        }
    }
    if (current_state.mode == _mode)
    {
        ROS_INFO("GDPdrone: %s mode enabled", _mode.c_str());
    }
}

void commands::set_Arm_Disarm(bool _arm)
{
    mavros_msgs::CommandBool arm_command;
    arm_command.request.value = _arm;
    ros::Time last_request = ros::Time::now();
    while (ros::ok())
    {
        if (!current_state.armed && (ros::Time::now() - last_request > ros::Duration(0.25)))
        {
            if (arming_client.call(arm_command) && arm_command.response.success && _arm)
            {
                ROS_INFO("Vehicle Armed");
                break;
            }
            else if (arming_client.call(arm_command) && arm_command.response.success && !_arm)
            {
                ROS_INFO("Vehicle Disarmed");
                break;
            }
            last_request = ros::Time::now();
        }
    }
}

void commands::set_Pose(geometry_msgs::PoseStamped _pose)
{
    position_pub.publish(_pose);
    ros::spinOnce();
    rate.sleep();
}

void commands::set_Velocity(geometry_msgs::Twist _twist)
{
    velocity_pub.publish(_twist);
    ros::spinOnce();
    rate.sleep();
}

//-----   CALLBACKS -----//
// State subscriber callback function
void commands::ext_state_cb(const mavros_msgs::ExtendedState::ConstPtr &msg)
{
    extended_state = *msg;
}

// State subscriber callback function
void commands::state_cb(const mavros_msgs::State::ConstPtr &msg)
{
    current_state = *msg;
}