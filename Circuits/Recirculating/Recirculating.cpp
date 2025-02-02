#include "Recirculating.h"
#include "../../Actuator/Pumps/Pumps.h"
#include <string>
#include <iostream>

using namespace std;

// Recirculating Circuit

RecirculatingCircuit::RecirculatingCircuit() : Circuit(2, "RecirculatingPump"), fcu(FCU())
{
}

RecirculatingCircuit::RecirculatingCircuit(int n_of_pumps, int instance_n_of_fcu, string instance_name) : Circuit(n_of_pumps, "RecirculatingPump"), fcu(FCU())
{
    n_of_fcu = instance_n_of_fcu;
    name = instance_name;
}

int RecirculatingCircuit::get_FCU_on_time() { return fcu.get_on_time(); }

int RecirculatingCircuit::get_total_on_time() { return fcu.get_on_time() + get_pumps_on_time(); }

double RecirculatingCircuit::get_temperature_transfer_coefficient() { return 0; }

int RecirculatingCircuit::get_total_energy_consuption() {
    return fcu.get_power_consumed() + get_pumps_total_energy_consumption(); }

void RecirculatingCircuit::turn_on_fcu() { RecirculatingCircuit::fcu.turn_on(); }

void RecirculatingCircuit::turn_off_fcu()
{
    RecirculatingCircuit::fcu.turn_off();
}

int RecirculatingCircuit::get_FCUs_cycles()
{
    return 0;
}

void RecirculatingCircuit::display_status()
{
    cout << "##### " << name << " RECIRCULATING CIRCUIT #####\n\n";
    cout << "   _____________ FCUs STATUS _____________\n\n";
    cout << "       # FCU I " << " Status: " << (fcu.get_state() ? "ON" : "OFF") << " Cycles: " << fcu.get_cycles() << " On Time: " << fcu.get_on_time() << endl;

    // Check for second FCU (Used in Aulas II)

    if (n_of_fcu == 2)
    {
        cout << "       # FCU II " << " Status: " << (fcu.get_state() ? "ON" : "OFF") << " Cycles: " << fcu.get_cycles() << " On Time: " << fcu.get_on_time() << endl;
    }

    display_pumps_status();

    cout << "   Energy Consumed:        " << get_total_energy_consuption() << " W\n\n";
}

void RecirculatingCircuit::turn_on_both_FCUs()
{
    // Empty Implementation so we have different RecirculatingCircuits in place
}

void RecirculatingCircuit::turn_off_both_FCUs()
{
    // Empty Implementation so we have different RecirculatingCircuits in place
}

// Aulas II Recirculating Circuit

AulasIRecirculatingCircuit::AulasIRecirculatingCircuit() : RecirculatingCircuit(2, 2, "Aulas I"), fcu_2(FCU()), one_pump_TTCf(0.3), two_pump_TTCf(0.4)
{
}

double AulasIRecirculatingCircuit::get_temperature_transfer_coefficient()
{
    if (!fcu.get_state() && !fcu_2.get_state())
    {
        cout << "Unable to cool, one or more of Aulas I FCU not turned on!!" << endl;
        return 0;
    }

    iterate();

    double cooling_capacity{0};

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

int AulasIRecirculatingCircuit::get_FCUs_cycles()
{
    return fcu.get_cycles() + fcu_2.get_cycles();
}

void AulasIRecirculatingCircuit::turn_on_both_FCUs()
{
    fcu.turn_on(), fcu_2.turn_on();
}

void AulasIRecirculatingCircuit::turn_off_both_FCUs()
{
    fcu.turn_off(), fcu_2.turn_off();
}

void AulasIRecirculatingCircuit::iterate()
{
    iterate_pumps();
    fcu.iterate();
    fcu_2.iterate();
}

void AulasIRecirculatingCircuit::display_status()
{
    cout << "##### AULAS I RECIRCULATING CIRCUIT #####\n\n";
    cout << "   _____________ FCUs STATUS _____________\n\n";
    cout << "       # FCU I " << " Status: " << (fcu.get_state() ? "ON" : "OFF") << " Cycles: " << fcu.get_cycles() << endl;
    cout << "       # FCU II " << " Status: " << (fcu_2.get_state() ? "ON" : "OFF") << " Cycles: " << fcu_2.get_cycles() << endl
         << endl;
    display_pumps_status();
}

// Aulas II Recirculating Circuit

AulasIIRecirculatingCircuit::AulasIIRecirculatingCircuit() : RecirculatingCircuit(2, 1, "Aulas II"), one_pump_TTCf(0.25), two_pump_TTCf(0.4) {}

double AulasIIRecirculatingCircuit::get_temperature_transfer_coefficient()
{
    if (!fcu.get_state())
    {
        cout << "Unable to cool, Aulas II FCU not turned on!!" << endl;
        return 0;
    }
    iterate();


    double cooling_capacity{0};

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

int AulasIIRecirculatingCircuit::get_FCUs_cycles()
{
    return fcu.get_cycles();
}

void AulasIIRecirculatingCircuit::iterate()
{
    iterate_pumps();
    fcu.iterate();
}

void AulasIIRecirculatingCircuit::display_status()
{
    cout << "##### AULAS II RECIRCULATING CIRCUIT #####\n\n";
    cout << "   _____________ FCU STATUS _____________\n\n";
    cout << "       # FCU I " << " Status " << (fcu.get_state() ? "ON" : "OFF") << " Cycles: " << fcu.get_cycles() << endl
         << endl;
    display_pumps_status();
}

// Library Recirculating Circuit

BiblioTECRecirculatingCircuit::BiblioTECRecirculatingCircuit() : RecirculatingCircuit(3, 1, "Library"), one_pump_TTCf(0.2), two_pump_TTCf(0.3), three_pump_TTCf(0.4) {}

double BiblioTECRecirculatingCircuit::get_temperature_transfer_coefficient()
{
    if (!fcu.get_state())
    {
        cout << "Unable to cool, BiblioTEC FCU not turned on!!" << endl;
        return 0;
    }
    iterate();


    double cooling_capacity{0};

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

double BiblioTECRecirculatingCircuit::get_cooling_capacity(double RToff, double TCh)
{

    double cooling_capacity = (RToff - TCh) * get_temperature_transfer_coefficient();
    return cooling_capacity;
}

int BiblioTECRecirculatingCircuit::get_FCUs_cycles()
{
    return fcu.get_cycles();
}

void BiblioTECRecirculatingCircuit::iterate()
{
    iterate_pumps();
    fcu.iterate();
}

void BiblioTECRecirculatingCircuit::display_status()
{
    cout << "##### BiblioTEC RECIRCULATING CIRCUIT #####\n\n";
    cout << "   _____________ FCU STATUS _____________\n\n";
    cout << "       # FCU I " << " Status " << (fcu.get_state() ? "ON" : "OFF") << " Cycles: " << fcu.get_cycles() << endl
         << endl;
    display_pumps_status();
}