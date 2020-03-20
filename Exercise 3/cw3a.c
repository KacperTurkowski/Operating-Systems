#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "cw3a.h"
int main(int argc, char *Argv[])
{
if(argc!=3)
	{
		printf("Bad arguments\n");
		exit(1);
	}
char choose;
choose=*Argv[1];
int number=atoi(Argv[2]);
switch(choose){
		case('i')://ignore signal
		signal_ignore(number);
		break;
		case('d'):
		signal_default(number);
		break;
		case('p'):
		signal_intercept(number);
		break;
		default:
		printf("Bad signal\n");
		exit(2);
	}
return 0;
}
