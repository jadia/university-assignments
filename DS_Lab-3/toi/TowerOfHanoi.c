/*
Create tower of hanoi.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 64
#define inputfile "toiInput.txt"

int validation(char *);
void tower(int,char,char,char);

void main()
{
  char array[BUFFER_SIZE];
  char source = 'A',destination = 'C', auxiliary = 'B';
  int TestCases = 0;
  FILE *fp;
  fp = fopen(inputfile,"r");
  fscanf(fp,"%d",&TestCases);

  for(int i=1;i <= TestCases ;i++)
  {
    printf("\nInput is: ");
    fscanf(fp,"%s",array);
    fputs(array,stdout);

    int check = validation(array);
    if(check == 1)
    {
      printf("\n");
      int n = atoi(array);
      tower(n,source,destination,auxiliary);
    }
    else
    {
      printf("\n Invalid Input! \n");
    }
  }
  fclose(fp);
}

int validation(char *arr)
{
  int i=0;
  while(i < strlen(arr))
  {
    int temp = arr[i];
    if(temp >= 49 && temp <= 57 ) //ASCII value of 0 to 9 value.
    {
      i++;
    }
    else {
      return -1;
    }
  }
  return 1;
}

void tower(int n,char source,char destination,char auxiliary)
{
  if(n==1)
  {
    printf("Move disk %d from %c to %c\n",n,source,destination);
    return ;
  }
  else
  {
    tower(n-1,source,auxiliary,destination);
    printf("Move disk %d from %c to %c\n",n,source,destination);
    tower(n-1,auxiliary,destination,source);
    return ;
  }

}
