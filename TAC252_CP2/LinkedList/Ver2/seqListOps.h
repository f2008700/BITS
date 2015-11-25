/* file: seqListOps.h */

#include "seqList.h"

extern void createStore();

extern ListHead createList();

extern Element getElement(int pos, ListHead h);

extern void insertNode(Element e, ListHead h);

extern void deleteNode(Element e, ListHead h);

extern void insertInPos(Element e, ListHead h, int pos);

extern void printList(ListHead h);

extern void printStore();

