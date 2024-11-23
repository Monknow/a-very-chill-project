#ifndef CIRCUIT
#define CIRCUIT
#include "../Actuator/Pumps/Pumps.h"

class Circuit
{
private:
    int n_of_pumps;
    Pump pumps[];
public:
    Circuit(Pump a_pumps[], int a_n_of_pumps);
    int get_pumps();
    int get_pumps_on();
    void turn_on_pumps(int n);
    void turn_off_pumps(int n);
    double get_instant_energy_consumption();
    int get_pumps_on_time();
    double get_pumps_total_energy_consumption();
    virtual double get_total_on_time();
    virtual double get_total_energy_consuption();
};


#endif
