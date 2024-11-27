#ifndef RECIRCULATING
#define RECIRCULATING

#include "../Circuits.h"
#include "../../Actuator/FCU/FCU.h"
#include <string>

class RecirculatingCircuit : public Circuit
{
protected:
    FCU fcu;

public:
    RecirculatingCircuit(int n_of_pumps);
    virtual double get_temperature_transfer_coefficient();
    int get_FCU_on_time();
    int get_total_energy_consuption();
    int get_total_on_time();
    void turn_on_fcu();
};

class AulasIRecirculatingCircuit : public RecirculatingCircuit
{
protected:
    FCU fcu_2;
    double one_pump_TTCf;
    double two_pump_TTCf;

public:
    AulasIRecirculatingCircuit();
    double get_temperature_transfer_coefficient();
};

class AulasIIRecirculatingCircuit : public RecirculatingCircuit
{
protected:
    double one_pump_TTCf;
    double two_pump_TTCf;

public:
    AulasIIRecirculatingCircuit();
    double get_temperature_transfer_coefficient();
};

class BiblioTECRecirculatingCircuit : public RecirculatingCircuit
{
protected:
    double one_pump_TTCf;
    double two_pump_TTCf;
    double three_pump_TTCf;

public:
    BiblioTECRecirculatingCircuit();
    double get_temperature_transfer_coefficient();
    double get_cooling_capacity(double RToff, double TCh);
};

#endif