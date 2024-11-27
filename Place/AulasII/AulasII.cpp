#include "AulasII.h"
#include "../../Circuits/Recirculating/Recirculating.h"

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

AulasIIRecirculatingCircuit aulasIIRecirculatingCircuit{};

AulasII::AulasII(string name, double instance_temperature_indoor, double instance_temperature_outdoor) : Place(name, instance_temperature_indoor, instance_temperature_outdoor, 0.7, busy_hours_aulas_ii, aulasIIRecirculatingCircuit) {}
