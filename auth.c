#include "core.h"
#include "auth.h"

void auth()
{
    char username[20];
    char password[20];
    do
    {
        textMessages(1);
        fgets(username, 21, stdin);
        textMessages(2);
        fgets(password, 21, stdin);
        system("clear");
    }while (!verify(username, password));
}

int verify(char* usrn, char* pasw)
{
    FILE* authorize = fopen("auth_data.txt", "r");
    char username[20];
    char password[20];
    fgets(username, 20, authorize);
    fgets(password, 20, authorize);

    fclose(authorize);

    if(strcmp(username, usrn) == 0 && strcmp(password, pasw) == 0)
        return 1;
    else
        return 0;

}

/*void createfile()
{
    FILE* auth = fopen("auth_data.txt", "w");
}*/

void textMessages(int num)
{
    switch (num)
    {
        case 1:
            printf("Enter your username: ");
            break;
        case 2:
            printf("Enter your password: ");
            break;
        case 3:
            printf("");
            break;
        default:
            break;
    }
}