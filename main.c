#include "functions.h"
int main()
{
    do {
        system("clear");

        int chooseProgramScenario;

        aloe(&chooseProgramScenario);

        printf("Yo bro your input was %d", chooseProgramScenario);

        /*switch (chooseProgramScenario)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
        }*/
    } while (1);

    return 0;
}
