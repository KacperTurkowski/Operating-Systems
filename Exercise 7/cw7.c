#define WPROD 1
#define WKONS 1
#define SIZE 4
#include "Library.h"
#define BLU "\x1B[31m"
#define RED "\x1B[34m"
#define RESET "\x1B[0m"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
int main(){
    int length=NELE;
    int descriptor;
    int insert=0;
    int remove =0;
    const char *name=NAME;
    descriptor=openSM(name, SIZE * sizeof(Commodity));
    const char *prod=PROD;
    const char *kons=CONS;
    sem_t* sem1=NULL;
    sem_t* sem2=NULL;
    sem1=creating(prod,NELE);
    sem2=creating(kons,0);
    char *in="in";
    char *out="out";
    int e=fork();
    switch(e){
        case -1:
            perror("Fork Error");
            exit(1);
        case 0:
            producer(sem1, sem2, length, in, descriptor, insert);
            break;
        default:
            sleep(1);
            consumer(sem1, sem2, length, out, descriptor, remove);
            deleting(prod);
            deleting(kons);
            deleteSM(name);
            break;
    }
    return 0;
}
void producer(sem_t* sem1, sem_t* sem2, int length, char *in, int descriptor, int insert){
    Commodity *wpd = (Commodity *)projectionSM(descriptor, SIZE * sizeof(Commodity));
    Commodity commodityProd;
    int op=0;
    wpd->licz=1;
    if((op=open(in,O_RDONLY,0))==-1){
        perror("Open function error");
        exit(2);
    }
    int or=0;
    while((or=read(op, commodityProd.bufor, NELE))>0){
        printf("PRODUCER\n");
        down(sem1);
        printf("Save: \n");
        printf("%d \n",or);
        if(write(1, commodityProd.bufor, or)==-1){
            perror("Write Error");
            exit(3);
        }
        printf("\n");
        *(wpd + insert)=commodityProd;
        wpd->licz=1;
        wpd->dl=or;
        insert= (insert + 1) % SIZE;
        sleep(2);
        up(sem2);
    }
    wpd->licz=0;
    closing(sem1);
}
void consumer(sem_t* sem1, sem_t* sem2, int length, char *out, int descriptor, int remove){
    Commodity *wpd = (Commodity *)projectionSM(descriptor, SIZE * sizeof(Commodity));
    Commodity commodityCons;
    int op;
    if((op=open(out,O_WRONLY))==-1){
        perror("File Open Error");
        exit(4);
    }
    int a;
    while((wpd->licz)!=0){
        printf("CLIENT\n");
        down(sem2);
        commodityCons=*(wpd + remove);
        printf("READ\n");
        a=write(1, commodityCons.bufor, wpd->dl);
        printf("\n");
        if(a==-1){
            perror("Error");
            exit(9);
        }
        if(write(op, commodityCons.bufor, wpd->dl) == -1){
            perror("Error");
            exit(5);
        }
        remove = (remove + 1 ) % SIZE;
        sleep(2);
        up(sem1);
    }
   if( sem_close(sem2)==-1){
	perror("Error");
	exit(6);
	};
}

