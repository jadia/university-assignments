#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/types.h>
#include <signal.h>

void main()
{

	/*
  ### Shared memory section ###
  */

  //ftok creates a code depending upon actual file and the number you provide.
  key_t key = ftok("/dev/null", 1995);
  //create shared memory, if already there give 0666 permission.
  int shmid = shmget(key, BUFSIZ, 0666 | IPC_CREAT);
  //attach shared memory.
  pid_t *str = (pid_t*) shmat(shmid, NULL, 0);

	pid_t pid = *str;
	kill(pid,SIGINT);
}
