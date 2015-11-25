/* file: compare.c */
#include "dramaClubMember.h"
#include "compare.h"

ORDER compare(Member m1, Member m2)
{
	if(m1.i == m2.i) return EQUAL;
	else if(m1.i<m2.i) return LESS;
	else return GREATER;
}
