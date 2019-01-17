/*
Accepts only positive integers and float values.
Checks if they are in range or not.
Does not save any memory by realloc. That is yet to be done.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<limits.h>
#define BUFFER_SIZE 256

/*
This range function is useful when I'll add memory saving feature.
*/
bool range_valid(long long inputcheck, int type)
{
  switch (type) {
    case 0:
    if(inputcheck<=LONG_MAX)
    return true;
    break;
    case 1:
    if(inputcheck<=LONG_MAX)
    return true;
    break;
    default:
    printf("Out of range!");
    return false;
  }
}

bool validation(char *inputptr)
{
  if(fgets(inputptr, BUFFER_SIZE, stdin) == NULL)
  return false;
  char *dummyptr = inputptr;
  int flag = -1; // checking for double decimal points.
  while(*dummyptr != '\n')
  {
    if(isdigit(*dummyptr))
    {
      if(flag == -1)
      {
        flag = 0;
      }
    }
    else if(*dummyptr == '.' && (flag == -1 || flag == 0))
    {
      flag = 1;
    }
    else
    {
      printf("Value must be an positive integer or float! \n");
      return false;
    }
    dummyptr++;
  }
  long long ssinput;
  int n = sscanf(inputptr,"%lld", &ssinput); // use %Lf when long double is used
  if(errno == ERANGE)
  {
    printf("Out of range number, try again! \n");
    errno = 0;
    return false;
  }
  if(n==1 && (flag == -1 || flag == 0))
  {
    if(!range_valid(ssinput, 0))
    return false;
    long int intinput = strtol(inputptr, NULL, 10);
    printf("error no : %d\n", errno);
    printf("Integer: %ld \n", intinput);
  }
  else if(n == 1 && (flag<2))
  {
    if(!range_valid(ssinput, 1))
    return false;
    long double floatinput = atof(inputptr);
    printf("Float : %Lf\n",floatinput);
  }
  return true;
}



void main()
{
  // bool validation(char *);
  // bool range_valid(long long, int);
  char *input = (char*) malloc(256);
  while(!validation(input));

}
