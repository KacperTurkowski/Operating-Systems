#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#define RED "\x1B[34m"
#define RESET "\x1B[0m"
int main()
{
  int i;
  int child;
  printf("Parent Process:%s PID %s %d %s PPID %s %d %s  UID %s %d %s GID %s  %d %s PGID %s  %d \n",RED,RESET,getpid(),RED,RESET,getppid(),RED,RESET,getuid(),RED,RESET,getgid(),RED,RESET,getpgrp());
  for(i=0;i<=2;i++)
    {
      child=fork();
      switch(child)
	{
	case -1:
	  {
	    perror("error");
	    exit(1);
	  }
	case 0:
	  {
	    printf("Child process:%s PID %s %d %s PPID %s %d %s  UID %s %d %s GID %s  %d %s PGID %s  %d \n",RED,RESET,getpid(),RED,RESET,getppid(),RED,RESET,getuid(),RED,RESET,getgid(),RED,RESET,getpgrp());
	    break;
	  }
	default:
	  {
	    waitpid(0,NULL,0);
	    break;
	  }
	}
    }
  return 0;
}
