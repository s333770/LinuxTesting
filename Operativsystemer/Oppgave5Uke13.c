#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

int i,id,pid,mypid,ppid;
id = getpid();
printf ("Fork demo!\n Jeg er parent-prosess med pid = %d \n",id);
sleep(2);
pid = fork();     /* Prosessen lager nå en ny uavhengig prosess
                     I den nye barne-prosessen er $pid = 0
                     I foreldre prosessen er $pid = barnets PID */
if (pid == 0)
  {
    mypid = getpid();
    ppid  = getppid();
    printf("       Jeg er child (mypid = %d) av parent med pid = %d.\n",mypid,ppid);
    printf("       Here er variabelen pid = %d.\n",pid);
    for (i = 1;i < 10;i++)
      {
        printf("       %d \n",i);
        sleep(1);
      }
    printf("       Child prosess avslutter.\n");
    exit(0);
  } 
else
  {
    sleep(2);
    printf("Parent %d venter på child %d her...\n",id,pid);
    wait(&pid); 
    printf("Child har avsluttet, Parent avslutter!\n");
  }

}
