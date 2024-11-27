#ifndef PLACE
#define PLACE
#include <iostream>
#include "../Circuits/Recirculating/Recirculating.h"

using namespace std;

class Place
{
public:
    Place(string instance_name, double instance_temperature_indoor, double instance_ambient_room_rate, double instance_temperature_outdoor, bool instance_busy_hours[24], AulasIRecirculatingCircuit instance_aulas_i_recirculating_circuit);
    void updateTemperature(bool state, double temperature_chilled_water, double new_temperature_outdoor);
    double get_indoor_temperature();
    void turn_on_fcu();
    void turn_off_fcu();
    void turn_on_pumps(int n);
    void turn_off_pumps(int n);
    AulasIRecirculatingCircuit recirculating_circuit;

private:
    int time = 0;
    string name;
    double ambient_room_rate;
    double temperature_outdoor;
    double temperature_indoor;
    bool busy_hours[24];
};

#endif