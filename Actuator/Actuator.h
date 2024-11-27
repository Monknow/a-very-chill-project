#ifndef ACTUATOR
#define ACTUATOR

class Actuator
{
public:
    Actuator();
    Actuator(double a_power_consuption);
    bool switch_state();
    void iterate();
    double get_power_consumed();
    bool get_state();
    double get_power_consumption();
    int get_on_time();
    void turn_off();
    void turn_on();
    int get_cycles();

private:
    bool state;
    int cycles;
    int on_time;
    double power_consumption;
};

#endif