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
    drone.Commands.set_Offboard();

    // Arm the motors
    drone.Commands.set_Armed();

    // Request takeoff at 1m altitude. At 25Hz = 10 seconds
    int altitude = 0.35;
    int time_takeoff = 250;
    //drone.Commands.requestTakeoff(altitude, time_takeoff);
    ROS_INFO("Taking Off");
    for (int count = 1; count < 400; count++)
    {
        drone.Commands.move_Position_Local(0, 0, 5, 180);
        ros::spinOnce();
        rate.sleep();
    }

    /*
    ROS_INFO("Velocity Command");
    for (int count = 1; count < 100; count++)
    {
        drone.Commands.move_Velocity_Local(0, 1, 1, 0);
        ros::spinOnce();
        rate.sleep();
    }

    ROS_INFO("Acceleration Command");
    for (int count = 1; count < 25; count++)
    {
        drone.Commands.move_Acceleration_Local(0.1, 0, 0.8);
        ros::spinOnce();
        rate.sleep();
    }
    /**/

    ROS_INFO("Global Position Command");
    for (int count = 1; count < 550; count++)
    {
        drone.Commands.move_Position_Global(47.39738, 8.5456, 545, 90);
        ros::spinOnce();
        rate.sleep();
    }

    // Land and disarm
    // TODO: There should be a check at the end
    drone.Commands.request_LandingAuto();

    // Exit
    return 0;
}