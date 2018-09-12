#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void forking(int);

int main(void){
    
   forking(3);
   forking(5);
   
   return 0;
}

void forking(int n){ 
int i;

for(i=0; i<n;i++){
    
  int pid = fork();

  if(pid == 0)
  {
    printf("I am the child process and pid is %d! \n",(int)getpid());
    printf("pid of parent is %d\n", (int)getppid());
  }
  else if(pid == -1)
  {
   printf("fork() failed\n");
  }
  else
  {
    int status;
    wait(&status);
    printf("\n Hello I am the parent process ");
    printf("\n My actual pid is %d, pid of my child is %d\n ",(int)getpid(), pid);
    exit(1);}
  }
  sleep(15);
    
}