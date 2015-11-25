#define MAX 20
typedef struct {
	int id;
	int regstatus;
}Element;

typedef Element  ElementList[MAX];

typedef struct frame{
	Element e; 
	struct frame *next; 
}Frame;
typedef Frame *Link;
typedef Frame *StackTop;
