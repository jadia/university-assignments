#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

pid_t pid;

void triedToKill(int sig)
{
	printf("\n Did you tried to kill me? %d \n", getpid());
	exit(1);
}

void triedToQuit(int sig)
{
	printf("\n I tried using Quit! \n");
	exit(1);
}

void main()
{
	signal(SIGINT,triedToKill);
	signal(SIGQUIT,triedToQuit);
	pid = fork();
	
	if(pid == 0) // child runs this
	{	
		sleep(3);
		printf("I'm a child. Pid: %d \n",getpid());
		printf("My papa pid: %d \n", getppid());
	}
	else if (pid > 0) // parent runs this
	{
//		kill(pid,SIGQUIT);
		printf("I'm a parent. Pid: %d \n",getpid());
		sleep(100);
	}
	else if (pid < 0)
		printf("Not able to create child.");
}
