#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#define NAME "/name"

void creating(const char *name,int wartosc);
sem_t* opening(const char *name);
void value(sem_t*);
void up(sem_t*);
void down(sem_t*);
void closing(sem_t*);
void deleting(const char *name);
