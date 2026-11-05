#include <stdio.h>
#include <stdlib.h>
int main()
{
    int choice;

    while (1)
    {
       
        printf("\n");
        printf("====================================================\n");
        printf(" ---->  LINUX PROCESS MONITORING SYSTEM  <---- \n");
        printf("====================================================\n");

        printf("1. View All Processes\n");
        printf("2. Search Process\n");
        printf("3. View Memory Information\n");
        printf("4. View Process Details\n");
        printf("5. Terminate Process\n");
        printf("6. Clear\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
           case 1:
    system("ps -e -o pid,comm,state");
    break;
    
    
case 2:
{
    char name[100];

    printf("Enter process name: ");
    scanf("%99s", name);

    char command[200];

    snprintf(
        command,
        sizeof(command),
        "ps -e -o pid,comm | grep -i -- '%s'",
        name
    );

    system(command);

    break;
}


case 3:
    system("free -h");
    break;


case 4:
{
    int pid;

    printf("Enter Process ID: ");
    scanf("%d", &pid);

    if (pid <= 0)
    {
        printf("Invalid PID.\n");
        break;
    }

    char command[150];

    snprintf(
        command,
        sizeof(command),
        "ps -p %d -o pid,ppid,comm,state,pcpu,pmem",
        pid
    );

    system(command);

    break;
}


case 5:
{
    int pid;
    char confirmation;

    printf("Enter PID to terminate: ");

    if (scanf("%d", &pid) != 1 || pid <= 1)
    {
        printf("Invalid or protected PID.\n");
        break;
    }

    printf("Are you sure? Enter y to confirm: ");
    scanf(" %c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y')
    {
        char command[100];

        snprintf(
            command,
            sizeof(command),
            "kill -TERM %d",
            pid
        );

        system(command);

        printf("Termination request sent.\n");
    }
    else
    {
        printf("Operation cancelled.\n");
    }

    break;
}

case 6:
system("clear");
break;
            case 0:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
