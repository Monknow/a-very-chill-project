#ifndef CLASSROOM
#define CLASSROOM
#include "../Place.h"

class Classroom : public Place
{
public:
    Classroom(string name, double instance_temperature_indoor, double instance_temperature_outdoor, bool instance_busy_hours[24]);
};

#endif