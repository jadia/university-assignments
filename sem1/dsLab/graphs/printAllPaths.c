/*
Print all paths from a given source to a destination.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUTFILE "printAllPath.txt"

/*-----------------------------
Global var
-----------------------------*/
int n; // number of elements


/*functions*/

void printAllPath(int source, int destination, int index, int visited[n], int path[n], int buffer[][n])
{
  visited[source] = 1;
  path[index++] = source;
  if(source == destination)
  {
    for(int i = 0; i < index; i++)
    printf("%d ", path[i]);
    printf("\n");
  }
  else
  {
    // checking all the adjacent nodes
    printf("checking adjacent nodes.\n");
    for(int i = 0; i < n; i++)
    {
      if(buffer[source][i] != 0 && visited[i] !=1)
      {
        printAllPath(i, destination, index, visited, path, buffer);
      }
    }
  }
  index--;
  visited[source] = 0;
}

void initalizePath(int source, int destination, int buffer[][n])
{
  printf("initalizePath\n");
  int visited[n];
  int path[n];

  // making all visited 0
  printf("memset\n");
  memset(visited, 0, n);
  memset(path, 0, n);

  int index = 0;

  printAllPath(source, destination, index, visited, path, buffer);
}

void main()
{
  FILE *fp;
  if((fp = fopen(INPUTFILE, "r")) == NULL)
  {
    perror("InputFile ");
    exit(1);
  }
printf("file opened\n");
  fscanf(fp,"%d", &n);
  int source, destination;
  fscanf(fp,"%d", &source);
  fscanf(fp,"%d", &destination);
  printf("n: %d, s: %d, d: %d. \n", n, source, destination);
  int i,j;
  int buffer[n][n];
  for(i = 0; i< n; i++)
  {
    for(j = 0; j < n; j++)
    {
      fscanf(fp,"%d", &buffer[i][j]);
    }
  }
  printf("data read into buffer\n");
  initalizePath(source, destination, buffer);
}
