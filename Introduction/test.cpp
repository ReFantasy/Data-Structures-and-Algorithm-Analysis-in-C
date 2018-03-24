#include "introduction.h"
#include <iostream>
using namespace std;

int main()
{
    vector<int> array;
    for(int i=0; i<10000; i++)
        array.push_back(rand());

    cout<<Select_K1(array, 10)<<endl;
    cout<<Select_K2(array, 10)<<endl;

    return 0;
}