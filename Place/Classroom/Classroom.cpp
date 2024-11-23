#include "Classroom.h"

Classroom::Classroom(double instance_temperature_indoor, double instance_temperature_outdoor, bool instance_busy_hours[24]) : Place("Classroom", instance_temperature_indoor, instance_temperature_outdoor, 0.7, instance_busy_hours) {}
