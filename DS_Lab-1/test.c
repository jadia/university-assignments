#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#define BUFFER_SIZE 256
void main()
{
  char *inputptr = (char*) malloc(256);
  if(fgets(inputptr, BUFFER_SIZE, stdin) == NULL)
  exit(1);
  char *dummyptr = inputptr;
  while(*dummyptr != '\n')
  {
    // printf("%c hey", *dummyptr);
    if(*dummyptr == '0' || *dummyptr == '1' || *dummyptr == '2' || *dummyptr == '3' || *dummyptr == '4' || *dummyptr == '5' || *dummyptr == '6' || *dummyptr == '7' || *dummyptr == '8' || *dummyptr == '9')
      ;
    else
    {
      printf("Value must be integer!");
      exit(1);
    }
    dummyptr++;
  }
  long int ssinput;
  int n = sscanf(inputptr,"%ld", &ssinput);
  // printf("\nvalue of n: %d\n",n );
  if(n==1)
  {
    long int intinput = strtol(inputptr, NULL, 10);
    printf("%ld", intinput);
  }
}
