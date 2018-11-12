#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

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
	signal(SIGQUIT,SIG_IGN);

	/*
  ### Shared memory section ###
  */

  //ftok creates a code depending upon actual file and the number you provide.
  key_t key = ftok("/dev/null", 1995);
  //create shared memory, if already there give 0666 permission.
  int shmid = shmget(key, BUFSIZ, 0666 | IPC_CREAT);
  //attach shared memory.
  pid_t *str = (pid_t*) shmat(shmid, NULL, 0);

	*str = getpid();
	while(1);

}
