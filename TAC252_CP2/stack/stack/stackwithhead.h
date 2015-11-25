#define MAX 20
#define StackSize 6

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

typedef struct {
	int size;
	Link top;
}StackTop;
