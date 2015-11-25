/* file: smallSetOps.c */
#include <stdio.h>
#include "smallSet.h"
#include "boolean.h"

unsigned int mask=1;



SmallSet CreateSet(void)
{
	SmallSet S=0;
	return S;
}

SmallSet AddElement(unsigned int x, SmallSet S)
{
	return (S|(mask<<x));
}

SmallSet RemoveElement(unsigned int x, SmallSet S)
{
	return (S & (~(mask<<x)));
}

Boolean isElementOf(unsigned int x, SmallSet S)
{
	if(S & (mask<<x)) return TRUE;
	else return FALSE;
}

SmallSet Union(SmallSet S1, SmallSet S2)
{
	return (S1 | S2);
}

SmallSet Intersect(SmallSet S1, SmallSet S2)
{
	return S1 & S2;
}

SmallSet Complement(SmallSet S)
{
	return ~S; 
}

Boolean Equals(SmallSet S1, SmallSet S2)
{
	if(S1==S2)
		return TRUE;
	else
		return FALSE;
}

void Print(SmallSet S)
{
	int i;
	printf("{");
	i=0;
	while(S!=0)
	{
		if(S & 1)
			printf("%d ",i);
		S=S>>1;
		i++;
	}
	printf("}\n");
}

