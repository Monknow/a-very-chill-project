#ifndef LIBRARY
#define LIBRARY
#include "../Place.h"
#include "../../Circuits/Recirculating/Recirculating.h"

class Library : public Place
{
public:
    Library(double instance_temperature_indoor, double instance_temperature_outdoor, bool instance_busy_hours[24], AulasIRecirculatingCircuit instance_recirculating_circuit);
};

#endif