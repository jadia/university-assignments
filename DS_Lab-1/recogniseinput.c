#include<stdio.h>
#include<stdlib.h>
#define BUFFER_SIZE 256
void main()
{
  char *inputptr = (char*) malloc(256);
  if(fgets(inputptr, BUFFER_SIZE, stdin)) == NULL)
    exit(1);

  

}
