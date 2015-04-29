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

int msgQId;
static void hd1 (int someRandomVar){
	int retFromMsgctl;
	struct msqid_ds *myq;
	retFromMsgctl = msgctl(msgQId, IPC_RMID, myq);
	if(retFromMsgctl<0){
		printf("Error in retFromMsgctl!\n");
		exit(0);
	}
}
int main()
{
	struct sigaction act;
	int retFromMsgsnd, retFromSignal;
	char msgp[25] = "Have you received this?";
	int key = 1234;
	msgQId = msgget(key, IPC_CREAT);

	act.sa_handler = hd1;
	sigemptyset(&act.sa_mask);
	printf("%d\n", msgQId);

	if(msgQId<0){
		printf("Error in msgqid!\n");
		exit(0);
	}

	retFromSignal = sigaction(SIGUSR2, &act, NULL);	
	retFromMsgsnd = msgsnd(msgQId, msgp, 100, IPC_NOWAIT);	
	

	if(retFromSignal<0){
			printf("Error in sigaction!\n");
			exit(0);
		}

	printf("%d\n", retFromMsgsnd);
	return 0;

}