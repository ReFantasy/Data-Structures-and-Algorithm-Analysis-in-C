#include "introduction.h"
using namespace std;
//sort all number, return position k
int Select_K1(vector<int> array, int k)
{
    //sort array
    sort(array.begin(), array.end());

    return array[array.size()-k];
}

//sort k numbers,then read one number to the k numbers of sorted every time
int Select_K2(vector<int> array, int k)
{
    //sort k number
    vector<int> k_number(array.begin(), array.begin()+k);
    sort(k_number.begin(), k_number.end());

    for(int i=k; i<array.size(); i++)
    {
        if(array[i]<=k_number[0])
        {
            continue;
        }
        else
        {
            k_number[0] =array[i];
            for(int j=0; j+1<k_number.size(); j++)
            {
                if(k_number[j]>k_number[j+1])
                {
                    swap(k_number[j], k_number[j+1]);
                }
                else
                {
                    break;
                }
            } 
        }
    }

    return k_number[0];
}