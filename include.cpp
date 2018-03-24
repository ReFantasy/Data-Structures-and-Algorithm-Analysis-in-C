#include "include.h"
void InsertSort(vector<int> &array)
{
	int len = array.size();
	for (int i = 1; i < len; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}