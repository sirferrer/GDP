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
    int altitude = 0.35;
    int time_takeoff = 250;
    drone.Commands.requestTakeoff(altitude, time_takeoff);
    
    // Land and disarm
    drone.Commands.requestLandingAuto();
    
    // Exit
    return 0;
}