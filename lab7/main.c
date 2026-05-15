#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Human
{
	char name[20];
	char surname[20];
	int year;
	char gender;
	int height;
} Human;

int SortByYear(const Human*, const Human*);
int SortByName(const Human*, const Human*);
int SortBySurname(const Human*, const Human*);
int SortByGender(const Human*, const Human*);
int SortByHeight(const Human*, const Human*);
int ReadAllLines(char*, Human*, int);
int WriteToFile(char*, Human*, int);

void main()
{

	char path[100];
	char paramSort;
	int numOfLinesInFile;

	printf("Input path to file: ");
	scanf(" %s", path);

	printf("\nEnter the number of lines in the file: ");
	scanf(" %d", &numOfLinesInFile);

	if(numOfLinesInFile <= 0)
	{
		printf("\nError: incorrect value! \n");
		return;
	}

	printf("\nHow do you want to sort the array? () \n");
	printf("--------\n0. Sort by year of birth; \n1. Sort by name; \n2. Sort by surname; \n3. Sort by gender; \n4. Sort by height.\n--------\n");	
	scanf(" %c", &paramSort);

	Human humans[numOfLinesInFile];

	if(!ReadAllLines(path, humans, numOfLinesInFile)) return;

	switch (paramSort)
	{
		case '0':
			qsort(humans, numOfLinesInFile, sizeof(Human), 
				(int (*)(const void *, const void *))SortByYear);
			break;
		
		case '1':
			qsort(humans, numOfLinesInFile, sizeof(Human), 
				(int (*)(const void *, const void *))SortByName);
			break;

		case '2':
			qsort(humans, numOfLinesInFile, sizeof(Human), 
				(int (*)(const void *, const void *))SortBySurname);
			break;

		case '3':
			qsort(humans, numOfLinesInFile, sizeof(Human), 
				(int (*)(const void *, const void *))SortByGender);
			break;	
		
		case '4':
			qsort(humans, numOfLinesInFile, sizeof(Human), 
				(int (*)(const void *, const void *))SortByHeight);
			break;

		default:
			printf("Sort By Error! Check data.\n");
			return;
	}

	if (!WriteToFile(path, humans, numOfLinesInFile))
		printf("Error");
	else 
		printf("\nDone!\n");

}

int WriteToFile(char path[100], Human* humans, int len)
{
	FILE* fileP = fopen(path, "w");

	if (fileP == NULL) return 0;

	for (int i = 0; i < len; i++)
		fprintf(fileP, "%s %s %d %c %d\n", humans[i].name, humans[i].surname, humans[i].year, humans[i].gender, humans[i].height);

	fclose(fileP);
	return 1;
}

int SortByYear(const Human* human0, const Human* human1)
{
	return human0->year - human1->year;
}

int SortByName(const Human* human0, const Human* human1)
{
	return strcmp(human0->name, human1->name);
}

int SortBySurname(const Human* human0, const Human* human1)
{
	return strcmp(human0->surname, human1->surname);
}

int SortByGender(const Human* human0, const Human* human1)
{
	return human0->gender - human1->gender;
}

int SortByHeight(const Human* human0, const Human* human1)
{
	return human0->height - human1->height;
}

int ReadAllLines(char path[100], Human* humans, int len)
{
	int i = 0;
	FILE* fileP = fopen(path, "r");

	if(fileP == NULL)
	{
		printf("\nError: incorrect path or file not exist! \n");
		return 0;
	}
	
	while((fscanf(fileP, "%s %s %d %c %d", humans[i].name, humans[i].surname, &(humans[i].year), &(humans[i].gender), &(humans[i].height)) != EOF) && (i < len))
		i++;

	fclose(fileP);

	return 1;
}













