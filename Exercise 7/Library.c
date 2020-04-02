#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>

sem_t* creating(const char *name,int value){
    sem_t *sem;
    sem=sem_open(name, O_CREAT, 0644, value);
    printf("%s %d\n", name, value);
    if(sem==SEM_FAILED){
        perror("Creating semaphore Error");
        exit(1);
    }
    return sem;
}
sem_t* otwieranie(const char *name){
    sem_t *sem;
    sem=sem_open(name,0);
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
    printf("Value of semaphore is: %d \n", amount);
}
void up(sem_t *sem){
    int error;
    error=sem_post(sem);
    if(error==-1){
        perror("Up error");
        exit(3);
    }
}
void down(sem_t *sem){
    if((sem_wait(sem))==-1){
        perror("Down Error");
        exit(4);
    }
}
void closing(sem_t *sem){
    int error;
    error=sem_close(sem);
    printf("Close Semaphore\n");
    if(error==-1){
        perror("close error");
        exit(5);
    }
}
void deleting(const char *name){
    printf("Delete Semaphore\n");
    if(sem_unlink(name)==-1){
        perror("Delete error");
        exit(7);
    }
}
int openSM(const char *name,int length){
    printf("Create share memory\n");
    int descriptor;
    descriptor=shm_open(name, O_CREAT | O_RDWR, 0666);
    if(-1 == descriptor){
        perror("shm_open Error");
        exit(8);
    }
    int error;
    error=ftruncate(descriptor, length);
    if(-1==error){
        perror("Ftruncate Error");
        exit(9);
    }
    return descriptor;
}
void deleteSM(const char *name){
    int error;
    printf("Delete SM\n");
    error=shm_unlink(name);
    if(error==-1){
        perror("shm_unlink error");
        exit(10);
    }
}
void closeSM(int descriptor){
    int error;
    printf("Close SM\n");
    error=close(descriptor);
    if(error==-1){
        perror("Close SM error");
        exit(11);
    }
}
int* projectionSM(int descriptor, int length){
    int *map =(int *)mmap(NULL, length, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_SHARED, descriptor, 0);
    if(map==MAP_FAILED){
        perror("Error");
        exit(12);
    }
    return map;
}
