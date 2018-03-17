#include <iostream>
#include "./tree/tree.h"
using namespace std;

int main()
{
    SearchTree T;
    MakeEmpty(T);
    T = Insert(T, 6);
    Insert(T, 3);
    Insert(T, 8);
    Insert(T, 1);
    Insert(T, 4);
    Insert(T, 7);
    Insert(T, 9);

    MidOrderPrintTree(T);

    printf("\n");
    return 0;
}