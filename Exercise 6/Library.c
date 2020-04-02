#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

void creating(const char *name,int value){
    sem_t *sem;
    sem=sem_open(name, O_CREAT, 0644, value);
    if(sem==SEM_FAILED){
        perror("Error");
        exit(1);
    }
}
sem_t* opening(const char *name){
    sem_t *sem;
    sem=sem_open(name,O_CREAT);
    if(sem==SEM_FAILED){
        perror("Error");
        exit(2);
    }
    return sem;
}
void  value(sem_t *sem){
    int amount;
    int *sval = &amount;
    if((sem_getvalue(sem,sval))==-1){
        perror("Error");
        exit(3);
    }
    printf("Value of Semaphore is: %d \n", amount);
}
void up(sem_t *sem){
    int error;
    error=sem_post(sem);
    if(error==-1){
        perror("Up error");
        exit(4);
    }
}
void down(sem_t *sem){
    int error;
    error=sem_wait(sem);
    if(error==-1){
        perror("Down error");
        exit(5);
    }
}
void closing(sem_t *sem){
    int error;
    printf("Close semaphore \n");
    error=sem_close(sem);
    if(error==-1){
        perror("Close error");
        exit(6);
    }
}
void deleting(const char *name){
    printf("deleting semaphore \n");
    if(sem_unlink(name)==-1){
        perror("Delete error");
        exit(7);
    }
}
