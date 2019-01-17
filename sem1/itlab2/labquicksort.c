#include<stdio.h>
/*
	// generating random number
	srand(time(0));

	int random = rand() % n;
	int p = random;

*/
void main()
{
	void quicksort(int *, int, int);
	int partition(int *, int, int);
	int n;
	printf("Enter value of n: \n");
	scanf("%d", &n);

	int arr['n'];
	for(int i=0;i<n;i++)
		scanf("%d", &arr[i]);
	for(int i=0;i<n;i++)
		printf("%d ", arr[i]);
//	int m = partition(arr, 0, n-1);

	printf("\n Calling Quicksort \n");

	quicksort(arr, 0, n-1);
	for(int i=0;i<n;i++)
		printf("%d \n ", arr[i]);

}

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
	if(p < q)
	{
	int m = partition(arr, p, q);
	printf(" Value of m = %d \n", m);
	quicksort(arr, p, m-1);
	quicksort(arr, m+1, q);
	}
}
