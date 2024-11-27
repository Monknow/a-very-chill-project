#ifndef AULAS_I
#define AULAS_I
#include "../Place.h"
#include "../../Circuits/Recirculating/Recirculating.h"

class AulasI : public Place
{
public:
    AulasI(string name, double instance_temperature_indoor, double instance_temperature_outdoor);
};

#endif