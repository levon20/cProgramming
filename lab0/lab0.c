#include <stdio.h>
#include <math.h>

float a;
float b;
float c;

void main()
{
	printf("Enter 3 coefficients by space: ");
	scanf(" %f %f %f", &a, &b, &c);

	float d = pow(b, 2)-4*a*c;

	if (d < 0) 
	{
		printf("Корней нет\n");
		return;
	} 
	
	printf("x0 = %f \n", (-b + sqrt(d))/(2*a));
	if (d > 0) printf("x1 = %f \n", (-b - sqrt(d))/(2*a));
}