#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

#define MAX_LINE 80

int main(){

    char *args[MAX_LINE / 2 + 1]; // holds arguments
    char str[MAX_LINE];//holds user input

    int should_run = 1;
    char *token;

    pid_t pid;

    while(should_run){

        printf("Sofia>");
        fflush(stdout);
        
        fgets(str, sizeof str, stdin);
        
        int x = 0;
        args[x] = strtok(str, " ");
        while (args[x] != NULL){
            //printf("%s\n", args[x]);
            x++;
            args[x] = strtok(NULL, " ");

        }


        pid = fork();


        if(pid < 0){
            fprintf(stderr, "Fork Failed");
            return 1;
        }
        else if(pid == 0){
            execvp(args[0], &args[1]);
        }
        else{
            wait(NULL);
            printf("Child Complete\n");
        }
    }

}
