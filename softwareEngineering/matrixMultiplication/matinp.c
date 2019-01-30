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
