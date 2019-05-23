#include "headers/gdpdrone.h"

GDPdrone::GDPdrone(){};
GDPdrone::GDPdrone(int argc, char **argv, float rate)
{
    Commands = commands(argc, argv, rate);
    Data = data(argc, argv, rate);
    Functions = functions();
}