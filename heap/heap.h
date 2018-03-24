#ifndef __HRAP_H__
#define __HRAP_H__
#include <stdlib.h>
#define MinData -10000;
struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;
PriorityQueue Initialize(int MaxElements);
#endif 