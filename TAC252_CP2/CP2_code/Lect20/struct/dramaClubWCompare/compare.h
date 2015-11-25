/* file: compare.h */
#include "dramaClubMember.h"

typedef enum { LESS=-1, EQUAL=0, GREATER=1}ORDER;

/* Precondition: m1 and m2 can be ordered by a key field 
   Postcondition: 
   		returns EQUAL   if keys are equal
		returns LESS    if keys are in order
		returns GREATER if keys are out of order
*/
extern ORDER compare(Member m1, Member m2);
