#ifndef CHILLER
#define CHILLER

#include "../Actuator.h"
#include "../Pumps/Pumps.h"

class Chiller : public Actuator
{
private:
    Pump pumps[8];

public:
    Chiller(Pump a_pumps[8]);
};

#endif