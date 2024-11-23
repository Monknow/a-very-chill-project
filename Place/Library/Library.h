#ifndef LIBRARY
#define LIBRARY
#include "../Place.cpp"
#include <iostream>

using namespace std;

class Library : public Place
{
public:
    Library(double instance_temperature_indoor, double instance_temperature_outdoor, bool instance_busy_hours[24]);
};

#endif