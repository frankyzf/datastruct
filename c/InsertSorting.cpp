#include <iostream>
#include <stdio.h>

using namespace std;
bool InsertOneNode(int*, int, int);

bool InsertSorting (int* data, const int len)
{
/*
	insert sorting 
	time complexity = O(n^2)
	space complexity = 1
*/
	for(int i = 1; i < len; ++i)
	{
		int tmp = data[i];
		InsertOneNode(data, i, tmp);
	}
	return true;
}

inline bool InsertOneNode(int * data, const int len, const int value)
{
	// insert value into data[len]
	int i = 0;
	while(data[i] < value && i < len)
	{
		++i;
	}
	for(int j = len; j > i; --j)
	{	
		data[j] = data[j-1];	
	}
	data[i] = value;
	return true;
}

int main()
{
	int data[] = {6,3,5,3,1, 7};
	int len = 6;
	InsertSorting(data, len);
	for(int i = 0; i < len; ++i)
	{
		cout << ":" << data[i];
	}
	return 1;
}
