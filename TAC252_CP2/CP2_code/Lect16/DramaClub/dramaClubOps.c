/*file: dramaClubOps.h */
#include "dramaClubList.h"
#include "boolean.h"

ListSize add(Member m, List ms, ListSize N)
{
	int pos, newsize=N;
	if((N+1)>MAX)	return 0;
	for(pos=0; pos<N; pos++)
	{
		if(ms[pos] > m) break;
		if(ms[pos] ==m) return N;
	}
	for(;N>pos;N--)
		ms[N]=ms[N-1];
	ms[N]=m;
	return newsize+1;
}

int search(ID i, List ms, ListSize N)
{
	int lo, hi, mid;
	lo=0; hi=N-1;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(ms[mid] == i)
			return mid;
		else if(ms[mid]>i)
			hi=mid-1;
		else
			lo=mid+1;
	}
	return -1;
}

ListSize delete(Member m, List ms, ListSize N)
{
	int pos, newsize=N;
/*	for(pos=0; pos<N; pos++)
	{
		if(ms[pos] > m) return N;
		if(ms[pos] == m) break;
	}
*/
	pos=search(m,ms,N);
	if(pos>=0)
	{
		for(;pos<(N-1);pos++)
			ms[pos]= ms[(pos+1)];
		return (N-1);
	}
	return N;
}

Boolean isMember(ID i, List ms, ListSize N)
{
	if(search(i,ms,N) >=0) return TRUE;
	else return FALSE;
}


