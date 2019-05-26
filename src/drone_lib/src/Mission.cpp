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
    float altitude = 0.35;
    int time_takeoff = 250;
    //drone.Commands.request_Takeoff(altitude, time_takeoff);

    ROS_INFO("Local Acceleration Command");
    for (int count = 1; count < 250; count++)
    {
        drone.Commands.move_Position_Local(1, 0, 1, 45, "BODY");
        ros::spinOnce();
        rate.sleep();
    }

    ROS_INFO("Local Acceleration Command 2");
    for (int count = 1; count < 100; count++)
    {
        drone.Commands.move_Acceleration_Local(0, 0, 0.51, "LOCAL");
        ros::spinOnce();
        rate.sleep();
    }

   /*
    ROS_INFO("Global Position Command");
    for (int count = 1; count < 200; count++)
    {
        drone.Commands.move_Position_Global(47.39770, 8.5456, 545, 90, "NOT IMPLEMENTED");
        ros::spinOnce();
        rate.sleep();
    }

    ROS_INFO("Local Velocity Command");
    for (int count = 1; count < 100; count++)
    {
        drone.Commands.move_Velocity_Local(1, 1, 1, 0, "LOCAL");
        ros::spinOnce();
        rate.sleep();
    }

     ROS_INFO("Local Acceleration Command");
    for (int count = 1; count < 50; count++)
    {
        drone.Commands.move_Acceleration_Local(0, 0.1, 0.1, "LOCAL");
        ros::spinOnce();
        rate.sleep();
    }

   /*
    ROS_INFO("Global Acceleration Command");
    for (int count = 1; count < 150; count++)
    {
        drone.Commands.move_Velocity_Global(0.1, 0.3, 9.81 + 0.1, 0);
        ros::spinOnce();
        rate.sleep();
    }
    /**/

    // Land and disarm
    // TODO: There should be a check at the end
    drone.Commands.request_LandingAuto();

    // Exit
    return 0;
}