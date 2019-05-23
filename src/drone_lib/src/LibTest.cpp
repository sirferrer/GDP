#include "headers/gdpdrone.h"

float const set_rate = 25;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "drone_node");
    ros::NodeHandle nh;
    ros::Rate rate(set_rate); // 20 Hz by default

    GDPdrone drone(nh, rate);
    drone.Commands.await_Connection();
    drone.Commands.set_Offboard();
    drone.Commands.set_Armed();
    drone.Commands.requestTakeoff(1);
    drone.Commands.move_Position(0, 0, 1);
    drone.Commands.move_Position(1, 0, 1);
    // drone.Commands.move_Velocity();
    // drone.Commands.move_Acceleration();
    drone.Commands.requestLanding();
    drone.Commands.set_Disarmed();

    return 0;
}