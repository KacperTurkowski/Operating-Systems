#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#define SIZE 10
void Reading(char *in,char array[], int descriptor[]){
	int op, r;
	time_t tt;
	r = time(&tt);
	srand(r);
	int or,k;
	k=rand()%10;
	if(-1 == close(descriptor[0])){
		perror("Error");
		exit(3);
	}
	op = open(in, O_RDONLY);
	if(op==-1){
		perror("Error");
		exit(4);
	}
	while ((or=read(op, array ,SIZE))>0){
		if(or==-1){
			perror("Error");
			exit(5);
		}
		if(write(descriptor[1], array, or)==-1){
			perror("Error");
			exit(6);
		}
		sleep(k);
	};
	if(-1==close(op)){
		perror("Error");
		exit(7);
	}
	if(-1==close(descriptor[1])){
		perror("Error");
		exit(8);
	}
}
void Saving(char *in,char array[], int descriptor[]){
int op,random;
time_t tt;
random = time(&tt);
srand(random);
int k;
k=rand()%10;
int w,r;
	if(-1==close(descriptor[1])){
		perror("Error");
		exit(9);
	}
	op=open(in,O_TRUNC|O_WRONLY|O_CREAT|O_APPEND,0);
	if(op==-1){
		perror("Error");
		exit(10);
		}
	printf("Saved: \n");
	while((r=read(descriptor[0],array,SIZE)) >0){
		if(write(1,array,r)==-1){
			perror("Error");
			exit(11);
			}
		printf("\n");
		if((w=write(op,array,r))==-1){
			perror("Error");
			exit(12);
		}
		sleep(k);
	}
	if(-1==close(op)){
		perror("Error");
		exit(12);
		}
	if(-1==close(descriptor[0])){
		perror("Error");
		exit(13);
		}
}
