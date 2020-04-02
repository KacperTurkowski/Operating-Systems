#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZE 10
void readfromfile(char *in,char array[],const char *fifo){
int op,errorread,errorwrite;
	op = open(in, O_RDONLY);
	if(op==-1){
		perror("Error");
		exit(1);
		}
	errorwrite = open(fifo, O_WRONLY);
	if(errorwrite == -1){
		perror("Error");
		exit(2);
	}
	while((errorread = read(op,array,SIZE))>0){
			printf("READ:\n");
			sleep(1);
			if(write(1,array,errorread)==-1){
				perror("Error");
				exit(3);
				}
			printf("\n");
			if(write(errorwrite,array,errorread)==-1){
			perror("Error");
			exit(4);
			}
		sleep(1);
		};
	if(-1==close(op)){
			perror("Error");
			exit(5);
		}
	if(-1==close(errorread)){
			perror("Error");
			exit(6);
		}
}
void save(char *out, char array[], const char *fifo){
int op,errorread,errorwrite;
	op=open(out, O_CREAT | O_TRUNC | O_WRONLY | O_APPEND,0);
	if(op==-1){
		perror("Error");
		exit(7);
	}
	errorwrite = open(fifo, O_RDONLY, 0);
	if(errorwrite == -1){
		perror("Error");
		exit(8);
	}
	while((errorread = read(errorwrite,array,SIZE))>0){
		printf("SAVE:");
		sleep(1);
		printf("\n");
		if(write(1,array,errorread)==-1){
			perror("Error");
			exit(9);
			}
		printf("\n");
		if(write(op,array,errorread)==-1){
			perror("Error");
			exit(10);
		}
		sleep(2);
	}
	if(-1 == close(op)){
		perror("Error");
		exit(11);
	}
	if(-1 == close(errorwrite)){
		perror("Error");
		exit(12);
	}
	if(unlink(fifo) == -1){
		perror("Error");
		exit(13);
	}
}
