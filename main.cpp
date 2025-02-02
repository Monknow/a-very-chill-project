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
    15, // 01:00
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
    CondensedWaterCircuit condensedWaterCircuit(22);

    AulasI aulasI("Aulas I", initial_temperature_indoor, temperature_outdoor);
    AulasII aulasII("Aulas II", initial_temperature_indoor, temperature_outdoor);
    Library library(initial_temperature_indoor, temperature_outdoor);

    Place buildings[3] = {
        aulasI,
        aulasII,
        library,
    };

    // Display initial status
    cout << "0:00hr" << endl;

    chilledWaterCircuit.update_temperature(temperature_outdoor);

    for (int building = 0; building < 3; building++)
    {
        buildings[building].display_status();
    }

    chilledWaterCircuit.display_status();
    condensedWaterCircuit.display_status();

    // Run Simulation

    for (int hour = 1; hour < 24; hour++)
    {
        cout << hour << ":00hr" << endl;

        // You can use the below code to simulate a day in CDMX;
        // temperature_outdoor = day_temperature[hour];

        cout << "What's the ambient temperature? " << endl;
        cin >> temperature_outdoor;

        // Update Condensed Water

        condensedWaterCircuit.update_temperature(temperature_outdoor);

        // Update Chilled Water

        chilledWaterCircuit.update_temperature(temperature_outdoor);

        // Update And Display Buildings

        for (int building = 0; building < 3; building++)
        {
            buildings[building].update_temperature(chilledWaterCircuit.water_temperature, temperature_outdoor, hour);
            buildings[building].update_comfort(hour);
            buildings[building].display_status();
        }

        chilledWaterCircuit.display_status();
        condensedWaterCircuit.display_status();
    }

    // Print Final Values
    double counter_energy{0};
    int counter_cycles{0};
    counter_energy += chilledWaterCircuit.get_total_energy_consuption();
    counter_energy += condensedWaterCircuit.get_total_energy_consuption();

    counter_cycles += chilledWaterCircuit.get_pumps_cycles();
    counter_cycles += chilledWaterCircuit.get_chillers_cycles();

    counter_cycles += condensedWaterCircuit.get_pumps_cycles();
    counter_cycles += condensedWaterCircuit.get_towers_cycles();

    for (int building = 0; building < 3; building++)
    {
        counter_energy += buildings[building].recirculating_circuit->get_total_energy_consuption();
        counter_cycles += buildings[building].recirculating_circuit->get_pumps_cycles();
        counter_cycles += buildings[building].recirculating_circuit->get_FCUs_cycles();
        buildings[building].recirculating_circuit->display_status();

        cout << "########### Confort ###########" << endl;
        cout << "   Good Confort:   " << buildings[building].good_confort_counter << endl;
        cout << "   Bad Confort:   " << buildings[building].bad_confort_counter << endl;
    }
    cout << "Total energy.......... " << counter_energy << " W " << endl;
    cout << "Total cycles.......... " << counter_cycles << " ON/OFF Cycles " << endl
         << endl;

    // TODO Print final confort
    return 0;
}