#include "Actuator.h"

Actuator::Actuator(){};

Actuator::Actuator(double a_power_consuption)
    : 
    state(false),
    cycles(0),
    on_time(0), 
    power_consumption(a_power_consuption)
    {}

bool Actuator::switch_state() {
    Actuator::state = !Actuator::state;

    //If a on-off cycle is compleated
    //i.e. The current state after switching is off
    //we sould add a cycle to the object
    if (!Actuator::state){ Actuator::cycles++; }

    // Return current state
    return Actuator::state;
}

void Actuator::iterate() {
    if (!Actuator::state){return;}

    // If actuator is on, change on_time
    on_time++;
}

double Actuator::get_power_consumption() { return power_consumption; }

int Actuator::get_on_time() {return on_time;}

double Actuator::get_power_consumed(){ return on_time * power_consumption;}

bool Actuator::get_state() { return Actuator::state; }

