/*file: dramaClubOps.h */
#include "dramaClubList.h"
#include "boolean.h"

/* Precondition:
 * size of ms is N
 * ms is a list of Member elements 
 *
 * Postcondition: 
 * m added to ms if not present present and over written if present.
 * return the size of the possibly updated list
*/ 
extern ListSize add(Member m, List ms, ListSize N);


/* Precondition:
 * size of ms is N
 * ms is a list of Member elements 
 *
 * Postcondition: 
 * m deleted from ms if present present, ms unchanged if not present.
 * return the size of the possibly updated list
*/ 
extern ListSize delete(Member m, List ms, ListSize N);


/* Precondition:
 * size of ms is N
 * Each element of ms can be matched against an ID 
 *
 * Postcondition: 
 * returs TRUE if ID matches against an element in ms FALSE otherwise.
*/ 
extern Boolean isMember(ID i, List ms, ListSize N);


