#include "../Place/Classroom/Classroom.h"
#include "../Circuits/ChilledWater/ChilledWater.h"
#include "../Circuits/CondensedWater/CondensedWater.h"
#include <iostream> 
#include <cassert>

using namespace std;

void test_chilled_water_circuit() {
        ChilledWaterCircuit chilledWaterCircuit{};
        assert(chilledWaterCircuit.get_chillers_on() == 0);
        assert(chilledWaterCircuit.get_pumps_on_time() == 0);
        assert(chilledWaterCircuit.get_chillers_cycles() == 0);
        assert(chilledWaterCircuit.get_pumps_cycles() == 0);
        chilledWaterCircuit.turn_on_both_chillers();
        //chilledWaterCircuit.


        cout << "TEST 1 ########### PASSED ###########" << endl;
};

int main()
{
    test_chilled_water_circuit();


    // double initial_temperature_indoor = 20;
    // double temperature_outdoor = day_temperature[0];
    // double total_energy_used = 0;

    // ChilledWaterCircuit chilledWaterCircuit{};
    // CondensedWaterCircuit condensedWaterCircuit{chilledWaterCircuit.water_temperature};

    // AulasIRecirculatingCircuit aulasIRecirculatingCircuit{};
    // Classroom aulasI("Aulas I", initial_temperature_indoor, temperature_outdoor, busy_hours_aulas_ii, aulasIRecirculatingCircuit);

    // cout << "0" << endl;

    // cout << "Aulas I" << " is " << aulasI.get_indoor_temperature() << "C" << endl;
    // cout << "Chilled Water" << " is " << chilledWaterCircuit.water_temperature << "C" << endl;
    // cout << "Condensed Water" << " is " << condensedWaterCircuit.water_temperature << "C" << endl;


    // for (int hour = 1; hour < 24; hour++)
    // {
    //     temperature_outdoor = day_temperature[hour];

    //     if (busy_hours_aulas_i[hour] && aulasI.get_indoor_temperature() > 20)
    //     {
    //         aulasI.recirculating_circuit.turn_on_both_FCUs();
    //         aulasI.turn_on_pumps(1);
    //         aulasI.updateTemperature(true, chilledWaterCircuit.water_temperature, temperature_outdoor);
    //         aulasI.recirculating_circuit.turn_off_both_FCUs();
    //         aulasI.turn_off_pumps(1);
    //     }
    //     else
    //     {
    //         aulasI.updateTemperature(false, chilledWaterCircuit.water_temperature, temperature_outdoor);
    //     }

    //     if (condensedWaterCircuit.water_temperature > 20)
    //     {
    //         condensedWaterCircuit.turn_on_pumps(2);
    //         condensedWaterCircuit.turn_on_one_tower();
    //         condensedWaterCircuit.condense_water();
    //         condensedWaterCircuit.turn_off_both_towers();
    //         condensedWaterCircuit.turn_off_pumps(2);
    //     }
    //     else
    //     {

    //         condensedWaterCircuit.not_condense_water(temperature_outdoor);
    //     }

    //     if (chilledWaterCircuit.water_temperature > 15)
    //     {
    //         chilledWaterCircuit.turn_on_pumps(2);
    //         chilledWaterCircuit.turn_on_one_chiller();
    //         chilledWaterCircuit.chill_water(temperature_outdoor);
    //         chilledWaterCircuit.turn_off_both_chillers();
    //         chilledWaterCircuit.turn_off_pumps(2);
    //     }
    //     else
    //     {
    //         chilledWaterCircuit.not_chill_water(temperature_outdoor);
    //     }

    //     cout << "TIME:  " << hour << " HOUR" << endl;

    //     cout << "Aulas I" << " is " << aulasI.get_indoor_temperature() << "C" << endl;
    //     cout << "Chilled Water" << " is " << chilledWaterCircuit.water_temperature << "C" << endl;
    //     cout << "Condensed Water" << " is " << condensedWaterCircuit.water_temperature << "C" << endl;
    //     cout << endl << "################## Statistics ##################" << endl;
    //     cout << "___________________Energy consumed per circuit___________________" << endl;
    //     cout << "Chilled Water Circuit.............        " << chilledWaterCircuit.get_total_energy_consuption() << endl << endl;
    //     cout << "Condensed Water Circuit...........        " << condensedWaterCircuit.get_total_energy_consuption() << endl << endl;
    //     cout << "AULAS I Recirculating Circuit.....        " << aulasI.recirculating_circuit.get_total_energy_consuption() << endl << endl;

    //     cout << endl << "___________________Cycles per circuit___________________" << endl;
    //     cout << "Chilled Water Circuit (Pumps).......................        " << chilledWaterCircuit.get_pumps_cycles() << endl;
    //     cout << "       Chilled Water Circuit (Chillers).............        " << chilledWaterCircuit.get_chillers_cycles() << endl << endl;
        
    //     cout << "Condensed Water Circuit (Pumps).....................        " << condensedWaterCircuit.get_pumps_cycles() << endl;
    //     cout << "       Condensed Water Circuit (Towers).............        " << condensedWaterCircuit.get_towers_cycles() << endl << endl;

    //     cout << "AULAS I Recirculating Circuit (Pumps)...............        " << aulasI.recirculating_circuit.get_pumps_cycles() << endl;
    //     cout << "       AULAS I Recirculating Circuit (FCUs).........        " << aulasI.recirculating_circuit.get_FCUs_cycles() << endl;

    // }
    // cout << endl << endl << "################# TOTALS###################" << endl;
    // cout << "Chilled Water Circuit (Energy) ...........................            " << chilledWaterCircuit.get_total_energy_consuption() << endl;
    // cout << "Condensed Water Circuit (Energy) .........................            " << condensedWaterCircuit.get_total_energy_consuption() << endl;
    // cout << "AULAS I Recirculating Circuit (Energy) ...................            " << aulasI.recirculating_circuit.get_total_energy_consuption() << endl << endl;

    // cout << "Chilled Water Circuit (Cycles) ...........................            " << chilledWaterCircuit.get_chillers_cycles() + chilledWaterCircuit.get_pumps_cycles() << endl;
    // cout << "Condensed Water Circuit (Cycles) .........................            " << condensedWaterCircuit.get_towers_cycles() + condensedWaterCircuit.get_pumps_cycles() << endl;
    // cout << "AULAS I Recirculating Circuit (Cycles) ...................            " << aulasI.recirculating_circuit.get_FCUs_cycles() + aulasI.recirculating_circuit.get_pumps_cycles() << endl << endl;




    // return 0;
}