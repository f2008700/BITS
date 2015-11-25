/* file: setOps.h */
#include "set.h"
#include "boolean.h"

/*Postcondition:
 * initialize Set x to an Empty Set
*/
extern void CreateSet(Set x, unsigned int UnivSpace);


/*Postcondition:
 * S= S after adding Element x in it
*/
extern void AddElementSet(unsigned int x, Set S, unsigned int UnivSpace);


/*Postcondition:
 * S = S after Removing Element x from it
*/
extern void RemoveElementSet(unsigned int x, Set S, unsigned int UnivSpace);


/* Precondition: 
 * 	x < univSpace
 *
 * Postcondition:
 *	Return TRUE if x is an element of S
*/
extern Boolean isElementOfSet(unsigned int x, Set S, unsigned int UnivSpace);


/* Postcondition:
 *	 S3 such that x is in S3
 *	         iff x in S1 OR x in S2
*/
extern void UnionSet(Set S1, Set S2, Set S3, unsigned int UnivSpace);


/* Postcondition:
 *	S3 such that x is an element of S3
 *		iff x in S1 AND x in S2
*/
extern void IntersectSet(Set S1, Set S2, Set S3, unsigned int UnivSpace);


/* Postcondition:
 *	S2 such that x in S1
 *		iff NOT (x in S2)
*/
extern void ComplementSet(Set S1, Set S2, unsigned int UnivSpace);


/* Postcondition:
 *	Return TRUE if (x in S1 --> x in S2) AND
 *		       (x in S2 --> x in S1)
 *	       FALSE otherwise
*/
 extern Boolean EqualsSet(Set S1, Set S2, unsigned int UnivSpace);


/* Postcondition:
 *	Print the elements of SmallSet S
*/
extern void PrintSet(Set S, unsigned int UnivSpace);
