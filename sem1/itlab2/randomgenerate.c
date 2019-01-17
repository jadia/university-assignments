/*
Generate the input text files with sizes 100, 1000, 10,000
and 100,000 containing integers(also -ve numbers through set
the range such as -100 to 100 for size of 100 ) in
(i) sorted (ascending order)
(ii) random
(iii) sorted (descending order)
Save input text file as “in_asce100.txt”, “in_ran1000.txt”,
“in_desc10000.txt”
*/

#include<stdio.h>
#include<time.h>  //time()
#include<stdlib.h> // exit(), random()

int partition(int *arr, int p, int q)
{
	//selecting 1st element as pivot

	int x = arr[p];
	int i = p;
	int temp;
	for(int j = p+1; j<=q; j++)
		if(arr[j]<=x)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	//swapping pivot and i
	temp = arr[i];
	arr[i] = arr[p];
	arr[p] = temp;
	return(i);
}

void quicksort(int *arr, int p, int q)
{
//  q--;
	if(p < q)
	{
	int m = partition(arr, p, q);
	quicksort(arr, p, m-1);
	quicksort(arr, m+1, q);
	}
}

void genrandom(int limitlow, int limitup, int n, char *ch1) // generating n random numbers range(-1000 to 1000)
{
  srand(time(0));
  int random;
  FILE *fp;
  if((fp = fopen(ch1, "w")) == NULL)
  {
    perror("genrandom, in_ran1000:");
    exit(1);
  }
  while(n>0)
  {
    random = (rand() %(limitup-limitlow+1)+limitlow); // generate random numbers in range
    fprintf(fp,"%d\n",random);
    n--;
  }
  fclose(fp);
}


void gensortasc(char ch1[], int n)
{
  genrandom(n*-1,n,n,ch1);

  FILE *fp;
  if((fp = fopen(ch1, "r")) == NULL)
  {
    perror("gensortasc-read, in_ran1000:");
    exit(1);
  }
  // reading previously created random file and picking 100 elements from it.
    int arr[n];
  for(int i = 0; i< n; i++)
  {
    fscanf(fp, "%d", &arr[i]);
  }
  fclose(fp);
  //sorting the array using quicksort
  quicksort(arr, 0, n-1);
  if((fp = fopen(ch1, "w")) == NULL)
  {
    perror("gensortasc - write");
    exit(1);
  }
  fprintf(fp,"%d\n",n);
  for(int i=0;i<n;i++)
  {
    fprintf(fp,"%d\n",arr[i]);
    //printf("%d ",arr[i]);
  }
}

void nosort(char ch1[], int n)
{
  genrandom(n*-1,n,n,ch1);
  FILE *fp;
  if((fp = fopen(ch1, "r")) == NULL)
  {
    perror("genrandom, in_ran1000:");
    exit(1);
  }

  int arr[n];
  for(int i = 0; i< n; i++)
  {
  fscanf(fp, "%d", &arr[i]);
  }
  fclose(fp);

  if((fp = fopen(ch1, "w")) == NULL)
  {
  perror("gensortasc - write");
  exit(1);
  }

  fprintf(fp,"%d\n",n);
  for(int i=0;i<n;i++)
  {
  fprintf(fp,"%d\n",arr[i]);
  //printf("%d ",arr[i]);
  }
  fclose(fp);
}


void gensortdesc(char ch1[], int n)
{
  genrandom(n*-1,n,n,ch1);

  FILE *fp;
  if((fp = fopen(ch1, "r")) == NULL)
  {
    perror("gensortasc-read, in_ran1000:");
    exit(1);
  }

  int arr[n];
  for(int i = 0; i<n;i++)
  {
    fscanf(fp, "%d", &arr[i]);
  }
  fclose(fp);
  perror("hello");
  //sorting the array using quicksort
  quicksort(arr, 0, n-1);
  if((fp = fopen(ch1, "w")) == NULL)
  {
    perror("gensortdesc - write");
    exit(1);
  }
  fprintf(fp,"%d\n",n);
  for(int i=n-1;i>=0;i--)
  {
    fprintf(fp,"%d\n",arr[i]);
    //printf("%d ",arr[i]);
  }
  fclose(fp);
}

void main()
{

  gensortasc("in_asce100.txt",100);
  gensortasc("in_asce1000.txt",1000);
  gensortasc("in_asce10000.txt",10000);
  gensortasc("in_asce100000.txt",100000);
  gensortdesc("in_desc100.txt",100);
  gensortdesc("in_desc1000.txt",1000);
  gensortdesc("in_desc10000.txt",10000);
  gensortdesc("in_desc100000.txt",100000);
  nosort("in_rand100.txt",100);
  nosort("in_rand1000.txt",1000);
  nosort("in_rand10000.txt",10000);
  nosort("in_rand100000.txt",100000);

  // gensortdesc();
  //genrandom(-1000, 1000, 1000);
}
