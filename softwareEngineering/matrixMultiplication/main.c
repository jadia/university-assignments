// matrix multiplication

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "matmul.c"
#include "matinp.c"		

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