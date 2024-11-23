#include "Recirculating.h"
#include "../../Actuator/Pumps/Pumps.h"

RecirculatingCircuit::RecirculatingCircuit(int n_of_pumps): Circuit(n_of_pumps, "RecirculatingPump"), fcu(FCU()) {
}

int RecirculatingCircuit::get_FCU_on_time(){ return fcu.get_on_time(); }

int RecirculatingCircuit::get_total_on_time() { return fcu.get_on_time() + get_pumps_on_time(); }

int RecirculatingCircuit::get_total_energy_consuption() { return fcu.get_power_consumed() + get_pumps_total_energy_consumption(); }
