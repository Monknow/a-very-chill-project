#include "Circuits.h"
#include <iostream>
#include <string>

using namespace std;


Circuit::Circuit(Pump a_pumps[], int a_n_of_pumps):n_of_pumps(a_n_of_pumps) {
    for (int i = 0; i < n_of_pumps; i++) {
        pumps[i] = a_pumps[i];
    }
}

// Overload constructor for built in initialization of Pumps
Circuit::Circuit(int a_n_of_pumps, string pump_type ):n_of_pumps(a_n_of_pumps) {
    
    if (pump_type == "ChillWaterPump")
    {
        for (int i = 0; i < n_of_pumps; i++) {
            pumps[i] = ChillWaterPump(); 
        }
    }

    else if (pump_type == "CondensedWaterPump")
    {
        for (int i = 0; i < n_of_pumps; i++) {
            pumps[i] = CondensedWaterPump();
        }
    }

    else if (pump_type == "RecirculatingPump")
    {
        for (int i = 0; i < n_of_pumps; i++) {
            pumps[i] = RecirculatingPump();
        }
    }
}

int Circuit::get_pumps() {
    return Circuit::n_of_pumps;
}

int Circuit::get_pumps_on() {
    int counter {0};
    for (int i = 0; i < n_of_pumps; i++)
    {
        if (pumps[i].get_state()){ counter++; }
    }
    return counter;
}

void Circuit::turn_on_pumps(int n) {
    int n_of_pumps_off {get_pumps() - get_pumps_on()};
    if (n > n_of_pumps_off)
    {
        cout << "ERROR: CANNOT TURN ON " << n << " PUMPS ON CIRCUIT WHERE ONLY " << n_of_pumps_off << " ARE OFF!!";
        return;
    }

    int turned_on {0};
    for (int i = 0; (i < get_pumps()) && (turned_on < n); i++)
    {
        if (!pumps[i].get_state()) {
            turned_on++;
            pumps[i].switch_state();
        }
    }
    
}

void Circuit::turn_off_pumps(int n) {
   
    if (n > get_pumps_on())
    {
        cout << "ERROR: CANNOT TURN OFF " << n << " PUMPS ON CIRCUIT WHERE ONLY " << get_pumps_on() << " ARE ON!!";
        return;
    }

    int turned_off {0};
    for (int i = 0; (i < get_pumps()) && (turned_off < n); i++)
    {
        if (pumps[i].get_state()) {
            turned_off++;
            pumps[i].switch_state();
        }
    }
    
}

double Circuit::get_instant_energy_consumption() {
    return get_pumps_on() * pumps[0].get_power_consumption();
}

int Circuit::get_pumps_on_time() {
    int time_counter {0};
    for (int i = 0; i < n_of_pumps; i++){
        time_counter += pumps[i].get_on_time();
    }

    return time_counter;
}

int Circuit::get_pumps_cycles() {
    int counter {0};
    for (int i = 0; i < n_of_pumps; i++){
        counter += pumps[i].get_cycles();
    }

    return counter;
}

void Circuit::iterate_pumps()
{;
    for (int i = 0; i < n_of_pumps; i++){
        pumps[i].iterate();
    }
}

void Circuit::iterate()
{
    return;
}

void Circuit::display_pumps_status()
{
    cout << "   _____________ PUMP STATUS _____________\n\n";
    for (int i = 0; i < n_of_pumps; i++){
        cout << "        # PUMP " << i << ": Status " <<  (pumps[i].get_state() ? "ON":"OFF") << " Cycles: " << pumps[i].get_cycles() <<" ON Time " << pumps[i].get_on_time() << endl;
    }
    cout << "   Energy Consumed:        " << get_pumps_total_energy_consumption() << " W\n\n";
    cout << "\n\n\n";
}

double Circuit::get_pumps_total_energy_consumption() { return get_pumps_on_time() * pumps[0].get_power_consumption(); }

int Circuit::get_total_on_time(){return 0;}

int Circuit::get_total_energy_consuption(){return 0;}