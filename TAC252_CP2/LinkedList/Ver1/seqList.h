/* file: seqList.h */
#define MAX 20
typedef struct {
	int id;
	int regstatus;
}Element;

typedef Element  ElementList[MAX];

typedef struct {
	Element e; 
	int next; 
}Node;

typedef Node Store[MAX+3]; 
typedef int ListHead;

