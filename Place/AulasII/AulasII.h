#ifndef Aulas_II
#define Aulas_II
#include "../Place.h"
#include "../../Circuits/Recirculating/Recirculating.h"

class AulasII : public Place
{
public:
    AulasII(string name, double instance_temperature_indoor, double instance_temperature_outdoor);
};

#endif