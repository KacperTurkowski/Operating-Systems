#include <unistd.h>
#include <stdio.h>
#include "cw3a.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void intercept(int number)
{
        printf("Signal %d intercept \n",number);
}
void signal_default(int number){
	printf("Default \n");
	if(signal(number, SIG_DFL)==SIG_ERR){
		perror("Error: \n");
		exit(1);
	}
	pause();
}
void signal_ignore(int number)
{
	printf("Ignore\n");
	if(signal(number, SIG_IGN)==SIG_ERR){
		perror("Error: \n");
		exit(1);
	}
	printf("Signal Ignore \n");
	pause();
}
void signal_intercept(int number)
{
	printf("Interept\n");
	if(signal(number,&intercept)==SIG_ERR){
	perror("Error: \n");
	exit(2);
	}
	printf("Signal intercept\n");
	pause();
}
