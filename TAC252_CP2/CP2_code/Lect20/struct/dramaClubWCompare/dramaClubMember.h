/* file: dramaClubMemeber.h */
#ifndef DRAMACLUBMEMBER_H
#define DRAMACLUBMEMBER_H
typedef unsigned int ID;
typedef enum {A1=1,A2,B1,B2,C1,C2,D1,D2}Group;

#define NAME_LEN 50

typedef struct
{
	ID i;
	char n[NAME_LEN];
	Group g;
}Member;
#endif
