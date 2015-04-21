/*
USAGE: $./a.out -o pid $./a.out -o uid $./a.out -o pgid $./a.out -o uid  $./a.out -o sid
	And combinations of the above
*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
int main(int argc, char**argv)
{
	if(argc>=3)
	{
		if(strcmp(argv[2],"pid")==0)
		{			
			printf("My parent's ID: %d\n", getppid());
			printf("My process ID : %d\n", getpid());
		}
		if(strcmp(argv[2],"uid")==0)
		{			
			printf("My parent's UID: %d\n", getuid());
			printf("My process UID : %d\n", getuid());
		}
		if(strcmp(argv[2],"pgid")==0)
		{			
			printf("My parent's GID: %d\n", getgid());
			printf("My process GID : %d\n", getgid());
		}
		if(strcmp(argv[2],"sid")==0)
		{
			printf("My parent's SID: %d\n", getsid(getppid()));
			printf("My process SID : %d\n", getsid(getpid()));
		}
		if(strcmp(argv[2],"pid,uid")==0 || strcmp(argv[2],"uid,pid")==0)
		{
			printf("My parent's ID: %d\n", getppid());
			printf("My process ID : %d\n", getpid());
			printf("My parent's UID: %d\n", getuid());
			printf("My process UID : %d\n", getuid());
		}
		if(strcmp(argv[2],"pid,ppid")==0 ||strcmp(argv[2],"pid,ppid")==0)
		{
			printf("My parent's ID: %d\n", getppid());
			printf("My process ID : %d\n", getpid());
		}
		if(strcmp(argv[2],"pid,sid")==0 ||strcmp(argv[2],"sid,pid")==0)
		{
			printf("My parent's ID: %d\n", getppid());
			printf("My process ID : %d\n", getpid());
			printf("My parent's SID: %d\n", getsid(getppid()));
			printf("My process SID : %d\n", getsid(getpid()));
		}
		if(strcmp(argv[2],"pid,gid")==0 ||strcmp(argv[2],"pid,gid")==0)
		{
			printf("My parent's ID: %d\n", getppid());
			printf("My process ID : %d\n", getpid());
			printf("My parent's GID: %d\n", getgid());
			printf("My process GID : %d\n", getgid());
		}
		if(strcmp(argv[2],"sid,gid")==0 ||strcmp(argv[2],"sid,gid")==0)
		{
			printf("My parent's SID: %d\n", getsid(getppid()));
			printf("My process SID : %d\n", getsid(getpid()));
			printf("My parent's GID: %d\n", getgid());
			printf("My process GID : %d\n", getgid());
		}

		if(strcmp(argv[2],"pid,ppid,pgid,sid,uid")==0 || strcmp(argv[2],"ppid,pid,pgid,sid,uid")==0 )
		{
			printf("My parent's ID: %d\n", getppid());
			printf("My process ID : %d\n", getpid());
			printf("My parent's SID: %d\n", getsid(getppid()));
			printf("My process SID : %d\n", getsid(getpid()));
			printf("My parent's GID: %d\n", getgid());
			printf("My process GID : %d\n", getgid());
			printf("My parent's UID: %d\n", getuid());
			printf("My process UID : %d\n", getuid());
		}

	}
	return 0;
}
