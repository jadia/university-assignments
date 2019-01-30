// matrix multiplication

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


void matrixInput(int row1, int column1, int row2, int column2, int mat1[][column1], int mat2[][column2])
{	
	/*Taking input for matrix1*/
	int i, j;
	char input[99];
	printf("Input values for 1st matrix: \n");
	for(i = 0; i<row1; i++)
	{
		for(j=0; j<column1; j++)
		{
			printf("\n Row: %d, Column: %d -> ", i, j);
			scanf("%s", &input);
			if(sscanf(input,"%d",&mat1[i][j]) == 0)
			{
				printf("Enter valid input! Try again. \n");
				j--;
			}
		}
	}

	/* Taking input for matrix 2 */
	printf("\n\nInput values for 2nd matrix: \n");
	for(i = 0; i<row2; i++)
	{
		for(j=0; j<column2; j++)
		{
			printf("\n Row: %d, Column: %d -> ", i, j);
			scanf("%s", &input);
			if(sscanf(input,"%d", &mat2[i][j]) == 0)
			{
				printf("Enter valid input! Try again. \n");
				j--;
			}
		}
	}

	/* Printing matrix*/
	printf("\n\n1st matrix: \n");
	for(i = 0; i<row1; i++)
	{
		for(j=0; j<column1; j++)
		{
			printf("%d ", mat1[i][j]);
		}
		printf("\n");
	}
	printf("\n\n2nd matrix: \n");
	for(i = 0; i<row2; i++)
	{
		for(j=0; j<column2; j++)
		{
			printf("%d ", mat2[i][j]);
		}
		printf("\n");
	}

}


void multiplyMatrix(int row1, int column1, int row2, int column2, int mat1[][column1], int mat2[][column2])
{	
	int result[row1][column2];
	int i, j, k;
	int temp = 0;
	for(i=0; i<row1; i++)
	{
		for(j=0; j<column2; j++)
		{
			for(k=0; k<row2; k++)
				{
					temp = temp + (mat1[i][k]*mat2[k][j]);
				}
			result[i][j] = temp;
			temp = 0;
		}
	}
	
	printf("\n\nResult matrix: \n");
	for(i = 0; i<row1; i++)
	{
		for(j=0; j<column2; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}				

void main()
{
/* Initial input */
	printf("Input rows and column for 1st matrix: ");
	int row1, column1;
	scanf("%d %d", &row1, &column1);
	int mat1[row1][column1];
	printf("Input rows and column for 2nd matrix: ");
	int row2, column2;
	scanf("%d %d", &row2, &column2);
	int mat2[row2][column2];
/* Check if matrix multiplication is possible */
	if(column1 != row2)
	{
		printf("Sorry matrix multiplication not possible! \n");
		exit(1);
	}
	
/* Matrix input */	
	matrixInput(row1, column1, row2, column2, mat1, mat2);
/* Multiplication */
	multiplyMatrix(row1, column1, row2, column2, mat1, mat2);
}