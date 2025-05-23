#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ? Header files ? //
#include "headers/utlis.h"
#include "headers/task_handler.h"

void banner(const char *title) {
    printf("\n========================================================\n");
    char command[512];
    snprintf(command, sizeof(command), "python3 python_scripts/banner.py \"%s\"", title);
    system(command);
    printf("========================================================\n");
}


void loger(const char *username) {
    int choice;
    FILE *fp;

    printf("\nHi user, welcome to my To-Do List Program!\n");

    menu(username);
    return;
}

void menu(const char *username){
    int choice;
    while (1) {
        banner("TO-DO MENU");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Mark Task as Done\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                addTask(username); 
                break;
            case 2: 
                viewTasks_banner(username); 
                break;
            case 3: 
                deleteTask(username); 
                break;
            case 4: 
                taskCompletion(username); 
                break;
            case 5: 
                return;
            default: 
                printf("❌Option Chosen is Invalid.\n");
        }
    }
}

// ? End of Code ? //
