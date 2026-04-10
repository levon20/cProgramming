#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GetYear(char*);

void main()
{
	int year = 1980;
	char string[100];

	FILE* originFilePtr = fopen("list.txt", "r");
	FILE* newFilePtr = fopen("newList.txt", "w+");

	if (originFilePtr == NULL || newFilePtr == NULL)
		perror("Error");

	while(fgets(string, 100, originFilePtr) != NULL)
	{
		int y = GetYear(string);
		if(y > year)
			fputs(string, newFilePtr);
	}
	
	fclose(originFilePtr);
	fclose(newFilePtr);
}

int GetYear(char* s)
{
	int len = strlen(s);
	char buffer[5];
	int j = 4;
	
	for(int i = len-1; i > len-6; i--)
	{
		buffer[j] = s[i];
		j--;
	}
	return(strtol(buffer, NULL, 10));
}