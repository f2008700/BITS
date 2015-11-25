/* File Name: quad.c
 * implementation of quad function is available here
*/
#include "sqrt.h"
float quad(int a, int b, int c, int sign)
{
	float s;
	if((b*b)-(4*a*c)>0)
	{
		s=sqrt1(b*b-4*a*c);
		if(s>=0.0)
		{
			if(sign)
			{
				return (((float)(-1*b + s))/2*a);
			}
			else	
				return (((float)(-1*b - s))/2*a);
		}
		else
			return (float)-1;
	}
	else
		return (float)-1;
}
