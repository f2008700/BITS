/*
This program will calculate the sum and product of two 3x3 matrices
*/
# include <stdio.h>

# define Rows 3
# define Cols 3

void PrintMatrix(int a[Rows][Cols])
{
	int i, j;
	for(i = 0; i < Rows; i++)
	{
		for(j = 0; j < Cols; j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
}


void AddMatrices(int a[Rows][Cols], int b[Rows][Cols], int sum[Rows][Cols])
{
	int i, j;

	for(i = 0; i < Rows; i++)
	{
		for(j = 0; j < Cols; j++)
		{
			sum[i][j] = a[i][j] + b[i][j];
		}
	}
}

void MultiplyMatrices(int a[Rows][Cols], int b[Rows][Cols], int product[Rows][Cols])
{
	int i, j, k;
	int sum = 0;

	for(i = 0; i < Rows; i ++)
	{
		for(j = 0; j < Cols; j++)
		{
			sum = 0;
			for(k = 0; k < Cols; k++) sum += a[i][k]*b[k][j];
			product[i][j] = sum;
		}
	}

}

void main()
{
	int a[Rows][Cols];
	int b[Rows][Cols];
	int sum[Rows][Cols];
	int product[Rows][Cols];

	int i, j;

	printf("Enter the values for the first matrix..\n");
	for(i = 0; i < Rows; i++)
	{
		for(j = 0; j < Cols; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	printf("Enter the values for the second matrix..\n");
	for(i = 0; i < Rows; i++)
	{
		for(j = 0; j < Cols; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	AddMatrices(a, b, sum);
	MultiplyMatrices(a, b, product);

	printf("The sum matrix is......\n");
	PrintMatrix(sum);

	printf("The product matrix is......\n");
	PrintMatrix(product);

}