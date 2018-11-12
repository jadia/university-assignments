/*
Q1: Write a C/C++ program that creates two processes, a parent and a child where the child is
created via the fork() system call. The parent reads the content of a file - which contains roll number
and mark, separated by a blank space. Find out the number of students who secured more than
average mark and send them to child via Inter process communication (IPC). The child receives the

data sent by the parent and writes it to another file together with an additional field (Equal / Above-
average or Less-than-average).

Hint: You can use any one of the IPC mechanism like UNIX/LINUX pipes, Shared memory or
Message queue.

Example inputFile.txt
5
1 10
2 20
3 30
4 40
5 50
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define inputFile "inputFile.txt"

void main()
{

  int pipefd[2]; // pipe file pointer
  FILE *fp;
  /*Opening file*/
  if((fp = fopen(inputFile, "r")) == NULL)
  {
    perror("Input: ");
    exit(1);
  }

  if(!pipe(pipefd))
  {
    pid_t fork_result;
    // forking
    fork_result = fork();
    if(fork_result == -1)
    {
      printf("Failed to fork!\n");
      exit(1);
    }
    if(fork_result == 0) // child will run this
    {
      //sleep(1); // make sure that parent runs first
      // declaring buffer
      int n, average;
      read(pipefd[0], &n, sizeof(n));
      int rollno[n];
      read(pipefd[0], rollno, sizeof(rollno));
      int marks[n];
      read(pipefd[0], marks, sizeof(marks));
      read(pipefd[0], &average, sizeof(average));
      printf("Average marks: %d.\n",average);

      // ### Printing list of students ###
      int i;
      for(i = 0; i < n; i++)
      {
        printf("Roll no: %d with marks: %d ", rollno[i], marks[i]);
        if(marks[i] == average)
        printf("is equal to average. \n");
        else if(marks[i] > average)
        printf("is greater than average. \n");
        else if(marks[i] < average)
        printf("is less than average. \n");
      }
    }
    else // parent runs this
    {
      /*Reading file to buffer*/
      int n; //number of entries
      fscanf(fp, "%d", &n);

      int i, rollno[n], marks[n];
      for(i = 0; i < n; i++)
      {
        fscanf(fp, "%d %d", &rollno[i], &marks[i]);
      }
      write(pipefd[1], &n, sizeof(n));
      write(pipefd[1], rollno, sizeof(rollno));
      write(pipefd[1], marks, sizeof(marks));

      int average = 0;
      // ### Calculating average ###
      for(i = 0; i < n; i++)
      {
        average += marks[i];
      }
      average = average/n;
      write(pipefd[1], &average, sizeof(average));
    }
  }
  else
  {
    printf("Unable to create pipe.\n");
    exit(1);
  }
}
