#ifndef CONDENSEDWATER
#define CONDENSEDWATER

#include "../Circuits.h"
#include "../../Actuator/Tower/Tower.h"
#include "../../Actuator/Pumps/Pumps.h"
#include <string>

class CondensedWaterCircuit : public Circuit
{
public:
    CondensedWaterCircuit();
    virtual double get_temperature_transfer_coefficient(double Tcd);
    int get_Towers_on_time();
    void turn_on_one_tower();
    void turn_on_both_towers();
    void turn_off_both_towers();
    int get_total_energy_consuption();
    int get_total_on_time();
    int get_towers_on();
    void condense_water(double dT);

    double water_temperature;

private:
    Tower tower_1;
    Tower tower_2;
    Pump pumps[8];
};

#endif