//RandomizedQuicksort - by modifing the RandomizedQuicksort function.

#include<stdio.h>
#include<stdlib.h>
long int comp = 0, swap = 0;
void RandomizedQuicksort(int *, int, int);
int partition(int *, int, int);
void main()
{
  void SortTheFile(char *, char *);
  SortTheFile("in_asce100.txt", "out_asce100.txt");
  SortTheFile("in_asce1000.txt", "out_asce1000.txt");
  SortTheFile("in_asce10000.txt", "out_asce10000.txt");
  SortTheFile("in_asce100000.txt", "out_asce100000.txt");
  SortTheFile("in_desc100.txt", "out_desc100.txt");
  SortTheFile("in_desc1000.txt", "out_desc1000.txt");
  SortTheFile("in_desc10000.txt", "out_desc10000.txt");
  SortTheFile("in_desc100000.txt", "out_desc100000.txt");
  SortTheFile("in_rand100.txt", "out_rand100.txt");
  SortTheFile("in_rand1000.txt", "out_rand1000.txt");
  SortTheFile("in_rand10000.txt", "out_rand10000.txt");
  SortTheFile("in_rand100000.txt", "out_rand100000.txt");
}

void SortTheFile(char in[], char out[])
{
  FILE *fp;
  if((fp = fopen(in, "r")) == NULL)
  {
    perror("SortTheFile, read:");
    exit(1);
  }
  int n;
  fscanf(fp,"%d",&n);
  int arr[n];
  for(int i = 0; i< n; i++)
  {
    fscanf(fp, "%d", &arr[i]);
  }
  fclose(fp);
  //sorting the array using RandomizedQuicksort
  comp = 0, swap =0;
  RandomizedQuicksort(arr, 0, n-1);
  if((fp = fopen(out, "w")) == NULL)
  {
    perror("SortTheFile - write");
    exit(1);
  }
  fprintf(fp,"%ld\n",comp);
  fprintf(fp, "%ld\n",swap);
  for(int i=0;i<n;i++)
  {
    fprintf(fp,"%d\n",arr[i]);
  }
}

int partition(int *arr, int p, int q)
{
	//selecting 1st element as pivot

	int x = arr[p];
	int i = p;
	int temp;
	for(int j = p+1; j<=q; j++)
  {
    comp++;
		if(arr[j]<=x)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
      swap++;
		}
  }
	//swapping pivot and i
	temp = arr[i];
	arr[i] = arr[p];
	arr[p] = temp;
  swap++;
	return(i);
}

void RandomizedQuicksort(int *arr, int p, int q)
{
  comp++;
	if(p < q)
	{
    // swapping pivot with random index
    int newrand = (rand() % (q - p + 1)) + p, temp;
    temp = arr[newrand];
    arr[newrand] = arr[p];
    arr[p] = temp;
	int m = partition(arr, p, q);
	// printf(" Value of m = %d \n", m);
	RandomizedQuicksort(arr, p, m-1);
	RandomizedQuicksort(arr, m+1, q);
	}
}
