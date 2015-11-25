/* file: seqListOps.h */

#include "seqList.h"

extern ListHead createList();

extern Element getElement(int pos, ListHead h);

extern ListHead insertAtHead(Element e, ListHead h);

extern ListHead insertAtTail(Element e, ListHead h);

extern ListHead insertInPos(Element e, ListHead h, int pos);

extern ListHead insertAfterValue(Element e, ListHead h, int pos);

extern ListHead deleteFromHead(ListHead h);

extern ListHead deleteFromTail(ListHead h);

extern ListHead deleteValue(ListHead h, int val);

extern ListHead deletePos(ListHead h, int pos);

extern void printList(ListHead h);

