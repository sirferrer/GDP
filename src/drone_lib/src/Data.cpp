#include "headers/data.h"

data::data(){};
data::data(ros::NodeHandle nh, ros::Rate _rate)
{
    // Subscribe to altitude node
    ros::Subscriber altitude_sub = nh.subscribe<mavros_msgs::Altitude>("/mavros/altitude", 10, &data::altitude_cb, this);

    // Compass Data
    ros::Subscriber compass_sub = nh.subscribe<std_msgs::Float64>("/mavros/global_position/compass_hdg", 10, &data::heading_cb, this);
}

// Altitude subscriber callback function
void data::altitude_cb(const mavros_msgs::Altitude::ConstPtr &msg)
{
    infrared_altitude = *msg;
}

// Heading subscriber callback function
void data::heading_cb(const std_msgs::Float64::ConstPtr &msg)
{
    compass_heading = *msg;
}