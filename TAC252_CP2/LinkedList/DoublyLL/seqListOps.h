/* file: seqListOps.h */

#include "seqList.h"

extern ListHead createList();

extern Element getElement(int pos, ListHead h);

extern void insertAtHead(Element e, ListHead h);

extern void insertAtTail(Element e, ListHead h);

extern void insertInPos(Element e, ListHead h, int pos);

extern void insertAfterValue(Element e, ListHead h, int pos);

extern void deleteFromHead(ListHead h);

extern void deleteFromTail(ListHead h);

extern void deleteValue(ListHead h, int val);

extern void deletePos(ListHead h, int pos);

extern void printList(ListHead h);

