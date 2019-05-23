#include "headers/gdpdrone.h"

int main(int argc, char **argv)
{
    // Initialise node
    ros::init(argc, argv, "drone_node");

    // Create drone object, this sets everything up
    GDPdrone drone;

    // Set the rate. DEFAULT working frequency is 25 Hz
    ros::Rate rate = ros::Rate(25.0);

    // Initialise connection and set offboard mode
    drone.Commands.await_Connection();
    drone.Commands.start_dataStream();
    drone.Commands.set_Offboard();

    // Arm the motors
    drone.Commands.set_Armed();

    // Request takeoff at 1m altitude. At 25Hz = 10 seconds
    int altitude = 1;
    int time_takeoff = 250;
    drone.Commands.requestTakeoff(altitude, time_takeoff);

    // Move about
    ROS_INFO("GDPdrone: Moving to First Position");
    for (int time_at_position = 125; time_at_position > 0; time_at_position--)
    {
        drone.Commands.move_Position(-1, 0, 1);
        rate.sleep();
    }

    ROS_INFO("GDPdrone: Moving to Second Position");
    for (int time_at_position = 125; time_at_position > 0; time_at_position--)
    {
        drone.Commands.move_Position(1, 0, 1);
        rate.sleep();
    }

    // Land and disarm
    drone.Commands.requestLandingAuto();
    drone.Commands.set_Disarmed();

    // Exit
    return 0;
}