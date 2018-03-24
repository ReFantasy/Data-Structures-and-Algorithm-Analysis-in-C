#include "introduction.h"
using namespace std;
//sort all number, return position k
int Select_K1(vector<int> array, int k)
{
    //sort array
    //sort(array.begin(), array.end());
	InsertSort(array);
    return array[array.size()-k];
}

//sort k numbers,then read one number to the k numbers of sorted every time
int Select_K2(vector<int> array, int k)
{
    //sort k number
    vector<int> k_number(array.begin(), array.begin()+k);
    //sort(k_number.begin(), k_number.end());
	InsertSort(k_number);
	int len = array.size();
    for(int i=k; i<len; i++)
    {
        if(array[i]<=k_number[0])
        {
            continue;
        }
        else
        {
            k_number[0] =array[i];
			int k_number_len = k_number.size();
            for(int j=0; j+1<k_number_len; j++)
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