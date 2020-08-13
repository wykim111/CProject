#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/msg.h>

struct mymsgbuf{

	long mtype;
	char mtext[80];
};



int main()
{
	key_t key;
	int msgid;
	struct mymsgbuf mesg;

	key=ftok("/home/wykim/IPC/MQ/ex10-1.c",1);
	msgid = msgget(key,IPC_CREAT|0644);

	if(msgid == -1)
	{
		perror("msgget");
		exit(1);
	}

	mesg.mtype = 1;
	strcpy(mesg.mtext, "Message Q Test\n");

	if(msgsnd(msgid,(void*)&mesg,80,IPC_NOWAIT) == -1)
	{
		perror("msgsnd");
		exit(1);
	}

	return 0;
}
