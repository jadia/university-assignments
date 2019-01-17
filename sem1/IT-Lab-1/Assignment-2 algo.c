/*Analysis of different TC by Nitish Jadia 18MCMT13 */

#include<stdio.h>
#include<stdlib.h> //for exit(1)
#include<time.h> //for clock()
void main()
{
  void linear(int);
  void logarithmic(int);
  void quad(int);
  void cubic(int);
  int exponent(int);

  int n, trash; // trash variable to hold return value of exponent function
  printf("Enter value of n for linear, logarithmic and Quadratic complexity: \n");
  scanf("%d", &n);

  clock_t start, end; // variable to store time start and end
  double cpu_time_used;

  //testing linear TC algo
  printf("O(n) complexity: \n");
  start = clock();
  linear(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%lf \n", cpu_time_used);

  //testing Logarithmic TC algo
  printf("Logarithmic complexity: \n");
  start = clock();
  logarithmic(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%lf \n", cpu_time_used);

  //testing Quadratic TC algo
  printf("Quadratic complexity: \n");
  start = clock();
  quad(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%lf \n", cpu_time_used);

  printf("Enter value of n for Cubic and Exponential complexity: \n");
  scanf("%d", &n);

  //testing Cubic TC algo
  printf("Cubic complexity: \n");
  start = clock();
  cubic(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%lf \n", cpu_time_used);

  //testing Exponential TC algo
  printf("Exponential complexity: \n");
  start = clock();
  trash = exponent(n);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("%lf \n", cpu_time_used);

}

void linear(int n)
{
  int i;
  for(i=0;i<n;i++)
  continue;
}

void quad(int n)
{
  int i,j;
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  continue;
}

int exponent(int fib)
{
  if (fib == 0 || fib == 1)
  return fib;
  else
  return(exponent(fib-1)+exponent(fib-2));
}

void logarithmic(int n)
{
  int i=1;
  while(i<n)
  i=i*2;
}

void cubic(int n)
{
  int i,j,k;
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  for(k=0;k<n;k++)
  continue;
}
