#include "headers/gdpdrone.h"

class GDPdrone
{
public:
    commands Commands;
    data Data;
    functions Functions;

    GDPdrone(int argc, char **argv)
    {
        Commands = commands(argc, argv, 20);
        Data = data(argc, argv, 20);
        Functions = functions();
    }
};