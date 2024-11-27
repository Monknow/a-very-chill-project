#include "./Place/Place.h"
#include "./Place/AulasI/AulasI.h"
#include "./Place/AulasII/AulasII.h"
#include "./Place/Library/Library.h"
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

int main()
{

    double initial_temperature_indoor = 16;
    double temperature_outdoor = day_temperature[0];
    double total_energy_used = 0;

    ChilledWaterCircuit chilledWaterCircuit{};
    CondensedWaterCircuit condensedWaterCircuit{chilledWaterCircuit.water_temperature};

    AulasI aulasI("Aulas I", initial_temperature_indoor, temperature_outdoor);
    AulasII aulasII("Aulas II", initial_temperature_indoor, temperature_outdoor);
    Library library(initial_temperature_indoor, temperature_outdoor);

    Place buildings[3] = {
        aulasI,
        aulasII,
        library,
    };

    for (int hour = 1; hour < 24; hour++)
    {
        temperature_outdoor = day_temperature[hour];

        // Update Condensed Water

        condensedWaterCircuit.update_temperature(temperature_outdoor);

        // Update Chilled Water

        chilledWaterCircuit.update_temperature(temperature_outdoor);

        // Update Buildings

        for (int building = 0; building < 3; building++)
        {
            buildings[building].update_temperature(chilledWaterCircuit.water_temperature, temperature_outdoor, hour);
        }

        aulasI.recirculating_circuit.display_status();
        aulasII.recirculating_circuit.display_status();
        library.recirculating_circuit.display_status();

        chilledWaterCircuit.display_status();
        condensedWaterCircuit.display_status();
    }

    // Print Final Values

    for (int building = 0; building < 3; building++)
    {
        cout << buildings[building].get_name() << " Temperature is " << buildings[building].get_indoor_temperature() << " C" << endl;
    }
    return 0;
}