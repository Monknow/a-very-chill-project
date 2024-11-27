#include "Library.h"

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

BiblioTECRecirculatingCircuit libraryRecirculatingCircuit;

Library::Library(double instance_temperature_indoor, double instance_temperature_outdoor) : Place("Library", instance_temperature_indoor, instance_temperature_outdoor, 0.9, busy_hours_library, &libraryRecirculatingCircuit) {}
