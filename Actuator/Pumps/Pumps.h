#ifndef PUMP
#define PUMP

#include "../Actuator.h"

class Pump : public Actuator 
{
public:
    Pump();
    Pump(double a_power_consuption);
};

class ChillWaterPump : public Pump
{
public:
    ChillWaterPump();
};

class CondensedWaterPump : public Pump
{
public:
    CondensedWaterPump();
};

class RecirculatingPump : public Pump
{
public:
    RecirculatingPump();
};
#endif