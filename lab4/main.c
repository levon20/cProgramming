#include <stdio.h>
#include <stdlib.h>
#include "matrixCalc.h"

void PrintMatrix(double*, int);
void InputMatrix(double*, int);

void main()
{
	int matrixSize = 2;
	char operation;

	double* array0 = malloc(matrixSize*matrixSize*sizeof(double));
	double* array1 = malloc(matrixSize*matrixSize*sizeof(double));
	double* reasult = NULL;

	if(array0 == NULL || array1 == NULL) 
	{
		printf("Error! Not enough memory! \n");
		return;
	}

	printf("Enter the elements of the first matrix by space (line by line): \n");
	InputMatrix(array0, matrixSize);

	printf("Enter the elements of the sacond matrix by space (line by line): \n");
	InputMatrix(array1, matrixSize);

	printf("Enter the desired matrix operation (+, -, *): ");
	scanf("%s", &operation);

	reasult = MatrixCalc(array0, array1, matrixSize, operation);

	MemoryFree(array0);
	MemoryFree(array1);

	if(reasult != NULL) PrintMatrix(reasult, matrixSize);
	else printf("Error! \n");

	MemoryFree(reasult);
}

void PrintMatrix(double* ptr, int size)
{
	printf("\n");
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			printf("%f ", *GetAddress(ptr, size, i, j));
		}
		printf("\n");
	}
}

void InputMatrix(double* ptr, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			scanf("%lf", GetAddress(ptr, size, i, j));
		}
	}
}





