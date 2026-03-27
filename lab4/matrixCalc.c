#include <stdlib.h>
#include "matrixCalc.h"

double* GetAddress(double* p, int i, int j)
{
	return(p + i*size + j);
}

void MemoryFree(void* p)
{
	free(p);
	p = NULL;
}

double* MatrixCalc(double* p0, double* p1, int size, char operation)
{
	if(p0 == NULL || p1 == NULL || size <= 0) return(NULL);

	double* reasult = malloc(size*size*sizeof(double));
	if(reasult == NULL) return(NULL);
	

	if(operation == '+' || operation == '-')
	{
		for(int i = 0; i < size*size; i++)
		{
			reasult[i] = operation == '+' ? p0[i] + p1[i] : p0[i] - p1[i];
		}
	}
	else if(operation == '*')
	{
		for(int i = 0; i < size, i++)
			for(int j = 0; j < size; j++)
 			{
 				
			}
	}
	else 
	{
		MemoryFree(reasult)
		return(NULL);
	}

	return(reasult);
}


