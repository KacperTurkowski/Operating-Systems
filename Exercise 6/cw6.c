#include <stdio.h>
#include <unistd.h>
#include "Library.h"
#include <sys/wait.h>
#include <stdlib.h>

#define PATH "./"

int main(int argc,char *argv[]){
	if(argc!=4){
	printf("Bad arguments \n");
	exit(0);
	}
	char PathName[100];
	sprintf(PathName,"%s%s",PATH,argv[1]);
	int amount_of_process=atoi(argv[2]);
	int value = 1;
	creating(NAME, value);
	for(int i=0; i <= amount_of_process; i++){
		printf("Open process number: %d \n",i+1);
		switch(fork()){
			case -1:
				perror("Fork error");
				exit(1);
			case 0:
				if((execl(PathName,argv[1],argv[3],NAME,NULL))==-1){
					perror("Execl error");
					exit(2);
				}
		}
		sleep(1);
	}
	for(int j=0; j <= amount_of_process; j++){
		wait(NULL);
	}
	sleep(2);
	deleting(NAME);
	return 0;
}

