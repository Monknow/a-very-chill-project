#include "./Place/Classroom/Classroom.h"
#include "./Circuits/Recirculating/Recirculating.h"
#include <iostream>

using namespace std;

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
    false, // 19:00
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

    double initial_temperature_indoor = 16;
    double temperature_outdoor_temperature = 25;

    AulasIRecirculatingCircuit aulasIRecirculatingCircuit{};
    Classroom aulasI("Aulas I", initial_temperature_indoor, temperature_outdoor_temperature, busy_hours_aulas_ii, aulasIRecirculatingCircuit);

    for (int hour = 0; hour < 24; hour++)
    {
        aulasI.updateTemperature(true, 10, 0.4);
    }

    return 0;
}