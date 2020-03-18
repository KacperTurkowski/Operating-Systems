//Kacper Turkowski
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define BLU "\x1B[34m"
#define GRN "\x1B[32m"
#define RESET "\x1B[0m"
#define PATH "./"

int main(int argc, char *argv[])
{
  if(argc!=2)
	{
		printf("Bad arguments");
		exit(1);
	}
  char PathName[100];
  sprintf(PathName,"%s%s",PATH,argv[1]);
  int c;
  printf("%sParent process:%s\n %s UID: %s %i \n %s GID: %s %i \n %s PID: %s %i \n %s PPID:%s %i \n %s PGID:%s %i \n \n \n",GRN,RESET,BLU,RESET,getuid(),BLU,RESET,getgid(),BLU,RESET,getpid(),BLU,RESET,getppid(),BLU,RESET,getpgrp());
  printf("%sChild process:%s \n \n",GRN,RESET);
  for(int i=0;i<=2;i++)
    {
      c=fork();
      switch(c)
	{
	case -1:
	  {
	    perror("error");
	    exit(2);
	  }
	case 0:
	  {
	    int b;
	    b=execl(PathName,argv[1],NULL);
	    if(b==-1){
		perror("error");
		_exit(4);
	      }
	    break;
	  }
	default:
	  {
	    int a;
	    a=wait(0);
	    if(a==-1)
	      {
		perror("error");
		exit(5);
	      }
	    break;
	  }
	}
    }
  return 0;

}
