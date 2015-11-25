#define MAX 20
#define QueueSize 6

typedef struct {
	int id;
	int regstatus;
}Element;

typedef Element  ElementList[MAX];

typedef struct qframe{
	Element e; 
	struct qframe *next; 
}QFrame;
typedef QFrame *QLink;

typedef struct {
	int size;
	QLink front;
	QLink rear;
}QueueHead;
