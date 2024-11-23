#ifndef CLASSROOM
#define CLASSROOM
#include "../Place.h"
#include <iostream>

using namespace std;

class Classroom : public Place
{
public:
    Classroom(double instance_temperature_indoor, double instance_temperature_outdoor, bool instance_busy_hours[24]);
};

#endif