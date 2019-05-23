#ifndef GDPdrone_H
#define GDPdrone_H

#include "data.h"
#include "commands.h"
#include "functions.h"

class GDPdrone
{
public:
    commands Commands;
    data Data;
    functions Functions;
    GDPdrone();
    GDPdrone(int argc, char **argv);
};
#endif /* GDPdrone_H */