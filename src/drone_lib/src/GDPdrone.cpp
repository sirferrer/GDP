#include "headers/gdpdrone.h"

class GDPdrone
{
public:
    commands Commands;
    data Data;
    functions Functions;

    GDPdrone(int argc, char **argv, float rate)
    {
        Commands = commands(argc, argv, rate);
        Data = data(argc, argv, rate);
        Functions = functions();
    }
};