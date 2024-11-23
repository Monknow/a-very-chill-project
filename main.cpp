// #include "./Place/Library/Library.h"
#include "./Place/Classroom/Classroom.h"
#include <iostream>

using namespace std;

int main()
{

    bool busy_hours_aulas_ii[24] = {
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        true,
        false,
        false,
        false,
        false,
    };

    // Library library(16, 25, busy_hours_aulas_ii);
    Classroom classroom(16, 25, busy_hours_aulas_ii);

    // library.updateTemperature(false);
    classroom.updateTemperature(false);

    return 0;
}