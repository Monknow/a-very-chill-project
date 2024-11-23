#include "Place.h"

Place::Place(string instance_name, double instance_temperature_indoor, double instance_temperature_outdoor, double instance_ambient_room_rate, bool instance_busy_hours[24])
{
    name = instance_name;
    temperature_indoor = instance_temperature_indoor;
    temperature_outdoor = instance_temperature_outdoor;
    temperature_delta = instance_temperature_outdoor - instance_temperature_indoor;
    ambient_room_rate = instance_ambient_room_rate;
    bool busy_hours[24];

    cout << name << " at " << time << " is " << temperature_indoor << "C" << endl;
}

void Place::updateTemperature(bool state)
{
    time++;

    if (state)
    {
    }
    else
    {
        temperature_indoor = temperature_indoor + ambient_room_rate * temperature_delta;
        temperature_delta = temperature_outdoor - temperature_indoor;
    }
    cout << name << " at " << time << " is " << temperature_indoor << "C" << endl;
}