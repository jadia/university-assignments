/* Write a reversal algo for right rotation of an array.
For eg: k=4
input: 1 2 3 4 5 6 7 8 9 10
output: 10 9 8 7 1 2 3 4 5
*/

#include<stdio.h>
#include<stdlib.h>
#define BUFFER_SIZE 256
#define inputfile "input.txt"

void main()
{
  void rotate(char [][BUFFER_SIZE],int,int);
  FILE *fp;
  if((fp = fopen(inputfile, "r")) == NULL)
  {
    perror("Input file: ");
    exit(1);
  }
  int TestCases, NoOfElements;
  fscanf(fp,"%d",&TestCases);
  int k[TestCases];
  for(int i=1;i<=TestCases;i++)
  {
    fscanf(fp,"%d",&NoOfElements);
    char arr[NoOfElements][BUFFER_SIZE];
    fscanf(fp,"%d",&k[i]);
    for(int i=0;i<NoOfElements;i++)
    {
      fscanf(fp,"%s",&arr[i][0]);
    }
    while(k[i]<0)
    {
      k[i]=k[i]+NoOfElements;
    }

    rotate(arr,NoOfElements,k[i]);

  }

}

void rotate(char arr[][BUFFER_SIZE],int NoOfElements,int k){

  for(int i = 1;i <=k;i++ )
    printf("\t %s",arr[NoOfElements-i]);

  for(int i = 0;i <= NoOfElements-(k-1);i++ )
    printf("\t %s",arr[i]);
  printf("\n");
}
