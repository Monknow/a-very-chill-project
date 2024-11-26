#include "Library.h"

Library::Library(double instance_temperature_indoor, double instance_temperature_outdoor, bool instance_busy_hours[24], AulasIRecirculatingCircuit instance_recirculating_circuit) : Place("Library", instance_temperature_indoor, instance_temperature_outdoor, 0.9, instance_busy_hours, instance_recirculating_circuit) {}
