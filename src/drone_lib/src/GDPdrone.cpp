#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Twist.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/Altitude.h>
#include <std_msgs/Float64.h>
#include <mavros_msgs/ExtendedState.h>

class GDPdrone{
    bool _landed;

    // Store controller state
    mavros_msgs::State current_state;

    // Store controller extended state
    mavros_msgs::ExtendedState current_ext_state;

    // Store altitude
    mavros_msgs::Altitude infrared_altitude;

    // Store Heading Angle
    std_msgs::Float64 compass_heading;

    GDPdrone(int argc, char **argv)
    {
        ros::init(argc, argv, "test_node");
        ros::NodeHandle nh;
        ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_cb);

        // Subscribe to altitude node
        ros::Subscriber altitude_sub = nh.subscribe<mavros_msgs::Altitude>("/mavros/altitude", 10, altitude_cb);

        //Extended State
        ros::Subscriber state_sub_ext = nh.subscribe<mavros_msgs::ExtendedState>("mavros_msgs/extended_state", 10, current_ext_state);

        // Compass Data
        ros::Subscriber compass_sub = nh.subscribe<std_msgs::Float64>("/mavros/global_position/compass_hdg", 10, heading_cb);

        ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);

        ros::Publisher local_twist_pub = nh.advertise<geometry_msgs::Twist>("mavros/setpoint_velocity/cmd_vel_unstamped", 10);

        ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");

        ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");
    }
    private:
        // State subscriber callback function
        void ext_state_cb(const mavros_msgs::ExtendedState::ConstPtr& msg){
            current_ext_state = *msg;
            _landed = current_ext_state.landed_state;
            if (_landed){ROS_INFO("Landed!");}
        }

        // Altitude subscriber callback function
        void altitude_cb(const mavros_msgs::Altitude::ConstPtr& msg){
            infrared_altitude = *msg;
        }

        // Heading subscriber callback function
        void heading_cb(const std_msgs::Float64::ConstPtr& msg){
            compass_heading = *msg;
        }

        // State subscriber callback function
        void state_cb(const mavros_msgs::State::ConstPtr& msg){
        current_state = *msg;
        }

    public:
        class Functions
        {
            private:
                const float pi = 3.1415926535;
            public:
                double DegToRad(float x){float ans = x/180 * pi; return ans;}
                double RadToDeg(float x){float ans = x*180 / pi; return ans;}
                
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
                    poseObj.pose.orientation.w = compass_heading.data * pi / 180;
                    return poseObj;
                }
        };

        class Commands
        { 
            public:
                void requestLanding(){
                // Create Twist Command
                geometry_msgs::Twist angVelocity;
                angVelocity.linear.x  = 0; angVelocity.linear.y  = 0; angVelocity.linear.z  = -0.1;
                angVelocity.angular.x = 0; angVelocity.angular.y = 0; angVelocity.angular.z = 0;}
        };

        void requestNewPose()
        {

        }
};