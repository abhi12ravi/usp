/* Write a daemon process in C language using relevant system calls. The daemon process has to write a syslog message once in 5 seconds.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <syslog.h>

int main(){
	int pid;
	pid_t sid=0;
	FILE* fp=NULL;

	pid = fork();
	printf("%d\n",pid );
	if(pid<0){
		printf("Fork failed\n");
		exit(1);
	}
	else if(pid>0){
		printf("Parent process\n");
		exit(0);
	}
	else { //Child process instructions where pid = 0
		//set the umask value for new files getting created
		umask (0);
		//start new session
		sid = setsid();

		chdir("/"); // change pwd to root

		//close all file descriptors - fd0, fd1 and fd2
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);

		fp = fopen("log.txt", "w+");
		while(1) {
			//Actual daemon function - runs in background
			sleep (5);
			fprintf(fp, "I slept for 5 seconds...\n");
			fflush(fp);

			//Writing to SYSLOG
			openlog("abhilog", LOG_PID, LOG_USER);
			sleep (5);
			syslog(LOG_INFO, "I slept for 5 seconds..!");
			closelog();			
		}
		fclose(fp);
		return 0;
	}
}
/* USAGE instructions
$cc daemon_test.c
$sudo ./a.out
$tail -f /log.txt [CUSTOM LOG]
$tail -f /var/log/syslog [SYSLOG]
*/