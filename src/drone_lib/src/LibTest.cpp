#include "headers/gdpdrone.h"
#include "headers/test.h"

float const set_rate = 25;
mavros_msgs::State current_state;

void state_cb(const mavros_msgs::State::ConstPtr &msg)
{
    current_state = *msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "drone_node");
    ros::NodeHandle nh;
    //ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_cb);

    ros::Rate rate(set_rate); // 20 Hz by default
  
    test test(int argc, char **argv);
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