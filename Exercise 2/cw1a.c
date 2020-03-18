// KACPER TURKOWSKI
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#define BLU "\x1B[34m"
#define RESET "\x1B[0m"
int main()
{
  int a,b,c,d,e;
  a=getuid();//UID
  b=getgid();//GID
  c=getpid();//PID
  d=getppid();//PPID
  e=getpgrp();//PGID
  printf(" %s UID: %s %i \n %s GID: %s %i \n %s PID: %s %i \n %s PPID:%s %i \n %s PGID:%s %i \n \n \n",BLU,RESET,a,BLU,RESET,b,BLU,RESET,c,BLU,RESET,d,BLU,RESET,e);
  return 0;
}
