/* file: seqList.h */
#define NUM_CS 15
#define MAX 20

typedef int ID;
typedef int Year;
typedef struct {
	ID i; 	       
	Year y; 
	char name[MAX];
}Student;

typedef enum {DENY=1, SUCC=2, CON=3}RegStatus;
typedef unsigned int Code;
typedef char String[MAX];
typedef enum { LEC=1, COMPRE=2, DTC=3 } Conflict;

typedef struct {
	Student st;
	RegStatus rs;
	union {
		Code courses[NUM_CS];
		String regRest;
		Conflict   con;			
	} rd;
} RegInfo;

typedef RegInfo  RegList[MAX];

typedef struct {
	RegInfo ri; 
	int next; 
} Element;

typedef Element Store[MAX+3]; 
typedef int ListHead;

