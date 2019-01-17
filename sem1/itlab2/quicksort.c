#include<stdio.h>
#include<stdlib.h>
int comp = 0, swap = 0;
void quicksort(int *, int, int);
int partition(int *, int, int);
void main()
{

  //
	// printf("Enter value of n: \n");
	// scanf("%d", &n);
  //
	// int arr['n'];
	// for(int i=0;i<n;i++)
	// 	scanf("%d", &arr[i]);
	// // for(int i=0;i<n;i++)
	// // 	printf("%d ", arr[i]);
	// quicksort(arr, 0, n-1);
	// for(int i=0;i<n;i++)
	// 	printf("%d \n ", arr[i]);
  void calculate(char *, char *);
  // void calculate(char, char);
  // void calculate(char, char);
  // void quicksort(char *, int ,int)

  calculate("in_asce100.txt", "out_asce100.txt");
  calculate("in_asce1000.txt", "out_asce1000.txt");
  calculate("in_asce10000.txt", "out_asce10000.txt");
  calculate("in_asce100000.txt", "out_asce100000.txt");
  calculate("in_desc100.txt", "out_desc100.txt");
  calculate("in_desc1000.txt", "out_desc1000.txt");
  calculate("in_desc10000.txt", "out_desc10000.txt");
  calculate("in_desc100000.txt", "out_desc100000.txt");
  calculate("in_rand100.txt", "out_rand100.txt");
  calculate("in_rand1000.txt", "out_rand1000.txt");
  calculate("in_rand10000.txt", "out_rand10000.txt");
  calculate("in_rand100000.txt", "out_rand100000.txt");
}

void calculate(char in[], char out[])
{
  FILE *fp;
  if((fp = fopen(in, "r")) == NULL)
  {
    perror("calculate, read:");
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
  //sorting the array using quicksort
  comp = 0, swap =0;
  quicksort(arr, 0, n-1);
  if((fp = fopen(out, "w")) == NULL)
  {
    perror("calculate - write");
    exit(1);
  }
  fprintf(fp,"%d\n",comp);
  fprintf(fp, "%d\n",swap);
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

void quicksort(int *arr, int p, int q)
{
  comp++;
	if(p < q)
	{
	int m = partition(arr, p, q);
	// printf(" Value of m = %d \n", m);
	quicksort(arr, p, m-1);
	quicksort(arr, m+1, q);
	}
}
