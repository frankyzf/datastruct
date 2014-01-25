#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

bool BubbleSorting(int* data, const int len)
{
/*
	Bubbule Sorting
	Time Complexity = O(n^2)
	Space Complexity = 1;
*/
	int tmp ;
 	for(int i = 1; i < len; ++i)
	{
		for(int j = i; j > 0; -- j)
		{
			if( data[j] >= data[j-1])
				break;
			else
				std::swap(data[j], data[j-1]);
		}
	}	
	return true;
}


int main()
{
	int data[] = {6,3,5,3,1, 7};
	int len = 6;
	BubbleSorting(data, len);
	for(int i = 0; i < len; ++i)
	{
		cout << ":" << data[i];
	}
	cout << endl;
	return 1;
}
