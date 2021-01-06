#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main()
{
	key_t key;
	int shmid;

	key=ftok("home/ubuntu/IPC/Sham/ex10-4.c",1);

	shmid=shmget(key,1024,IPC_CREAT|0644);

	if(shmid == -1)
	{
		perror("shmget");
		exit(1);
	}

	return 0;
}
