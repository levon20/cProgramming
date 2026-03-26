#include <stdio.h>
#include <stdlib.h>
#include "matrixCalc.h"

void PrintMatrix(double*, int);
void InputMatrix(double*, int);

void main()
{
	int matrixSize = 2;

	double* array0 = malloc(matrixSize*matrixSize*syzeof(double));
	double* array1 = malloc(matrixSize*matrixSize*syzeof(double));

	printf("Enter the elements of the first matrix by space: \n");
	InputMatrix(array0, matrixSize);

	printf("Enter the elements of the sacond matrix by space: \n");
	InputMatrix(array1, matrixSize);
1 2
3 4

1 2 3 4
1 3 2 4
}

void PrintMatrix(double* p, int size)
{
	for(int i = 0; i < matrixSize; i++)
	{
		for(int j = 0; j < matrixSize; j++)
		{
			printf("%f ",p[i][j]);
		}
		printf("\n");
	}
}

void InputMatrix(double* p, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			scanf("%lf", &p[i][j]);
		}
	}
}