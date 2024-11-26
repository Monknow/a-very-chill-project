#ifndef TOWER
#define TOWER

#include "../Actuator.h"
class Tower : public Actuator
{
    public:
        Tower(){
            Actuator(10);
        };
};

#endif