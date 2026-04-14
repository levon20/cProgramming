#include <stdio.h>
#include "triangle.h"

int isTriangle(float, float, float);

void main()
{
	float a, b, c;

	printf("Enter the sides of the triangle separated by a space: ");
	scanf("%f %f %f", &a, &b, &c);

	if(isTriangle(a,b,c)) 
	{
		printf("Perimeter: %f \nSquare: %f \n", GetTrianglePerimeter(a,b,c) ,GetTriangleSquare(a,b,c));
	}
	else 
	{
		printf("Such a triangle does not exist! \n");
	}	

}

int isTriangle(float a, float b, float c)
{
	return (a+b > c && a+c > b && c+b > a);
}