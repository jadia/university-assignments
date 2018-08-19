/*
2b. Write a program of Counting sort using the input text files
from Question 2a. Generate and save the output text files such
as “out_random50.txt” or “out_random500.txt”. Follow the I/O
syntax convention of Question 1.

*/

#include<stdio.h>
#include<stdlib.h>
int comp, swap; //Global var to get no of comparasions and swaps

void CountingSort(int *InitialArrayPtr, int size)
{
  int max(int *,int); //finding max function prototype
  int maxnum = max(InitialArrayPtr,size)+1;
  int count[maxnum]; // Middle array used during counting sort

  for(int i=0; i<maxnum; i++) // Initializing every element to 0
  count[i]=0;

  for(int i=0; i<size; i++)
  {
    count[InitialArrayPtr[i]]++;
  }

  for(int i=1; i<maxnum; i++)
  {
    count[i]=count[i-1] + count[i];
  }

  int SortedArray[size];

  for(int i=size-1;i>=0;i--)
  {
    count[InitialArrayPtr[i]]--;
    SortedArray[count[InitialArrayPtr[i]]] = InitialArrayPtr[i];
  }

  for(int i=0; i<size; i++) // inserting sortedarray into the original array
  InitialArrayPtr[i] = SortedArray[i];
}


void CreateFiles(char *in_file, char *out_file)
{
  comp = 0, swap = 0;
  FILE *fp;
  if ((fp = fopen(in_file, "r")) == NULL)
  {
    perror("in_file:");
    exit(1);
  }
  int size;
  fscanf(fp, "%d", &size);
  int InitialArray[size];
  for(int i=0; i<size; i++)
  fscanf(fp, "%d", &InitialArray[i]);
  fclose(fp);

  CountingSort(InitialArray, size); // Sorts the array

  if ((fp = fopen(out_file, "w")) == NULL)
  {
    perror("out_file:");
    exit(1);
  }
  fprintf(fp, "%d\n", size);
  fprintf(fp, "%d\n", comp);
  fprintf(fp, "%d\n", swap);
  for(int i=0; i<size; i++)
  fprintf(fp, "%d\n", InitialArray[i]);
  fclose(fp);
}

int max(int *arr, int n)
{
  int max=*arr;
  for(int i=0; i<n; i++)
  {
    comp++;
    if(max<*arr)
    max=*arr;
    arr++;
  }
  return max;
}

void main()
{
  CreateFiles("in_random50.txt", "out_random50.txt");
  CreateFiles("in_random100.txt", "out_random100.txt");
  CreateFiles("in_random500.txt", "out_random500.txt");
  CreateFiles("in_random1000.txt", "out_random1000.txt");
}
