#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define PATH "./"
int main(int argc, char *Argv[]){
if(argc!=3){
		printf("Bad arguments \n");
		exit(5);
	}
char PathName[100];
char name[98]="cw3a.x";
int number=atoi(Argv[2]);
sprintf(PathName,"%s%s",PATH,name);
int e=fork();
int status,i;
switch(e){
	case -1:
	{
		perror("Error");
		exit(6);
	}
	case 0:
	{
		int a;
		int c=getpid();
		printf("%d\n",c);
		setpgid(0,0);
		if(signal(number,SIG_IGN)==SIG_ERR){
			perror("Error");
			exit(11);
		}
		printf("Ignore signal:  %d \n",number);
		for(i=0;i<=2;i++){
			int d=fork();
			if(d<0){
				perror("Error");
				exit(6);
			}
			else if(d==0){
				status=getpid();
				printf("Process group: %d\n",getpgid(c));
				a=execl(PathName,"cw3a.x",Argv[1],Argv[2],NULL);
				if(a==-1){
					perror("Error");
					_exit(7);
				}
				break;
			}
		}
		for(int j=0;j<=2;j++){
			int wai=wait(&status);
			if(wai==-1){
					perror("Error");
					exit(11);
				}
			printf("Process PID: %d ended with status  %d \n",wai,status);
		}
		break;
	}
	default:
	{
		sleep(1);
		int check=kill(-e,0);
		if(check==-1){
			printf("Child process doesn't exist\n");
			exit(9);
		}
		int check1=kill(-e,number);
		if(check1==-1){
			perror("Error\n");
			exit(10);
		}
		wait(0);
		break;
	}
}
return 0;
}
