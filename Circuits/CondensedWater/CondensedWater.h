#ifndef CONDENSEDWATER
#define CONDENSEDWATER

#include "../Circuits.h"
#include "../../Actuator/Tower/Tower.h"
#include "../../Actuator/Pumps/Pumps.h"
#include <string>

class CondensedWaterCircuit : public Circuit
{
public:
    CondensedWaterCircuit(double water_temp);
    virtual double get_temperature_transfer_coefficient();
    int get_Towers_on_time();
    void turn_on_one_tower();
    void turn_on_both_towers();
    void turn_off_both_towers();
    int get_total_energy_consuption();
    int get_total_on_time();
    int get_towers_on();
    int get_towers_cycles();
    void condense_water();
    void not_condense_water(double temperature_outdoor);
    void set_water_temperature(double temperature);

    double water_temperature;

private:
    Tower tower_1;
    Tower tower_2;
    Pump pumps[8];
};

#endif