#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <mavros_msgs/Altitude.h>
#include <std_msgs/Float64.h>
#include "commands.h"
#include "gdpdrone.h"

class GDPdrone
{
public:
    commands Commands;

    // Store altitude
    mavros_msgs::Altitude infrared_altitude;

    // Store Heading Angle
    std_msgs::Float64 compass_heading;

    GDPdrone(int argc, char **argv)
    {
        Commands = commands(argc, argv, 20);
        ros::init(argc, argv, "drone_node");
        ros::NodeHandle nh;

        ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_cb);

        // Subscribe to altitude node
        ros::Subscriber altitude_sub = nh.subscribe<mavros_msgs::Altitude>("/mavros/altitude", 10, altitude_cb);

        // Compass Data
        ros::Subscriber compass_sub = nh.subscribe<std_msgs::Float64>("/mavros/global_position/compass_hdg", 10, heading_cb);

        ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);

        ros::Publisher local_twist_pub = nh.advertise<geometry_msgs::Twist>("mavros/setpoint_velocity/cmd_vel_unstamped", 10);

        
    }

private:
    // Altitude subscriber callback function
    void altitude_cb(const mavros_msgs::Altitude::ConstPtr &msg)
    {
        infrared_altitude = *msg;
    }

    // Heading subscriber callback function
    void heading_cb(const std_msgs::Float64::ConstPtr &msg)
    {
        compass_heading = *msg;
    }

public:
    struct Commands
    {
        void await_Connection()
        {
            while (ros::ok() && !current_state.connected)
            {
                ros::spinOnce();
                rate.sleep();
            }
        }
    };

    class Functions
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

    class Commands
    {
    private:
        static void await_Connection()
        {
            while (ros::ok() && !this.current_state.connected)
            {
                ros::spinOnce();
                rate.sleep();
            }
        }

        static void set_Offboard()
        {
            ros::Time last_request = ros::Time::now();
            while (ros::ok())
            {
                if (current_state.mode != "OFFBOARD" &&
                    (ros::Time::now() - last_request > ros::Duration(0.25)))
                {
                    if (set_mode_client.call(offb_set_mode) && offb_set_mode.response.mode_sent)
                    {
                        ROS_INFO("Offboard enabled");
                    }
                    last_request = ros::Time::now();
                    ros::spinOnce();
                    rate.sleep();
                }
            }

            void set_Armed()
            {
                ros::Time last_request = ros::Time::now();
                while (ros::ok())
                {
                    if (!current_state.armed && (ros::Time::now() - last_request > ros::Duration(5.0)))
                    {
                        if (arming_client.call(arm_cmd) && arm_cmd.response.success)
                        {
                            ROS_INFO("Vehicle armed");
                        }
                        last_request = ros::Time::now();
                    }
                }
            }

            bool check_Landing

                public : void
                         requestLanding()
            {
                // Create Twist Command
                geometry_msgs::Twist angVelocity;
                angVelocity.linear.x = 0;
                angVelocity.linear.y = 0;
                angVelocity.linear.z = -0.1;
                angVelocity.angular.x = 0;
                angVelocity.angular.y = 0;
                angVelocity.angular.z = 0;
            }
        };

        class Data
        {
        }
    };