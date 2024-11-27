#include "CondensedWater.h"
#include "../../Actuator/Tower/Tower.h"
#include "../../Actuator/Pumps/Pumps.h"

CondensedWaterCircuit::CondensedWaterCircuit(double water_temp) : Circuit(8, "CondensedWaterPump"), water_temperature(water_temp), tower_1(Tower()), tower_2(Tower()) {};

int CondensedWaterCircuit::get_Towers_on_time()
{
    int tower_1_on_time = tower_1.get_on_time();
    int tower_2_on_time = tower_2.get_on_time();
    return tower_1_on_time + tower_2_on_time;
};

void CondensedWaterCircuit::turn_on_one_tower()
{
    tower_1.turn_on();
    tower_2.turn_off();
}

void CondensedWaterCircuit::turn_on_both_towers()
{
    tower_1.turn_on();
    tower_2.turn_on();
}

void CondensedWaterCircuit::turn_off_both_towers()
{
    tower_1.turn_off();
    tower_2.turn_off();
}

int CondensedWaterCircuit::get_total_on_time()
{
    return get_Towers_on_time() + get_pumps_on_time();
}

int CondensedWaterCircuit::get_total_energy_consuption()
{
    double total_tower_1_consumption = tower_1.get_power_consumed();
    double total_tower_2_consumption = tower_2.get_power_consumed();

    return total_tower_1_consumption + total_tower_2_consumption + get_pumps_total_energy_consumption();
}

int CondensedWaterCircuit::get_towers_on()
{
    return tower_1.get_state() + tower_2.get_state();
}
int CondensedWaterCircuit::get_towers_cycles()
{
    return tower_1.get_cycles() + tower_2.get_cycles();
};

double CondensedWaterCircuit::get_temperature_transfer_coefficient()
{
    double Kt{0};
    switch (get_towers_on())
    {
    case 0:
        return 0.1;

    case 1:
        Kt = 0.7;
        break;

    case 2:
        Kt = 1;
        break;
    }

    double Kp{0};

    switch (get_pumps_on())
    {
    case 0:
        return 0.1;
    case 1:
        Kp = 0.4;
        break;

    case 2:
        Kp = 0.7;
        break;
    }

    return Kt * Kp;
};

void CondensedWaterCircuit::condense_water()
{
    cout << "WATER CONDENSED..." << endl;
    double dT = water_temperature - 18;
    water_temperature -= get_temperature_transfer_coefficient() * dT;
    iterate();
};

void CondensedWaterCircuit::not_condense_water(double temperature_outdoor)
{
    double dT = temperature_outdoor - water_temperature;
    water_temperature += dT * 0.4;
};

void CondensedWaterCircuit::set_water_temperature(double temperature) { water_temperature = temperature; }

void CondensedWaterCircuit::update_temperature(double temperature_outdoor)
{
    if (water_temperature > 20)
    {
        turn_on_pumps(2);

        turn_on_both_towers();

        condense_water();
        turn_off_both_towers();
        turn_off_pumps(2);
    }
    else
    {
        not_condense_water(temperature_outdoor);
    }

    cout << "Condensed Water  has used    " << get_total_energy_consuption() << " Kw " << endl;
}

void CondensedWaterCircuit::display_status()
{
    cout << endl << "############ CONDENSED WATER CIRCUIT ############" << endl;
    cout << "   WATER TEMPERATURE:      " << water_temperature << endl;
    cout << "_____________ TOWERS STATUS _____________\n\n";
    cout << "   # TOWER I " << " Status " <<  (tower_1.get_state() ? "ON":"OFF") << " Cycles: " << tower_1.get_cycles() << endl;
    cout << "   # TOWER II " << " Status " <<  (tower_2.get_state() ? "ON":"OFF") << " Cycles: " << tower_2.get_cycles() << endl << endl;
    display_pumps_status();
}

void CondensedWaterCircuit::iterate()
{
    iterate_pumps();
    tower_1.iterate();
    tower_2.iterate();
}