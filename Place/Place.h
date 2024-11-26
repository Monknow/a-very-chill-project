#ifndef PLACE
#define PLACE
#include <iostream>
#include "../Circuits/Recirculating/Recirculating.h"

using namespace std;

class Place
{
public:
    Place(string instance_name, double instance_temperature_indoor, double instance_ambient_room_rate, double instance_temperature_outdoor, bool instance_busy_hours[24], AulasIRecirculatingCircuit instance_aulas_i_recirculating_circuit);
    void updateTemperature(bool state, double temperature_chilled_water, double temperature_transfer_coefficient);

private:
    int time = 0;
    string name;
    double ambient_room_rate;
    double temperature_outdoor;
    double temperature_indoor;
    bool busy_hours[24];
    AulasIRecirculatingCircuit recirculating_circuit;
};

#endif