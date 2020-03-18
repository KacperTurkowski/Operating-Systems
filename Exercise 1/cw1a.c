#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  int a,b,c,d,e;
  a=getuid();
  b=getgid();
  c=getpid();
  d=getppid();
  e=getpgrp();
  printf("UID:%i \n GID:%i \n PID:%i \n PPID:%i \n PGID:%i \n",a,b,c,d,e);
  return 0;
}
