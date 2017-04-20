// file: twopipetwochildren.cpp
// // author: Brennan Stuewe
// purpose: search for number of lines that contain 3376 
// description: this program executes "ls -ltr | grep 3376 | wc -l", by dividing the two command among the child and parent process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <sys/wait.h>
#include <iostream>
int main(int argc, char **argv){
  int status;
  int child1, child2;
  char *cat_args[] = {"ls", "-ltr", NULL};
  char *grep_args[] = {"grep", "3376", NULL};// create one pipe to send the output of "ls" process to "grep" process
  char *wc_args[] = {"wc", "-l", NULL};
  int p1[2], p2[2];
  pipe(p1);//child 1 ls
  pipe(p2);
  if((child1 = fork()) == -1){
    perror("Error creating a child process");
    exit(1);
  }
  if (child1 == 0){//ls first child 
    dup2(p1[1], 1);//send to p1 write
    close(p1[1]);//close everything
    close(p1[0]);
    close(p2[1]);
    close(p2[0]);
    execvp(*cat_args, cat_args);//execute
    exit(0);
  }else{
    if((child2 = fork()) == -1){//second child grep
      perror("Error creating a child process");
      exit(1);
    }
    if (child2 == 0){
      dup2(p1[0], 0);//read p1, write p2
      dup2(p2[1],1);
      close(p1[1]);
      close(p1[0]);
      close(p2[1]);
      close(p2[0]);
      execvp(*grep_args, grep_args);//execute
      exit(0);
    }
  }
  dup2(p2[0],0);//read p2
  close(p1[1]);
  close(p2[1]);
  close(p1[0]);
  close(p2[0]);
  execvp(*wc_args, wc_args);

for(int x = 0;x <2;x++){
wait(&status);//wait for pipes to finish
}
  return(0);
}

//wc -l does not run, likely a problem with the parent grep area

//Change code to "ls -ltr | grep 3376 | wc -l"
//1- Use one parent and two children, TwoPipesTwoChildren.cpp.
//2- parent create 3 children, and the children will execute the
//commands (parent will do nothing, file TwoPipesThreeChildren.cpp
