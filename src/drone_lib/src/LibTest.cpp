#include "headers/gdpdrone.h"

int main(int argc, char **argv)
{
    GDPdrone::GDPdrone drone = GDPdrone(argc, argv);
    drone.Commands.await_Connection();
}