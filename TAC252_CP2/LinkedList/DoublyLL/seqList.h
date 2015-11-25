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
	struct node *prev; 
}Node;
typedef Node *Link;
typedef Node *ListHead;
