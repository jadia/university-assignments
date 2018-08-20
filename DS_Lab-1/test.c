#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<ctype.h>
#include<limits.h>
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
    if(isdigit(*dummyptr))
    flag = 0;
    else if(*dummyptr == '.' && (flag == -1 || flag == 0))
    {
      flag = 1;
    }
    else
    {
      printf("Value must be an positive integer or float!");
      exit(1);
    }
    dummyptr++;
  }
  long double ssinput;
  int n = sscanf(inputptr,"%Lf", &ssinput);
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
