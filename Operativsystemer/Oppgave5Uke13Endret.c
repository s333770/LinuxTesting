#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(){
	int i,pid,pid2, id,mypid,ppid;
	id=getpid();
	printf("Fork demo! \n Jeg er parent prosess med pid= %d \n",id);
	pid=fork();
	if(pid==0){
		mypid=getpid();
		ppid=getppid();
		printf("Jeg er child med id %d, parentid er: %d \n", mypid,ppid); 
		printf("Variabelen pid er: %d \n",pid);
		sleep(5);
		pid2=fork();
		if(pid2==0){
			ppid=getppid();
			printf("Jeg er child av parent med pid %d \n", ppid);
			sleep(5);
			printf("Grandchild Avslutter\n");
			exit(0);
		}
		else{
			printf("Parent venter på child %d \n",pid2);
			wait(&pid2);
			printf("Grandchild ferdig, avslutter parent\n");
			exit(0);
		}


	}
	else{
		printf("Parent venter på %d \n",pid);
		wait(&pid);
		exit(0);
	}




}	
