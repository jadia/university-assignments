//Creating Files on which counting sort has to be done.
#include<stdio.h>
#include<time.h>  //time()
#include<stdlib.h> // exit(), random()

void genrandom(int limitup, int n, char *ch1) // generating n random numbers according to limit
{
  srand(time(0));
  int random;
  FILE *fp;
  if((fp = fopen(ch1, "w")) == NULL)
  {
    perror("genrandom,:");
    exit(1);
  }
  while(n>0)
  {
    random = rand() % limitup; // generate random numbers in range
    fprintf(fp,"%d\n",random);
    n--;
  }
  fclose(fp);
}


void CreateRandomFiles(char ch1[], int n) // creating random files
{
  genrandom(n/5,n,ch1);
  FILE *fp;
  if((fp = fopen(ch1, "r")) == NULL)
  {
    perror("CreateRandomFiles - read:");
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
  perror("CreateRandomFiles - write");
  exit(1);
  }

  fprintf(fp,"%d\n",n);
  for(int i=0;i<n;i++)
  {
  fprintf(fp,"%d\n",arr[i]);
  }
  fclose(fp);
}

void main()
{

  CreateRandomFiles("in_random50.txt",50);
  CreateRandomFiles("in_random100.txt",100);
  CreateRandomFiles("in_random500.txt",500);
  CreateRandomFiles("in_random1000.txt",1000);
}
