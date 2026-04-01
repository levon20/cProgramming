#include <stdio.h>

void InputMatrix(void*, char, int);
void PrintMatrix(void*, char, int);
void BinPowMatrix(void*, int*, int);
int* GetAddress(int*, int, int, int);

void main()
{
	int size0 = 3;
	double array0[size0][size0];

	int size1 = 2;
	int array1[size1][size1];

	double sumMainDiagonal = 0;
	double sumSecondaryDioganal = 0;
	int* result;

	printf("Enter the elements of the 3x3 matrix: \n");
	InputMatrix(array0, 'd', size0);

	int j = 0;
	for(int i = 0; i < size0; i++)
		sumMainDiagonal += array0[i][j++];

	j = size0-1;
	for(int i = 0; i < size0; i++)
		sumSecondaryDioganal += array0[i][j--];

	printf("Sum of the elements of the main diagonal: %f \n", sumMainDiagonal);
	printf("Sum of the elements of the secondary diagonal: %f \n", sumSecondaryDioganal);

	printf("Enter the elements of the 2x2 matrix: \n");
	InputMatrix(array1, 'i', size1);

	BinPowMatrix(array1, result, size1);

	printf("The square of the matrix is equal to: \n");
	PrintMatrix(result, 'i', size1);

	scanf("%d");
}

void InputMatrix(void* arrP, char type, int size)
{
	double num;

	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
		{
			if(type == 'i') scanf("%d", (int*)arrP + size*i + j);
			else if(type == 'd') scanf("%lf", (double*)arrP + size*i + j);
		}
}

void PrintMatrix(void* arrP, char type, int size)
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

void BinPowMatrix(void* p, int* result,int size)
{
	int* matrix = (int*)p;
	
	for(int strN = 0; strN < size; strN++)
		for(int colN = 0; colN < size; colN++)
 		{
 			*GetAddress(result, size, strN, colN) = 0;

 			for(int i = 0; i < size; i++)
 				*GetAddress(result, size, strN, colN) += *GetAddress(matrix, size, strN, i) * *GetAddress(matrix, size, i, colN);
		}
}

int* GetAddress(int* p, int size, int i, int j)
{
	return(p + i*size + j);
}