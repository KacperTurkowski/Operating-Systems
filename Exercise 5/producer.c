#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZE 10
#define FIFO "./fifo"

int main(int argc,char *Argv[])
{
    if(argc!=2){
        printf("Bad arguments\n");
        exit(1);
    }
    printf("PRODUCER\n");
    char array[SIZE];
    char *in = Argv[1];
    int oi,of,or;
    oi=open(in,O_RDONLY,0);
    if(oi==-1){
        perror("Error");
        exit(2);
    }
    of=open(FIFO,O_WRONLY,0);
    if(of==-1){
        perror("Error");
        exit(3);
    }
    printf("Save in FIFO: \n");
    sleep(1);
    while((or=read(oi, array, SIZE))>0){
        if(write(1, array, or)==-1){
            perror("Error");
            exit(4);
        }
        printf("\n");
        if(write(of, array, or)==-1){
            perror("Error");
            exit(5);
        }
        sleep(1);
    };
    if(or==-1){
        perror("Error");
        exit(6);
    }
    if(-1==close(oi)){
        perror("Error");
        exit(7);
    }
    if(-1==close(or)){
        perror("Error");
        exit(8);
    }
}
