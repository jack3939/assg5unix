// file: dynpipe
// author: Brennan Stuewe
// purpose: CS3376
// description: this program executes "ls -ltr | grep 3376" dynamicaly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
int main(int argc, char **argv){
  int status;
  int id;
  char *cat_args[] = {"ls", "-ltr", NULL};
  char *grep_args[] = {"grep", "3376", NULL};// create one pipe to send the output of "ls" process to "grep" process
  int dynpipe[2];
  return(0);
}
//2- The piped commands to execute need to be passed as arguments to dynpipe,and not hardcoded.
//3- The max number of arguments should not exceed 5, and not less than 2 (otherwise print an error
//message)
//4- Each argument should be a unix/linux command with its parameters. The first argument will be the
//first to execute, followed by the second one, etc.. We will assume that only valid commands can be
//used, for simplicity
