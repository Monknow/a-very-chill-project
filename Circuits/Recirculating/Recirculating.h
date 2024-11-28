#ifndef RECIRCULATING
#define RECIRCULATING

#include "../Circuits.h"
#include "../../Actuator/FCU/FCU.h"
#include <string>
#include <optional>

class RecirculatingCircuit : public Circuit
{
private:
    string name;

protected:
    FCU fcu;
    std::optional<FCU> fcu_2;

public:
    RecirculatingCircuit();
    RecirculatingCircuit(int n_of_pumps, int n_of_fcu, string instance_name);

    int get_FCU_on_time();
    int get_total_energy_consuption();
    int get_total_on_time();
    void turn_on_fcu();
    void turn_off_fcu();
    void display_status();
    virtual void turn_on_both_FCUs();
    virtual void turn_off_both_FCUs();
    virtual int get_FCUs_cycles();
    virtual double get_temperature_transfer_coefficient();
    int n_of_fcu;
};

class AulasIRecirculatingCircuit : public RecirculatingCircuit
{

protected:
    FCU fcu_2;
    double one_pump_TTCf;
    double two_pump_TTCf;

public:
    AulasIRecirculatingCircuit();
    void iterate();
    void display_status();
    int get_FCUs_cycles();
    void turn_off_both_FCUs();
    void turn_on_both_FCUs();
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
    int get_FCUs_cycles();
    void iterate();
    void display_status();
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
    int get_FCUs_cycles();
    void iterate();
    void display_status();
};

#endif