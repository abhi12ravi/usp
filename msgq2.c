#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
	int msgQId, retFromRcv, retFromCtl;
	int key = 1234;
	char receivedMsg[100];
	struct msqid_ds myq;
	pid_t pid_sender;

	//int *ptrmq = &myq;
	msgQId = msgget(key, 0666);
	printf("%d\n", msgQId);

	if(msgQId<0){
		printf("Error in msgqid!\n");
		exit(0);
	}

	retFromRcv  = msgrcv(msgQId, receivedMsg, 100, 0, IPC_NOWAIT);
	printf("%d\n", retFromRcv);
	printf("%s\n", receivedMsg);

	if(retFromRcv<0){
		printf("Error in retFromRcv!\n");
		exit(0);
	}

	retFromCtl = msgctl(msgQId, IPC_RMID, &myq);
	printf("%d\n", retFromCtl);

	if(retFromCtl<0){
		printf("Error in retFromCtl!\n");
		exit(0);	
	}

	pid_sender = myq.msg_lspid;
	printf("%d\n",pid_sender);
	kill(pid_sender, SIGUSR2);

	return 0;
}