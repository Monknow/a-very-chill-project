#include "ChilledWater.h"
#include "../../Actuator/Chiller/Chiller.h"
#include "../../Actuator/Pumps/Pumps.h"

ChilledWaterCircuit::ChilledWaterCircuit() : Circuit(8, "ChillWaterPump"), water_temperature(15), chiller_1(Chiller()), chiller_2(Chiller()) {};

int ChilledWaterCircuit::get_Chillers_on_time()
{
    int chiller_1_on_time = chiller_1.get_on_time();
    int chiller_2_on_time = chiller_2.get_on_time();
    return chiller_1_on_time + chiller_2_on_time;
};

void ChilledWaterCircuit::turn_on_one_chiller()
{
    chiller_1.turn_on();
    chiller_2.turn_off();
}

void ChilledWaterCircuit::turn_on_both_chillers()
{
    chiller_1.turn_on();
    chiller_2.turn_on();
}

void ChilledWaterCircuit::turn_off_both_chillers()
{
    chiller_1.turn_off();
    chiller_2.turn_off();
}

int ChilledWaterCircuit::get_total_on_time()
{
    return get_Chillers_on_time() + get_pumps_on_time();
}

int ChilledWaterCircuit::get_total_energy_consuption()
{
    double total_chiller_1_consumption = chiller_1.get_power_consumption();
    double total_chiller_2_consumption = chiller_2.get_power_consumption();

    return total_chiller_1_consumption + total_chiller_2_consumption + get_pumps_total_energy_consumption();
}

int ChilledWaterCircuit::get_chillers_on()
{
    return chiller_1.get_state() + chiller_2.get_state();
}

int ChilledWaterCircuit::get_chillers_cycles()
{
    return chiller_1.get_cycles() + chiller_2.get_cycles();
};

double ChilledWaterCircuit::get_temperature_transfer_coefficient(double Tcd)
{
    double Kc{0};

    if (Tcd > 30)
    {
        return 0.1;
    }

    switch (get_chillers_on())
    {
    case 0:
        return 0.1;

    case 1:
        Kc = 0.6;
        break;

    case 2:
        Kc = 0.8;
        break;
    }

    double Kp{0};

    switch (get_pumps_on())
    {
    case 0:
        return 0.1;
    case 1:
        Kp = 0.5;
        break;

    case 2:
        Kp = 0.9;
        break;
    }

    return (30 - Tcd) / 12 * Kc * Kp;
};

void ChilledWaterCircuit::chill_water(double condensed_water_temperature)
{
    double dT = water_temperature - 8;
    water_temperature -= get_temperature_transfer_coefficient(condensed_water_temperature) * dT;
};

void ChilledWaterCircuit::not_chill_water(double temperature_outdoor)
{
    double dT = temperature_outdoor - water_temperature;
    water_temperature += 0.1 * dT;
}

void ChilledWaterCircuit::update_temperature(double temperature_outdoor)
{
    if (water_temperature > 15)
    {
        turn_on_pumps(2);
        turn_on_one_chiller();
        chill_water(temperature_outdoor);
        turn_off_both_chillers();
        turn_off_pumps(2);
    }
    else
    {
        not_chill_water(temperature_outdoor);
    }
}