#include <stdio.h>
#include <math.h>

float a = 2;
float b = -5;
float c = 3;

void main()
{
	float d = pow(b, 2)-4*a*c;

	if (d < 0) 
	{
		printf("Корней нет\n");
		return;
	} 
	
	printf("x0 = %f \n", (-b + sqrt(d))/(2*a));
	if (d > 0) printf("x1 = %f \n", (-b - sqrt(d))/(2*a));

	scanf("%d");
}