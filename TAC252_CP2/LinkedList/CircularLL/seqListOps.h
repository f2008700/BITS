/* file: seqListOps.h */

#include "seqList.h"

extern ListHead createList();

extern Element getElement(int pos, ListHead h);

extern void insertAtHead(Element e, ListHead h);

extern void insertAtTail(Element e, ListHead h);

extern void deleteFromHead(ListHead h);

extern void deleteFromTail(ListHead h);

extern void printList(ListHead h);

