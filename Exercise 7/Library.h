#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#define PROD "/producer1"
#define CONS "/consumer"
#define NELE 5
#define NAME "/Memory"
void producer();
void consumer();
sem_t* creating(const char*,int);
sem_t* opening(const char*);
void up(sem_t*);
void down(sem_t*);
void closing(sem_t*);
void deleting(const char*);
typedef struct{
	int licz;
	int dl;
	char bufor[NELE];
}Commodity;
void deleteSM(const char*);
void closeSM(int);
int openSM(const char*,int);
int* projectionSM(int,int);
void value(sem_t*);

