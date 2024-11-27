#include "Place.h"
#include "../Circuits/Recirculating/Recirculating.h"

Place::Place() = default;

Place::Place(string instance_name, double instance_temperature_indoor, double instance_temperature_outdoor, double instance_ambient_room_rate, bool instance_busy_hours[24], RecirculatingCircuit instance_recirculating_circuit)
{
    name = instance_name;
    temperature_indoor = instance_temperature_indoor;
    temperature_outdoor = instance_temperature_outdoor;
    ambient_room_rate = instance_ambient_room_rate;
    bool busy_hours[24];
    recirculating_circuit = instance_recirculating_circuit;
}

void Place::update_temperature(double temperature_chilled_water, double new_temperature_outdoor, int hour)
{
    temperature_outdoor = new_temperature_outdoor;
    time++;

    if (busy_hours[hour] && temperature_indoor > 20)
    {
        recirculating_circuit.turn_on_both_FCUs();
        turn_on_pumps(1);

        double temperature_transfer_coefficient = recirculating_circuit.get_temperature_transfer_coefficient();
        double temperature_delta = temperature_indoor - temperature_chilled_water;
        temperature_indoor = temperature_indoor - temperature_transfer_coefficient * temperature_delta;

        recirculating_circuit.turn_off_both_FCUs();
        turn_off_pumps(1);
    }
    else
    {
        double temperature_delta = temperature_outdoor - temperature_indoor;
        temperature_indoor = temperature_indoor + ambient_room_rate * temperature_delta;
    }
}

double Place::get_indoor_temperature()
{
    return temperature_indoor;
}

void Place::turn_on_fcu()
{
    recirculating_circuit.turn_on_fcu();
}

void Place::turn_off_fcu()
{
    recirculating_circuit.turn_off_fcu();
}

void Place::turn_on_pumps(int n)
{
    recirculating_circuit.turn_on_pumps(n);
}

void Place::turn_off_pumps(int n)
{
    recirculating_circuit.turn_off_pumps(n);
}

string Place::get_name()
{
    return name;
}

bool Place::is_busy(int hour)
{
    return busy_hours[hour];
}
