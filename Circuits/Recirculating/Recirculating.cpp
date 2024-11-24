#include "Recirculating.h"
#include "../../Actuator/Pumps/Pumps.h"
#include <string>
#include <iostream>

const string AULAS_I_NAME = "Aulas I";
const string AULAS_II_NAME = "";
const string BIBLIOTEC_NAME = "";

using namespace std;

RecirculatingCircuit::RecirculatingCircuit(int n_of_pumps): Circuit(n_of_pumps, "RecirculatingPump"), fcu(FCU()) {
}

int RecirculatingCircuit::get_FCU_on_time(){ return fcu.get_on_time(); }

int RecirculatingCircuit::get_total_on_time() { return fcu.get_on_time() + get_pumps_on_time(); }

int RecirculatingCircuit::get_total_energy_consuption() { return fcu.get_power_consumed() + get_pumps_total_energy_consumption(); }

AulasIRecirculatingCircuit::AulasIRecirculatingCircuit(): RecirculatingCircuit(2), fcu_2(FCU()), one_pump_TTCf(0.3), two_pump_TTCf(0.4) {}

double AulasIRecirculatingCircuit::get_cooling_capacity() {
    if (!fcu.get_state() || !fcu_2.get_state())
    {
        cout << "Unable to cool, one or more of Aulas I FCU not turned on!!" << endl;
        return 0;
    }

    double cooling_capacity {0};

    switch (get_pumps_on())
    {
    case 0:
        cooling_capacity = 0;
        break;
    case 1:
        cooling_capacity = one_pump_TTCf;
        break;
    
    case 2:
        cooling_capacity = two_pump_TTCf;
        break;

    default:
        cout << "ERROR: Unexpected code excecution on Recirculating.cpp please report it" << endl;
        break;
    }

    return cooling_capacity;
}

AulasIIRecirculatingCircuit::AulasIIRecirculatingCircuit(): RecirculatingCircuit(2), one_pump_TTCf(0.25), two_pump_TTCf(0.4) {}

double AulasIIRecirculatingCircuit::get_cooling_capacity() {
    if (!fcu.get_state())
    {
        cout << "Unable to cool, Aulas II FCU not turned on!!" << endl;
        return 0;
    }

    double cooling_capacity {0};

    switch (get_pumps_on())
    {
    case 0:
        cooling_capacity = 0;
        break;
    case 1:
        cooling_capacity = one_pump_TTCf;
        break;
    
    case 2:
        cooling_capacity = two_pump_TTCf;
        break;

    default:
        cout << "ERROR: Unexpected code excecution on Recirculating.cpp please report it" << endl;
        break;
    }

    return cooling_capacity;
}


BiblioTECRecirculatingCircuit::BiblioTECRecirculatingCircuit(): RecirculatingCircuit(3), one_pump_TTCf(0.2), two_pump_TTCf(0.3), three_pump_TTCf(0.4) {}

double BiblioTECRecirculatingCircuit::get_cooling_capacity() {
    if (!fcu.get_state())
    {
        cout << "Unable to cool, BiblioTEC FCU not turned on!!" << endl;
        return 0;
    }

    double cooling_capacity {0};

    switch (get_pumps_on())
    {
    case 0:
        cooling_capacity = 0;
        break;
    case 1:
        cooling_capacity = one_pump_TTCf;
        break;
    
    case 2:
        cooling_capacity = two_pump_TTCf;
        break;

    case 3:
        cooling_capacity = three_pump_TTCf;
        break;
    default:
        cout << "ERROR: Unexpected code excecution on Recirculating.cpp please report it" << endl;
        break;
    }

    return cooling_capacity;
}