#include <stdio.h>
#include <stdlib.h>

struct Human
{
	char name[20];
	char surname[20];
	int year;
};

void ArrayCpy(struct Human*, struct Human*, int);
void BubleSort(struct Human*, int);		


void main()
{
	int len = 4;

	struct Human listHum0[len];
	struct Human listHum1[len];

	for(int i = 0; i < len; i++)
	{
		scanf("%20s %20s %d", listHum0[i].name, listHum0[i].surname, &(listHum0[i].year));
		if(listHum0[i].year < 0) listHum0[i].year = 0;
	}

	ArrayCpy(listHum0, listHum1, len);

	BubleSort(listHum1, len);

	for(int i = 0; i < len; i++)
		printf("%d. %s %s %d \n", i, listHum1[i].name, listHum1[i].surname, listHum1[i].year);
}

void ArrayCpy(struct Human* originList, struct Human* newList, int len )
{
	for(int i = 0; i < len; i++)
		newList[i] = originList[i];
}

void BubleSort(struct Human* list, int len)
{
	int flag = 1;
	struct Human boofer;

	while(flag)
	{
		flag = 0;

		for(int i = 0; i < len-1; i++)
		{
			if(list[i].year > list[i+1].year)
			{
				boofer = list[i];
				list[i] = list[i+1];
				list[i+1] = boofer;
				flag = 1;
			}
		}

		len -= 1;	
	}
}