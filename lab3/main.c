#include <stdio.h>
#include "perimeter.h"
#include "square.h"

void main()
{
	float a, b, c;

	printf("Enter the sides of the triangle separated by a space: ");
	scanf("%f %f %f", &a, &b, &c);

	if(a+b > c) 
	{
		printf("Perimeter: %f \nSquare: %f \n", GetTrianglePerimeter(a,b,c) ,GetTriangleSquare(a,b,c));
	}
	else 
	{
		printf("Such a triangle does not exist! \n");
	}	
}