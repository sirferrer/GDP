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
public:
    commands();
    commands(int argc, char **argv, float rate);

    void await_Connection();
    void set_Offboard();
    void set_Armed();
    void set_Disarmed();
    void requestLanding();
    void requestTakeoff(float altitude);
    void requestHover(float time);
    void move_Position(float _x, float _y, float _z);
    void move_Position(float _x, float _y, float _z, float _qx, float _qy, float _qz, float _theta);
};

#endif