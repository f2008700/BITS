/* file: seqList.h */
#define MAX 20
typedef struct {
	int id;
	int regstatus;
}Element;

typedef Element  ElementList[MAX];

typedef struct node{
	Element e; 
	struct node *next; 
}Node;
typedef Node *Link;
typedef struct
{
	int size;
	Node *next;
}ListHead;
