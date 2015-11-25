/* file rectangleOps.h */
#include "rectangle.h"
#include "boolean.h"

extern Rect createRect(void);

extern Rect getData(Rect R1);

extern Boolean isSquare(Rect R1); 

extern Boolean isEqual(Rect R1, Rect R2);

extern int computeArea(Rect R1);

extern int findMaxArea(Rect RA[],int N);

extern void printRect(Rect R1);
