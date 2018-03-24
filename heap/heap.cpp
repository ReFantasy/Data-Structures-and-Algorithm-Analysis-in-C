#include "heap.h"
struct HeapStruct
{
    int Capacity;
    int size;
    int *Elements;
};

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue heap = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    if(!heap)
        return NULL;
    heap->Elements = (int *)malloc(sizeof(int)*(MaxElements+1));
    if(!heap->Elements)
    {
        free(heap);
        return NULL;
    }

    heap->Capacity = MaxElements;
    heap->size = 0;
    heap->Elements[0] = MinData;
    return heap;
}