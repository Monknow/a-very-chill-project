#ifndef CHILLEDWATER
#define CHILLEDWATER

#include "../Circuits.h"
#include "../../Actuator/Chiller/Chiller.h"
#include "../../Actuator/Pumps/Pumps.h"
#include <string>

class ChilledWaterCircuit : public Circuit
{
public:
    ChilledWaterCircuit();
    virtual double get_temperature_transfer_coefficient(double Tcd);
    int get_Chillers_on_time();
    void turn_on_one_chiller();
    void turn_on_both_chillers();
    void turn_off_both_chillers();
    int get_total_energy_consuption();
    int get_total_on_time();
    int get_chillers_on();
    void chill_water(double dT);

    double water_temperature;

private:
    Chiller chiller_1;
    Chiller chiller_2;
    Pump pumps[8];
};

#endif