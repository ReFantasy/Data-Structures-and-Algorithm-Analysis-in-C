#include <iostream>
#include <random>
#include <time.h>
#include <vector>

using namespace std;

//冒泡排序
template<typename T>
void BubbleSort1A(T A[], int n)
{
	bool isSorted = false;
	while (!isSorted)
	{
		isSorted = true;

		for (int i = 1; i < n; i++)
		{
			if (A[i - 1] > A[i])
			{
				swap(A[i - 1], A[i]);
				isSorted = false;
			}
		}
		n--;
	}
}

int main()
{
	//生成随机数组
	default_random_engine e(time(0));
	uniform_int_distribution<int> R;
	const int N = 10000;
	const int k = N/2;

	int arrray1[N];
	int arrray2[N];
	for (int i = 0; i < N; i++)
		arrray1[i] = arrray2[i] = R(e);
	

	

	//方法一：全排序，取第K个值
	clock_t t0 = clock();
	sort(begin(arrray1), end(arrray1));
	//BubbleSort1A(arrray1, N);
	clock_t t1 = clock();
	cout << "time1: " <<t1 - t0 << endl;
	cout << arrray1[N - k] << endl;

	cout << endl;
	//方法二：取k个值排序，然后将剩下的值逐一加入k个值的数组。
	clock_t t2 = clock();
	sort(begin(arrray2), begin(arrray2) + k);
	//BubbleSort1A(arrray2, k);
	for (int i = k; i < N; i++)
	{
		if (arrray2[0] >= arrray2[i])
		{
			continue;
		}
		else
		{
			arrray2[0] = arrray2[i];
			for (int i = 0; i < k - 1; i++)
			{
				if (arrray2[i] > arrray2[i + 1])
					swap(arrray2[i], arrray2[i + 1]);
				else
					break;
			}
		}
	}
	clock_t t3 = clock();
	cout << "time2: " <<t3 - t2 << endl;
	cout << arrray2[0] << endl;


	return 0;
}