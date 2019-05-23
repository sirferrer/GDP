#include "headers/gdpdrone.h"

int main(int argc, char **argv)
{
    float const set_rate = 25;
    ros::init(argc, argv, "drone_node");
    
    GDPdrone drone = GDPdrone(set_rate);
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