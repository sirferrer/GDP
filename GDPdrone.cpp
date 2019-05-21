#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/Altitude.h>
#include <std_msgs/Float64.h>

class GDPdrone{
    GDPdrone(int argc, char **argv)
    {
        ros::init(argc, argv, "test_node");
        ros::NodeHandle nh;
        ros::Subscriber set_vel_pub_     = nh.advertise<mavros_msgs::PositionTarget>("mavros/setpoint_raw/local", 10);
        ros::Subscriber takeoff_client_  = nh.serviceClient<mavros_msgs::CommandTOL>("/mavros/cmd/takeoff");
        ros::Subscriber set_mode_client_ = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");
        ros::Subscriber land_client_     = nh.serviceClient<mavros_msgs::CommandTOL>("/mavros/cmd/land");
    }
    public:
        void requestLanding(){
            // Create Twist Command
            geometry_msgs::Twist angVelocity;
            angVelocity.linear.x  = 0; angVelocity.linear.y  = 0; angVelocity.linear.z  = -0.1;
            angVelocity.angular.x = 0; angVelocity.angular.y = 0; angVelocity.angular.z = 0;
        }
};
