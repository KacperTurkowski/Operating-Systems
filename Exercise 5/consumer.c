#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define SIZE 8
#define FIFO "./fifo"
int main(int argc, char *Argv[])
{
    if(argc!=2)
    {
        printf("Bad arguments\n");
        exit(1);
    }
    printf("Consumer\n");
    char *out;
    char array[SIZE];
    out = Argv[1];
    int oo,of,or;
    printf("Save do out file\n");
    oo=open(out,O_CREAT | O_TRUNC | O_WRONLY | O_APPEND,0);
    if(oo==-1){
        perror("Error");
        exit(2);
    }
    of=open(FIFO,O_RDONLY,0644);
    if(of==-1){
        perror("Error");
        exit(3);
    }
    sleep(3);
    while((or=read(of, array, SIZE))>0){
        if(write(1, array, or)==-1){
            perror("Error");
            exit(4);
        }
        printf("\n");
        if(write(oo, array, or)==-1){
            perror("Error");
            exit(5);
        }
        sleep(2);
    }
    if(or==-1){
        perror("Error");
        exit(6);
    }
    if(-1==close(oo)){
        perror("Error");
        exit(7);
    }
    if(-1==close(of)){
        perror("Error");
        exit(8);
    }
    if(unlink(FIFO)==-1){
        perror("Error");
        exit(9);
    }
}
