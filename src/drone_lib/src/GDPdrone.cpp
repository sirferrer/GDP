#include "headers/gdpdrone.h"

GDPdrone::GDPdrone(float _rate)
{
    // This class is empty, it is just a container for:
    // - Commands
    // - Functions
    // - Data
    Data = data(_rate);
    Commands = commands(_rate);
}