#ifndef ACTUATOR
#define ACTUATOR

class Actuator
{
public:
    Actuator(double a_power_consuption);
    bool switch_state();
    void iterate();
    double get_power_consumed();
    bool get_state();

private:
    bool state;
    int cycles;
    int on_time;
    double power_consumption;
};

#endif