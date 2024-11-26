#include "Place.h"
#include "../Circuits/Recirculating/Recirculating.h"

Place::Place(string instance_name, double instance_temperature_indoor, double instance_temperature_outdoor, double instance_ambient_room_rate, bool instance_busy_hours[24], AulasIRecirculatingCircuit instance_recirculating_circuit)
{
    name = instance_name;
    temperature_indoor = instance_temperature_indoor;
    temperature_outdoor = instance_temperature_outdoor;
    ambient_room_rate = instance_ambient_room_rate;
    bool busy_hours[24];
    recirculating_circuit = instance_recirculating_circuit;

    cout << name << " at " << time << " is " << temperature_indoor << "C" << endl;
}

void Place::updateTemperature(bool state, double temperature_chilled_water, double temperature_transfer_coefficient)
{
    time++;

    if (state)
    {
        double temperature_delta = temperature_indoor - temperature_chilled_water;
        temperature_indoor = temperature_indoor - temperature_transfer_coefficient * temperature_delta;
    }
    else
    {
        double temperature_delta = temperature_outdoor - temperature_indoor;
        temperature_indoor = temperature_indoor + ambient_room_rate * temperature_delta;
    }
    cout << name << " at " << time << " is " << temperature_indoor << "C" << endl;
}