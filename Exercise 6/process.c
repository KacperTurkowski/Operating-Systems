#include "Library.h"
int main(int argc,char *argv[]){
    int critamount=atoi(argv[1]);
    sem_t *sem=NULL;
    printf("Open semaphore\n");
    sem=opening(argv[2]);

    for(int i=0; i < critamount; i++){
        up(sem);
        value(sem);
        down(sem);
        value(sem);
        printf("Loop %d \n",i);
    }
    closing(sem);
}
