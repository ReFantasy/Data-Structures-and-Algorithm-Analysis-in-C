#include <iostream>
#include <ctime>
#include "./tree/tree.h"
using namespace std;

int main()
{
    AvlTree T;
    AvlMakeEmpty(T);
    srand(time(0));
    for(int i=0; i<20; i++)
    {
        T = Insert(T, rand()%100);
    }
    

    MidOrderPrintAvlTree(T);

    printf("\n");
    return 0;
}