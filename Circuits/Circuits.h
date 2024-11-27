#ifndef CIRCUIT
#define CIRCUIT
#include <string>
#include "../Actuator/Pumps/Pumps.h"
using namespace std;


class Circuit
{
private:
    int n_of_pumps;
    Pump pumps[8]; // 8 is the maximum required
public:
    Circuit(Pump a_pumps[], int a_n_of_pumps);
    Circuit( int a_n_of_pumps, string pump_type);
    int get_pumps();
    int get_pumps_on();
    void turn_on_pumps(int n);
    void turn_off_pumps(int n);
    double get_instant_energy_consumption();
    int get_pumps_on_time();
    double get_pumps_total_energy_consumption();
    virtual int get_total_on_time();
    virtual int get_total_energy_consuption();
    int get_pumps_cycles();
    void iterate_pumps();
    virtual void iterate();
};


#endif
