#include "Chiller.h"
#include "../Actuator.h"

Chiller::Chiller(Pump a_pumps[8]): Actuator(60){
    for (int i = 0; i < 8; i++)
    {
        pumps[i] = a_pumps[i];
    }
    
};