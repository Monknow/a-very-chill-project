#include "./Place/Library/Library.h"
#include "./Place/Classroom/Classroom.h"
#include <iostream>

using namespace std;

bool busy_hours_library[24] = {
    false, // 00:00
    false, // 01:00
    false, // 02:00
    false, // 03:00
    false, // 04:00
    false, // 05:00
    false, // 06:00
    true,  // 07:00
    true,  // 08:00
    true,  // 09:00
    true,  // 10:00
    true,  // 11:00
    true,  // 12:00
    false, // 13:00
    false, // 14:00
    true,  // 15:00
    true,  // 16:00
    true,  // 17:00
    true,  // 18:00
    true,  // 19:00
    true,  // 20:00
    false, // 21:00
    false, // 22:00
    false, // 23:00
};

bool busy_hours_aulas_i[24] = {
    false, // 00:00
    false, // 01:00
    false, // 02:00
    false, // 03:00
    false, // 04:00
    false, // 05:00
    false, // 06:00
    false, // 07:00
    false, // 08:00
    false, // 09:00
    true,  // 10:00
    true,  // 11:00
    true,  // 12:00
    true,  // 13:00
    true,  // 14:00
    true,  // 15:00
    true,  // 16:00
    true,  // 17:00
    true,  // 18:00
    false, // 19:00
    false, // 20:00
    false, // 21:00
    false, // 22:00
    false, // 23:00
};

bool busy_hours_aulas_ii[24] = {
    false, // 00:00
    false, // 01:00
    false, // 02:00
    false, // 03:00
    false, // 04:00
    false, // 05:00
    false, // 06:00
    true,  // 07:00
    true,  // 08:00
    true,  // 09:00
    true,  // 10:00
    true,  // 11:00
    true,  // 12:00
    true,  // 13:00
    true,  // 14:00
    true,  // 15:00
    true,  // 16:00
    true,  // 17:00
    true,  // 18:00
    true,  // 19:00
    true,  // 20:00
    true,  // 21:00
    false, // 22:00
    false, // 23:00
};

int main()
{

    Library library(16, 25, busy_hours_library);
    Classroom aulasI("Aulas I", 27, 30, busy_hours_aulas_ii);

    aulasI.updateTemperature(true, 10, 0.4);
    // library.updateTemperature(false, 10);

    
    return 0;
}