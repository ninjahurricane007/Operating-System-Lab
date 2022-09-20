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
shmid=shmget((key_t)2345,1024,0666);
shared_memory=shmat(shmid,NULL,0);
printf("Data in shared memory: %s",(char*)shared_memory);
}