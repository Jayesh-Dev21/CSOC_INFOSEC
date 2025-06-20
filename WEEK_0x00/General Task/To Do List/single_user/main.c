// ** To Do Program for Single User ** //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ? Header files ? //
#include "src/headers/utlis.h"
#include "src/headers/task_handler.h"

// ? Defines ? //
#define MAX_TASKS 100
#define MAX_LINE_LENGTH 100
#define FILE_NAME "user_tasks.txt"

// ? Boolean ? //
typedef enum { false, true } bool;

// ? User Credentials ? //
typedef struct {
    char username[50];
} User;

// ? Task Structure ? //
typedef struct {
    char query[MAX_LINE_LENGTH];
    bool status;
} Task;



// ^ Main Function ^ //
int main(int argc, char *argv[]) {
    
    banner("TO-DO LIST PROGRAM (Single-User)");
    User localuser;
    localuser.username[50] = '0';
    loger(localuser.username);

    banner("GOODBYE USER");
    printf("\n");
    return 0;
}    


// ? End of Code ? //
