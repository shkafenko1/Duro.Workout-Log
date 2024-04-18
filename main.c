#include "core.h"
int main()
{
    int chooseProgramScenario;

    do {
        system("clear");

        getScenarioChoice(&chooseProgramScenario);

        switch (chooseProgramScenario)
        {
            case 1:
                accessWorkouts();
                break;
            case 2:
                recordNewWorkout();
                break;
            case 3:
                getTips();
                break;
            default:
                break;
        }
        restart(&chooseProgramScenario);

    } while (chooseProgramScenario != 0);

    system("clear");
    return 0;
}