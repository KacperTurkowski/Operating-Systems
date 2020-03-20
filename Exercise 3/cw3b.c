#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define PATH "./"
int main(int argc, char *Argv[])
{
if(argc!=3)
	{
		printf("Bad arguments\n");
		exit(5);
	}
char PathName[100];
char name[98]="cw3a.x";
int number=atoi(Argv[2]);
sprintf(PathName,"%s%s",PATH,name);
int e=fork();
switch(e){
	case -1:
	{
		perror("Error");
		exit(6);
	}
	case 0:
	{
		int a,b;
		b=getpid();
		printf("%d\n",b);
		a=execl(PathName,"cw3a.x",Argv[1],Argv[2],NULL);
		if(a==-1)
		{
			perror("Error");
			_exit(7);
		}
		break;
	}
	default:
		{
			sleep(5);
			int check=kill(e,0);
			if(check==-1)
			{
				printf("Child Process doesn't exist \n");
				exit(9);
			}
			check=kill(e,number);
			if(check==-1)
			{
				perror("Error");
				exit(10);
			}
			wait(0);
			break;
	}
}
return 0;
}
