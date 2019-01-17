//Storing sparse matrix

#include<stdio.h>
#include<stdbool.h>

//#define MAX_ROWS 3
//#define MAX_COLUMNS 3

bool
void main()
{
        int MAX_ROWS, MAX_COLUMNS;
        printf("Enter rows and columns: \n");
        scanf("%d %d", &MAX_ROWS, &MAX_COLUMNS);
        int arr[MAX_ROWS][MAX_COLUMNS];
        int size = 0;

        printf("\nNow enter values for the matrix: \n");
        for(int i=0; i<MAX_ROWS;i++)
                for(int j=0; j<MAX_COLUMNS;j++)
                {
                        scanf("%d", &arr[i][j]);
                        if(arr[i][j] != 0)
                                size++;
                }
        int store[3][size];
        int k=0; //for colums of store.
        for(int i=0;i<MAX_ROWS;i++)
                for(int j=0;j<MAX_COLUMNS;j++)
                {
                        if(arr[i][j]!=0)
                        {
                                store[0][k] = arr[i][j]; //value
                                store[1][k] = i; // row
                                store[2][k] = j; // column
                                k++;
                        }
                }

//      printf("The store array is: \n");

        for(int i=0;i<3;i++)
        {
                if(k == 0)
                {
                        printf("Sorry!, all zeros \n");
                        break;
                }
                switch(i)
                {
                        case 0:
                                printf("Value:  ");
                                break;
                        case 1:
                                printf("Row:    ");
                                break;
                        case 2:
                                printf("Column: ");
                }
                for(int j=0;j<k;j++)
                {
                        printf("%d ", store[i][j]);
                }
                printf("\n");
        }
}
