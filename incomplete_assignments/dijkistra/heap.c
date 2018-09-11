#include<stdio.h>
#include<stdlib.h>

void main()
{
  void minHeapify(int *, int);
  int size = 7;
  int arr[] = {2,3,5,1,7,9,8};
  for(int i=0;i<size;i++)
  printf("%d ",arr[i]);

  for(int i=0;i<size/2;i++)
  minHeapify(arr, i);

  for(int i=0;i<size;i++)
  printf("%d ",arr[i]);

}

void minHeapify(int *array)
