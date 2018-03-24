#include <iostream>
#include <ctime>
#include "include.h"
#include "./Introduction/introduction.h"
using namespace std;

int main()
{
	srand(time(0));
	vector<int> array;
	for (int i = 0; i < 10000; i++)
		array.push_back(rand());
	clock_t t1 = clock();
	cout << Select_K1(array, 5000) << endl;
	clock_t t2 = clock();
	cout << Select_K2(array, 5000) << endl;
	clock_t t3 = clock();
	cout << t2 - t1 << endl;
	cout << t3 - t2 << endl;


	cout << endl;
	system("pause");
	return 0;
}