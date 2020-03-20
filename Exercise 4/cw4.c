#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "cw4.h"

int main(int argc, char *Argv[]){
if(argc!=3){
		printf("Bad argumnets \n");
		exit(1);
	}
char *in = Argv[1];
char *out = Argv[2];
int descriptor[2];
char array[10];
if(pipe(descriptor)== -1){
	perror("Error");
	exit(2);
}
switch (fork()) {
	case -1:
		perror("Error");
		exit(2);
	case 0:
		Saving(out,array,descriptor);
		break;
	default:
		Reading(in,array,descriptor);
		break;
	}
return 0;
}
