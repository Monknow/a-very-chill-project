#include "Classroom.h"

Classroom::Classroom(string name, double instance_temperature_indoor, double instance_temperature_outdoor, bool instance_busy_hours[24], AulasIRecirculatingCircuit instance_recirculating_circuit) : Place(name, instance_temperature_indoor, instance_temperature_outdoor, 0.7, instance_busy_hours, instance_recirculating_circuit) {}
