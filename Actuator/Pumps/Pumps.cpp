#include "Pumps.h"
const double CHILL_WATER_PUMP_CONSUMPTION = 15;
const double CONDENSSED_WATER_PUMP_CONSUMPTION = 14;
const double RECIRCULATING_WATER_PUMP_CONSUMPTION = 11;


// Default constructor is needed to pass it as an array to the chillers
Pump::Pump():Actuator(0){};

Pump::Pump(double a_power_consuption):Actuator(a_power_consuption){};

ChillWaterPump::ChillWaterPump():Pump(CHILL_WATER_PUMP_CONSUMPTION){};
CondensedWaterPump::CondensedWaterPump():Pump(CONDENSSED_WATER_PUMP_CONSUMPTION){};
RecirculatingPump::RecirculatingPump():Pump(RECIRCULATING_WATER_PUMP_CONSUMPTION){};