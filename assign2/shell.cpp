/**
 * After reading user input, the steps are:
 * (1) fork a child process using fork()
 * (2) the child process will invoke execvp()
 * (3) parent will invoke wait() unless command included &
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <iostream>

using namespace std;

#define MAX_LINE 80 /* The maximum length command */

// TODO: create a .h file and clean code into functions if possible

int main()
{
  char *args[MAX_LINE / 2 + 1]; /* command line arguments */

  // string commands [] = {"ps", "-ael", NULL}

  string ps = "ps";
  string ael = "-ael";
  string exit = "exit";

  pid_t pid = fork();

  args[0] = (char *)ps.c_str();
  args[1] = (char *)ael.c_str();
  args[2] = NULL;


  // TODO: MAKE AN EXIT COMMAND

  while (1)
  {
    
    if (pid == 0)
    {
      execvp(args[0], args);
    }
    
   /*  if (pid > 0){

      if (wait(NULL) == -1){

        perror(":C ");
      }

    } */

  }

  return 0;
}