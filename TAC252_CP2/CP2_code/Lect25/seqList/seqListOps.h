/* file: seqListOps.h */

#include "seqList.h"

extern ListHead createList();

extern RegInfo getRegInfo(int pos, ListHead h);

extern void insertRegInfo(RegInfo R, ListHead h);

extern void deleteRegInfo(RegInfo R, ListHead h);

extern void insertInPos(RegInfo R, ListHead h, int pos);

extern void printList(ListHead h);

extern void printStore();

