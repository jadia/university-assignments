/*
Multiplies given matrix.
Accepts only integer matrix.
*/
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