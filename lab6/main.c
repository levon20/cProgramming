#include <stdio.h>
#include <stdlib.h>

struct Human
{
	char name[20];
	char surname[20];
	int year;
};

void main()
{
	int len = 4;

	struct Human listHum0[len];
	struct Human listHum1[len];

	for(int i = 0; i < len; i++)
	{
		scanf("%20s %20s %d", &listHum0[i].name, &listHum0[i].surname, &listHum0.year);
		listHum0[i].year >= 0;
	}


}

void BubleSort(struct Human* list, int len)
{
	int flag = 0;
	struct Human boofer;
	while(flag)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].year > list[i+1].year)
			{
				boofer = list[i];
				list[i] = list[i+1];
				list[i+1] = boofer;
				flag = 0;
			}
			else flag = 1;
		}
		if(flag) return;	
	}
	
}