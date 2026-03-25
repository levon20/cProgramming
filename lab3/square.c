#include <math.h>
#include "square.h"
#include "perimeter.h"


float GetTriangleSquare(float a, float b, float c)
{
	float p = GetTrianglePerimeter(a,b,c)/2;

	return sqrt(p*(p-a)*(p-b)*(p-c));
}