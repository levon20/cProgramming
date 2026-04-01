#include <stdio.h>
#include <stdlib.h>
#include "matrixCalc.h"

void PrintMatrix(double**, int);
void InputMatrix(double**, int);

void main()
{
	int matrixSize;
	double** array0 = NULL;
	double** array1 = NULL;
	double** reasult = NULL;
	char operation;

	printf("Enter the size of the square matrices: ");
	scanf("%d", &matrixSize);

	if(matrixSize <= 0) 
	{
		printf("Error: incorrect value size!\n");
		return;
	}

	array0 = CreateMatrix(matrixSize, matrixSize);
	array1 = CreateMatrix(matrixSize, matrixSize);
	
	if(array0 == NULL || array1 == NULL)
	{
		printf("Error: not enough free memory!");
		return;
	}

	printf("Enter the elements of the first matrix by space (line by line): \n");
	InputMatrix(array0, matrixSize);

	printf("Enter the elements of the second matrix by space (line by line): \n");
	InputMatrix(array1, matrixSize);

	printf("Enter the desired matrix operation (+, -, *): ");
	scanf(" %c", &operation);

	reasult = MatrixCalc(array0, array1, matrixSize, operation);

	MemoryFree(array0, matrixSize, matrixSize);
	MemoryFree(array1, matrixSize, matrixSize);

	if(reasult != NULL) PrintMatrix(reasult, matrixSize);
	else printf("Error! \n");

	MemoryFree(reasult, matrixSize, matrixSize);
}

void PrintMatrix(double** ptr, int size)
{
	printf("\n");
	
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
			printf("%f ", ptr[i][j]);
		printf("\n");
	}
}

void InputMatrix(double** ptr, int size)
{
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			scanf(" %lf", &(ptr[i][j]));
}




