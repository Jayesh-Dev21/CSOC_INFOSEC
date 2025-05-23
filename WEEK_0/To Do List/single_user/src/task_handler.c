#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ? Header files ? //
#include "headers/utlis.h"
#include "headers/task_handler.h"

// ? Defines ? //
#define MAX_TASKS 100
#define MAX_LINE_LENGTH 100
#define FILE_NAME "user_tasks.txt"


// ? Boolean ? //
typedef enum { false, true } bool;


// ? Task Structure ? //
typedef struct {
    char query[MAX_LINE_LENGTH];
    bool status;
} Task;

// ?? Function Defitions for Task ?? //


void addTask(const char *username){
    banner("ADD NEW TASK");
    char tempTask[MAX_LINE_LENGTH];

    printf("Enter new task: ");
    getchar();

    fgets(tempTask, MAX_LINE_LENGTH, stdin);
    tempTask[strcspn(tempTask, "\n")] = '\0'; // remove newline

    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("Error opening task file.\n");
        return;
    }

    fprintf(fp, "%s|0\n", tempTask); // 0 = not completed
    fclose(fp);
    printf(" >> New Task added successfully <<\n");
}

void deleteTask(const char *username){
    banner("DELETE TASK");

    Task tasks[MAX_TASKS];
    int count = 0;
    int lineIndex;
    int deleteIndex;

    FILE *fp = fopen(FILE_NAME, "r");
    if(fp == NULL){
        printf("No tasks to delete.\n");
        return;
    }

    while(fscanf(fp, " %[^\n|]|%d", tasks[count].query, &tasks[count].status) == 2){
        count++;
    }

    fclose(fp);

    
    viewTasks(username);
    printf("Enter task id to delete: ");
    scanf("%d", &deleteIndex);
    printf("%d\n", deleteIndex);

    if(deleteIndex < 1 || deleteIndex > count){
        printf("Invalid task id\n");
        return;
    }
    fp = fopen(FILE_NAME, "w");
    for(lineIndex = 0; lineIndex < count; lineIndex++){
        if(lineIndex != deleteIndex - 1) {
            fprintf(fp, "%s|%d\n", tasks[lineIndex].query, tasks[lineIndex].status);
        }
    }
    fclose(fp);
    printf(" >> Task deleted successfully <<\n");
}

void viewTasks_banner(const char *username){
    banner("VIEW TASKS");
    viewTasks(username);
}
void viewTasks(const char *username){

    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("No task was found.\n");
        return;
    }
    char line[MAX_LINE_LENGTH];

    int taskCount = 1;
    while (fgets(line, sizeof(line), fp)) {
        char *task = strtok(line, "|");
        char *done = strtok(NULL, "|");

        if (task && done) {
            printf("%d. %s <%c>\n", taskCount, task, (done[0] == '1' ? 'X' : ' '));
        }
        taskCount++;
    }

    if(taskCount == 1){
        printf("No tasks found.\n");
    }
    fclose(fp);
}

void taskCompletion(const char *username){
    banner("MARK TASKS AS COMPLETED");

    Task tasks[MAX_TASKS];
    int count = 0;
    int lineIndex;
    int markIndex;

    FILE *fp = fopen(FILE_NAME, "r");
    if(fp == NULL){
        printf("No tasks to delete.\n");
        return;
    }

    while(fscanf(fp, " %[^\n|]|%d", tasks[count].query, &tasks[count].status) == 2){
        count++;
    }

    fclose(fp);

    viewTasks(username);
    printf("Enter task id to mark as completed: ");
    scanf("%d", &markIndex);

    if(markIndex < 1 || markIndex > count){
        printf("Invalid task id.\n");
        return;
    }

    tasks[markIndex - 1].status = true; 

    fp = fopen(FILE_NAME, "w");
    for(lineIndex = 0; lineIndex < count; lineIndex++){
        fprintf(fp, "%s|%d\n", tasks[lineIndex].query, tasks[lineIndex].status);
    }
    fclose(fp);

    printf(" >> Task marked as completed successfully <<\n");
}

// ? End of Code ? //
