#include <stdio.h>

void GetSqrMatrixFromConsole(void*, char, int);
void PrintSqrMatrix(void*, char, int);


void main()
{
	int size0 = 3;
	int size1 = 2;
	double array0[size0][size0];
	int array1[size1][size1];

	double sumMainDiagonal = 0;
	double sumSecondaryDioganal = 0;

	printf("Enter the elements of the 3x3 matrix: \n");
	GetSqrMatrixFromConsole(array0, 'd', size0);

	int j = 0;
	for(int i = 0; i < size0; i++)
	{
		sumMainDiagonal += array0[i][j++];
	}

	j = size0-1;
	for(int i = 0; i < size0; i++)
	{
		sumSecondaryDioganal += array0[i][j--];
	}

	printf("Sum of the elements of the main diagonal: %f \n", sumMainDiagonal);
	printf("Sum of the elements of the secondary diagonal: %f \n", sumSecondaryDioganal);

	printf("Enter the elements of the 2x2 matrix: \n");
	GetSqrMatrixFromConsole(array1, 'i', size1);

	for(int i = 0; i < size1; i++)
	{
		for(int j = 0; j < size1; j++)
		{
			array1[i][j] *= array1[i][j]; 
		}
	}

	printf("The square of the matrix is equal to: \n");
	PrintSqrMatrix(array1, 'i', size1);

	scanf("%d");
}

void GetSqrMatrixFromConsole(void* arrP, char type, int size)
{
	double num;
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(type == 'i') scanf("%d", (int*)arrP + size*i + j);
			else if(type == 'd') scanf("%lf", (double*)arrP + size*i + j);
		}
	}
}

void PrintSqrMatrix(void* arrP, char type, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(type == 'i') printf("%d ", *((int*)arrP + size*i + j));
			else if(type == 'd') printf("%f ", *((double*)arrP + size*i + j));
		}

		printf("\n");
	}
}