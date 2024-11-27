#ifndef LIBRARY
#define LIBRARY
#include "../Place.h"
#include "../../Circuits/Recirculating/Recirculating.h"

class Library : public Place
{
public:
    Library(double instance_temperature_indoor, double instance_temperature_outdoor);
};

#endif