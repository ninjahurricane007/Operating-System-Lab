#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main()
{
int i;
void *shared_memory;
int shmid;
char buff[100];
shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
printf("Key of shared memory: %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("Process attached to %p\n",shared_memory);
printf("Enter data to write in shared memory\n");
read(0,buff,100);
strcpy(shared_memory,buff);
}