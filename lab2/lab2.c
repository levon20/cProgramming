#include <stdio.h>

void main()
{
	int maxLength = 81;
	char inputString[maxLength];

	printf("Input your string (max length %d literals): ", maxLength-1);
	scanf("%80s", inputString);

	for(int i = 0; i < maxLength; i++)
	{
		if(inputString[i] == 'a') inputString[i] = 'A';
		else if(inputString[i] == 'b') inputString[i] = 'B';
	}

	printf("%s \n", inputString);
}