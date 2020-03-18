#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#define BLU "\x1B[34m"
#define RESET "\x1B[0m"

void process()
{
  printf("%sPID%s %i %sPPID%s %i %sPGID%s %i \n",BLU,RESET,getpid(),BLU,RESET,getppid(),BLU,RESET,getpgrp());
}
int main()
{
  int i=0;
  process();
  do{
    switch( fork() ) {
    case -1 :
      perror("error") ;
      exit(EXIT_FAILURE) ;
      break;
    case 0 :
      setpgid(0,0);//function set pgid, child process is lider of group
      process();
      sleep(2);
      break ;
    default :
      break ;
    }
    i++;
  }while(i<3);
  sleep(5);
  return 0;
}
