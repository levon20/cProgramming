#include <stdlib.h>
#include "matrixCalc.h"
#include <stdio.h>

void MemoryFree(double**, int, int);
double** CreateMatrix(int, int);

double** MatrixCalc(double** ptr0, double** ptr1, int size, char operation)
{
	if(ptr0 == NULL || ptr1 == NULL || size <= 0) return(NULL);

	double** reasult = CreateMatrix(size, size);

	if(reasult == NULL) return(NULL);

	if(operation == '+' || operation == '-')
	{
		for(int i = 0; i < size; i++)
			for(int j = 0; j < size; j++)
				reasult[i][j] = operation == '+' ? ptr0[i][j] + ptr1[i][j] : ptr0[i][j] - ptr1[i][j];
	}
	else if(operation == '*')
	{
		for(int numOfStr = 0; numOfStr < size; numOfStr++)
			for(int numOfCol = 0; numOfCol < size; numOfCol++)
 			{
 				reasult[numOfStr][numOfCol] = 0;

 				for(int i = 0; i < size; i++)
 					reasult[numOfStr][numOfCol] += ptr0[numOfStr][i] * ptr1[i][numOfCol];
			}
	}
	else 
	{
		MemoryFree(reasult, size, size);
		return(NULL);
	}

	return(reasult);
}


double** CreateMatrix(int numOfStr, int numOfCol)
{
	double** matrix;

	matrix = malloc(numOfStr * sizeof(double*));

	if(matrix == NULL) return NULL;

	for(int i = 0; i < numOfStr; i++)
		matrix[i] = malloc(numOfCol * sizeof(double));
	
	return(matrix);
}


void MemoryFree(double** ptr, int numOfStr, int numOfColumn)
{
	for(int i = 0; i < numOfStr; i++)
		free(ptr[i]);

	free(ptr);

	ptr = NULL;
}
