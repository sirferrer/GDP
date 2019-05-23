#include "headers/data.h"

class data
{
public:
    // Store altitude
    mavros_msgs::Altitude infrared_altitude;

    // Store Heading Angle
    std_msgs::Float64 compass_heading;

    data();
    data(int argc, char **argv, float _rate)
    {
        ros::init(argc, argv, "drone_node");
        ros::NodeHandle nh;

        // Subscribe to altitude node
        ros::Subscriber altitude_sub = nh.subscribe<mavros_msgs::Altitude>("/mavros/altitude", 10, altitude_cb);

        // Compass Data
        ros::Subscriber compass_sub = nh.subscribe<std_msgs::Float64>("/mavros/global_position/compass_hdg", 10, heading_cb);
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
};