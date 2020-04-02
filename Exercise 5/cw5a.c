#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "cw5a.h"
#include <unistd.h>
#define FIFO "./fifo"

int main(int argc, char *Argv[])
{
if(argc!=3)
	{
		printf("Bad arguments\n");
		exit (0);
	}
char *in = Argv[1];//file from which text is copied
char *out = Argv[2];//file where text is pasted
char array[10];
if(mkfifo(FIFO, 0644)==-1){
	perror("Error");
	exit(1);
	}
int k = fork();
switch(k){
	case -1:
		perror("Error");
		exit(2);
	case 0:
		save(out,array,FIFO);
		break;
	default:
		readfromfile(in,array,FIFO);
		break;
	}
return 0;
}
