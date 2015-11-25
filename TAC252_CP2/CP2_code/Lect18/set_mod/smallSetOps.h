/* file: smallSetOps.h */
#include "smallSet.h"
#include "boolean.h"

/*Postcondition:
 * Returns an Empty SmallSet
*/
extern SmallSet Create(void);


/*Postcondition:
 * Returns S after adding Element x into Smallset S
*/
extern SmallSet AddElement(unsigned int x, SmallSet S);


/*Postcondition:
 * Returns S after Removing Element x into Smallset S
*/
extern SmallSet RemoveElement(unsigned int x, SmallSet S);


/* Precondition: 
 * 	x < sizeof(SmallSet)
 *
 * Postcondition:
 *	Return TRUE if x is an element of S
*/
extern Boolean isElementOf(unsigned int x, SmallSet S);


/* Postcondition:
 *	Return S such that x is in S
 *	         iff x in S1 OR x in S2
*/
extern SmallSet Union(SmallSet S1, SmallSet S2);


/* Postcondition:
 *	Return S such that x is an element of S
 *		iff x in S1 AND x in S2
*/
extern SmallSet Intersect(SmallSet S1, SmallSet S2);


/* Postcondition:
 *	Return S1 such that x in S1
 *		iff NOT (x in S)
*/
extern SmallSet Complement(SmallSet S);


/* Postcondition:
 *	Return TRUE if (x in S1 --> x in S2) AND
 *		       (x in S2 --> x in S1)
 *	       FALSE otherwise
*/
 extern Boolean Equals(SmallSet S1, SmallSet S2);


/* Postcondition:
 *	Print the elements of SmallSet S
*/
extern void Print(SmallSet S);
