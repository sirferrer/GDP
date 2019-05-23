#include "headers/gdpdrone.h"

GDPdrone::GDPdrone(ros::NodeHandle nh, ros::Rate _rate)
{
    Commands = commands(nh, _rate);
    Data = data(nh, _rate);
    Functions = functions();
}