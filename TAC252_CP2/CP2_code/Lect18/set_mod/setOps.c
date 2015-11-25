/* file: setOps.c */
#include <stdio.h>
#include <math.h>
#include "set.h"
#include "smallSetOps.h"

unsigned int y;
void CreateSet(Set S, unsigned int UnivSpace)
{
	int i,N;
	N=ceil(((float)UnivSpace)/((float)(8*sizeof(unsigned int))));
	for(i=0;i<N;i++)
		S[i]=Create();

}

void AddElementSet(unsigned int x, Set S, unsigned int UnivSpace)
{
	if(x<UnivSpace)
	{
		y=sizeof(unsigned int)*8;
		S[(x/y)]=AddElement((x%y),S[(x/y)]);
	}
	else
		printf("Addition not possible\n");
}

void RemoveElementSet(unsigned int x, Set S, unsigned int UnivSpace)
{
	if(x<UnivSpace)
	{
		y=sizeof(unsigned int)*8;
		S[(x/y)]=RemoveElement((x%y),S[(x/y)]);
	}
	else
		printf("Element outside Univ Set\n");
}


Boolean isElementOfSet(unsigned int x, Set S, unsigned int UnivSpace)
{
	if(x<UnivSpace)
	{
		y=sizeof(unsigned int)*8;
		return (isElementOf((x%y),S[(x/y)]));
	}
	else
		return FALSE;
}


void UnionSet(Set S1, Set S2, Set S3, unsigned int UnivSpace)
{
	int i,N;
	N=ceil(((float)UnivSpace)/((float)(8*sizeof(unsigned int))));
	for(i=0;i<N;i++)
		S3[i]=Union(S1[i],S2[i]);
}


void IntersectSet(Set S1, Set S2, Set S3, unsigned int UnivSpace)
{
	int i,N;
	N=ceil(((float)UnivSpace)/((float)(8*sizeof(unsigned int))));
	for(i=0;i<N;i++)
		S3[i]=Intersect(S1[i],S2[i]);
}


void ComplementSet(Set S1, Set S2, unsigned int UnivSpace)
{
	int i,N;
	N=ceil(((float)UnivSpace)/((float)(8*sizeof(unsigned int))));
	for(i=0;i<N;i++)
		S2[i]=Complement(S1[i]);

}


Boolean EqualsSet(Set S1, Set S2, unsigned int UnivSpace)
{
	int i,N;
	N=ceil(((float)UnivSpace)/((float)(8*sizeof(unsigned int))));
	for(i=0;i<N;i++)
	{
		if(Equals(S1[i],S2[i])==FALSE)
			return FALSE;
	}
	return TRUE;
}



void PrintSet(Set S, unsigned int UnivSpace)
{
	int i,j,N;
	unsigned int temp;
	N=ceil(((float)UnivSpace)/((float)(8*sizeof(unsigned int))));
	printf("{");
	for(i=0;i<N;i++)
	{
		j=0;
		temp=S[i];
		while(temp!=0)
		{
			if(temp & 1)
			{
				if((i*32+j)<UnivSpace)
					printf("%d ",(i*32+j));
			}
			temp=temp>>1;
			j++;
		}
		printf("  ");
	}
	printf("}\n");
}
