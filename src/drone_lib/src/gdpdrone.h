#ifndef GDPdrone_H
#define GDPdrone_H

#include "commands.h"

class GDPdrone
{
public:
    int age = 19;

    commands Commands;
    GDPdrone();
    GDPdrone(int argc, char **argv);
};
#endif /* GDPdrone_H */