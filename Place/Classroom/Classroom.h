#ifndef CLASSROOM
#define CLASSROOM
#include "../Place.h"
#include "../../Circuits/Recirculating/Recirculating.h"

class Classroom : public Place
{
public:
    Classroom(string name, double instance_temperature_indoor, double instance_temperature_outdoor, bool instance_busy_hours[24], AulasIRecirculatingCircuit instance_recirculating_circuit);
};

#endif