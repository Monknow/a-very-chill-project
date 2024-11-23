#ifndef ACTUATOR
#define ACTUATOR

class Actuator
{
public:
    Actuator();

private:
    bool state;
    int cycles;
    double power_consumption;
    double temperature_transfer_coefficient;
};

#endif