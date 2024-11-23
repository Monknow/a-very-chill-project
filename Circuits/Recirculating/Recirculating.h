#include "../Circuits.h"
#include "../../Actuator/FCU/FCU.h"

class RecirculatingCircuit : public Circuit
{
private:
    FCU fcu;

public:
    RecirculatingCircuit(int n_of_pumps);
    int get_FCU_on_time();
    int get_total_energy_consuption();
    int get_total_on_time();
};

