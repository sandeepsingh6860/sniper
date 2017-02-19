#include<stdio.h>
#include<semaphor.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

sem_t chopstick[5];
pthread_t philosopher[5];
sem_t room;

void *func(void*n)
{
	int n1=(int)n;
	printf("\nPHILOSOPHER %d IS THINKNG\n",n1+1);
	sleep(5);
	sem_wait(&room);
	printf("\nPHILOSOPHER %d IS HUNGRY\n",n1+1);
	sem_wait(&chopstick[n1]);
	sem_wait(&chopstick[(n1+1)%5]);
	printf("\nPHILOSOPHER %d IS EATING\n",n1+1);
	sleep(5);
    sem_post(&chopstick[n1]);
    sem_post(&chopstick[(n1+1)%5]);
    printf("\nPHILOSOPHER %d HAS FINISHED EATING\n",n1+1);
    sem_post(&room);
    pthread_exit("HI THIS IS WORKING FREAKING AWESOME");
}
int main()
{
	int i,k;
	void*msg;

	sem_init(&room,0,4);

	for(i=0;i<5;i++)
	{
      k=pthread_create(&philosopher[i],NULL,func,(void*)i);
      sleep(1);
      if(k!=0)
      {
        printf("\nTHREAD INITILISATION FAILED\n");
        exit(1);
      }
	}
    for(i=0;i<5;i++)
    {
      k=sem_init(&chopstick[i],0,1);
      if(k==-1)
      {
        printf("\nSEMAPHOR INITIALISATION FAILED\n");
        exit(1);
      }
    }
   for(i=0;i<5;i++)
   {
    k=pthread_join(&philosopher[i],&msg);
    if(k!=0)
    {
     printf("\nTHREAD JOIN FAILED\n");
    }
    else
    printf("%s",msg);
   }
}