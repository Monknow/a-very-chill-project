#include "./Place/Classroom/Classroom.h"
#include "./Circuits/ChilledWater/ChilledWater.h"
#include "./Circuits/CondensedWater/CondensedWater.h"
#include <iostream>

using namespace std;

double day_temperature[24] = {
    15, // 00:00
    14, // 01:00
    12, // 02:00
    11, // 03:00
    10, // 04:00
    9,  // 05:00
    9,  // 06:00
    7,  // 07:00
    10, // 08:00
    13, // 09:00
    18, // 10:00
    21, // 11:00
    24, // 12:00
    26, // 13:00
    27, // 14:00
    28, // 15:00
    28, // 16:00
    27, // 17:00
    25, // 18:00
    22, // 19:00
    21, // 20:00
    19, // 21:00
    18, // 22:00
    16, // 23:00
};

bool busy_hours_library[24] = {
    false, // 00:00
    false, // 01:00
    false, // 02:00
    false, // 03:00
    false, // 04:00
    false, // 05:00
    false, // 06:00
    true,  // 07:00
    true,  // 08:00
    true,  // 09:00
    true,  // 10:00
    true,  // 11:00
    true,  // 12:00
    false, // 13:00
    false, // 14:00
    true,  // 15:00
    true,  // 16:00
    true,  // 17:00
    true,  // 18:00
    true,  // 19:00
    true,  // 20:00
    false, // 21:00
    false, // 22:00
    false, // 23:00
};

bool busy_hours_aulas_i[24] = {
    false, // 00:00
    false, // 01:00
    false, // 02:00
    false, // 03:00
    false, // 04:00
    false, // 05:00
    false, // 06:00
    false, // 07:00
    false, // 08:00
    false, // 09:00
    true,  // 10:00
    true,  // 11:00
    true,  // 12:00
    true,  // 13:00
    true,  // 14:00
    true,  // 15:00
    true,  // 16:00
    true,  // 17:00
    true,  // 18:00
    true,  // 19:00
    false, // 20:00
    false, // 21:00
    false, // 22:00
    false, // 23:00
};

bool busy_hours_aulas_ii[24] = {
    false, // 00:00
    false, // 01:00
    false, // 02:00
    false, // 03:00
    false, // 04:00
    false, // 05:00
    false, // 06:00
    true,  // 07:00
    true,  // 08:00
    true,  // 09:00
    true,  // 10:00
    true,  // 11:00
    true,  // 12:00
    true,  // 13:00
    true,  // 14:00
    true,  // 15:00
    true,  // 16:00
    true,  // 17:00
    true,  // 18:00
    true,  // 19:00
    true,  // 20:00
    true,  // 21:00
    false, // 22:00
    false, // 23:00
};

int main()
{

    double initial_temperature_indoor = 20;
    double temperature_outdoor = day_temperature[0];
    double total_energy_used = 0;

    ChilledWaterCircuit chilledWaterCircuit{};
    CondensedWaterCircuit condensedWaterCircuit{};

    AulasIRecirculatingCircuit aulasIRecirculatingCircuit{};
    Classroom aulasI("Aulas I", initial_temperature_indoor, temperature_outdoor, busy_hours_aulas_ii, aulasIRecirculatingCircuit);

    cout << "0" << endl;

    cout << "Aulas I" << " is " << aulasI.get_indoor_temperature() << "C" << endl;
    cout << "Chilled Water" << " is " << chilledWaterCircuit.water_temperature << "C" << endl;
    cout << "Condensed Water" << " is " << condensedWaterCircuit.water_temperature << "C" << endl;

    for (int hour = 1; hour < 24; hour++)
    {
        temperature_outdoor = day_temperature[hour];

        if (busy_hours_aulas_i[hour] && aulasI.get_indoor_temperature() > 20)
        {
            aulasI.turn_on_fcu();
            aulasI.turn_on_pumps(1);
            aulasI.updateTemperature(true, chilledWaterCircuit.water_temperature, temperature_outdoor);
            aulasI.turn_off_pumps(1);
        }
        else
        {
            aulasI.updateTemperature(false, chilledWaterCircuit.water_temperature, temperature_outdoor);
        }

        if (condensedWaterCircuit.water_temperature > 28)
        {
            condensedWaterCircuit.turn_on_one_tower();
            condensedWaterCircuit.condense_water();
            condensedWaterCircuit.turn_off_both_towers();
        }
        else
        {

            condensedWaterCircuit.not_condense_water(temperature_outdoor);
        }

        if (chilledWaterCircuit.water_temperature > 15)
        {
            chilledWaterCircuit.turn_on_one_chiller();
            chilledWaterCircuit.chill_water(temperature_outdoor);
            chilledWaterCircuit.turn_on_both_chillers();
        }
        else
        {
            chilledWaterCircuit.not_chill_water(temperature_outdoor);
        }

        cout << hour << endl;

        cout << "Aulas I" << " is " << aulasI.get_indoor_temperature() << "C" << endl;
        cout << "Chilled Water" << " is " << chilledWaterCircuit.water_temperature << "C" << endl;
        cout << "Condensed Water" << " is " << condensedWaterCircuit.water_temperature << "C" << endl;
    }

    return 0;
}