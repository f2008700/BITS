/* file: seqListOps.h */

#include "seqList.h"

extern ListHead createList();

extern RegInfo getRegInfo(int pos, ListHead h);

extern ListHead insertRegInfo(RegInfo R, ListHead h);

extern ListHead deleteRegInfo(RegInfo R, ListHead h);

extern ListHead insertInPos(RegInfo R, ListHead h, int pos);

extern void printList(ListHead h);

extern void printStore();

