/*
Returns true of false.
Accepts only positive integers and float values.
Checks if they are in range or not.
Does not save any memory by realloc. That is yet to be done.
-----------------------------------------------------------------
Return values:
0 : Not accepted
1 : integer
2 : float
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<errno.h>
#include<ctype.h>
#include<limits.h>

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
    //printf("Out of range!");
    return false;
  }
}

int validation(char *inputptr)
{
  char *dummyptr = inputptr;
  int flag = -1; // checking for double decimal points.
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
    // printf("Value must be an positive integer or float! \n");
    return 0;
  }

  long long ssinput;
  int n = sscanf(inputptr,"%lld", &ssinput); // use %Lf when long double is used
  if(errno == ERANGE)
  {
    printf("Out of range number, try again! \n");
    errno = 0;
    return 0;
  }
  if(n==1 && (flag == -1 || flag == 0))
  {
    if(!range_valid(ssinput, 0))
    return 0;
    else
    return 1;
  }
  else if(n == 1 && (flag<2))
  {
    if(!range_valid(ssinput, 1))
    return 0;
    else
    return 2;
  }
}
