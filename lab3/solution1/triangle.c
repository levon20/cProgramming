#include <math.h>
#include "triangle.h"

float GetTriangleSquare(float a, float b, float c)
{
	float p = GetTrianglePerimeter(a,b,c)/2;

	return sqrt(	p*(p-a)*(p-b)*(p-c));
}

float GetTrianglePerimeter(float a, float b, float c)
{
	return a+b+c;
}