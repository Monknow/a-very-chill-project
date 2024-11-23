#ifndef PLACE
#define PLACE
#include <iostream>

using namespace std;

class Place
{
public:
    Place(string instance_name, double instance_temperature_indoor, double instance_ambient_room_rate, double instance_temperature_outdoor, bool instance_busy_hours[24]);
    void updateTemperature(bool state);

private:
    int time = 0;
    string name;
    double ambient_room_rate;
    double temperature_outdoor;
    double temperature_indoor;
    double temperature_delta;
    bool busy_hours[24];
};

#endif