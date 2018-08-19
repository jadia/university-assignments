/*
Accepts every kind of input.
Size validation is yet to be done.
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#define BUFFER_SIZE 256
void main()
{
  char *inputptr = (char*) malloc(256);
  if(fgets(inputptr, BUFFER_SIZE, stdin) == NULL)
  exit(1);
  char *dummyptr = inputptr;
  int flag = -1; // checking for double decimal points.
  while(*dummyptr != '\n')
  {
    // printf("%c hey", *dummyptr);
    //if(*dummyptr == '0' || *dummyptr == '1' || *dummyptr == '2' || *dummyptr == '3' || *dummyptr == '4' || *dummyptr == '5' || *dummyptr == '6' || *dummyptr == '7' || *dummyptr == '8' || *dummyptr == '9')
      if(isdigit(*dummyptr))
        flag = 0;
    else if(*dummyptr == '.' && (flag == -1 || flag == 0))
      {
        flag = 1;
      }
    else
    {
      printf("Value must be integer!");
      exit(1);
    }
    dummyptr++;
  }
  long double ssinput;
  int n = sscanf(inputptr,"%Lf", &ssinput);
  // printf("\nvalue of n: %d\n",n );
  if(n==1 && (flag == -1 || flag == 0))
  {
    long int intinput = strtol(inputptr, NULL, 10);
    printf("%ld", intinput);
  }
  else if(n == 1)
  {
    long double floatinput = atof(inputptr);
    printf("%Lf\n",floatinput);
  }
}
