#include <stdlib.h>
#include "matrixCalc.h"
#include <stdio.h>

double* GetAddress(double*, int, int, int);
void MemoryFree(void*);

double* MatrixCalc(double* ptr0, double* ptr1, int size, char operation)
{
	if(ptr0 == NULL || ptr1 == NULL || size <= 0) 
		{
			printf("%d \n", size);
			return(NULL);
		}
	double* reasult = malloc(size*size*sizeof(double));

	if(reasult == NULL) return(NULL);

	if(operation == '+' || operation == '-')
	{
		for(int i = 0; i < size*size; i++)
			reasult[i] = operation == '+' ? ptr0[i] + ptr1[i] : ptr0[i] - ptr1[i];
	}
	else if(operation == '*')
	{
		for(int numOfStr = 0; numOfStr < size; numOfStr++)
			for(int numOfCol = 0; numOfCol < size; numOfCol++)
 			{
 				*GetAddress(reasult, size, numOfStr, numOfCol) = 0;

 				for(int i = 0; i < size; i++)
 					*GetAddress(reasult, size, numOfStr, numOfCol) += *GetAddress(ptr0, size, numOfStr, i) * *GetAddress(ptr1, size, i, numOfCol);
			}
	}
	else 
	{
		MemoryFree(reasult);
		return(NULL);
	}

	return(reasult);
}


double* GetAddress(double* ptr,int size, int i, int j)
{
	return(ptr + i*size + j);
}


void MemoryFree(void* ptr)
{
	free(ptr);
	ptr = NULL;
}
