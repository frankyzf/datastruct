#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

bool FilterDown(int* data, const int index, const int end);

bool HeapSorting(int* data, const int len)
{
/*
	HeapSorting firstly make heap (Filter Down from last leaves node)
		    Then, remove the top of head node one by one 
	Time Complexity = O(n*log(n))
*/
	//make heap first
	for(int i = (len-1)/2; i >=0 ; --i)
		FilterDown(data, i, len-1); 
	cout << "debug, after make heap:" << endl;
	for(int i = 0; i < len; ++i)
		cout << ":" << data[i];
	cout << endl;
	// fetch the heap top one by one
	for(int i  =  len -1; i >= 1; --i)
	{
		std::swap(data[0], data[i]);
		FilterDown(data, 0, i -1);
	}
	return true;
}

bool FilterDown(int* data, int index, const int end)
{
	int tmp = data[index];
	int child = 2* index+1; // left child
	while(child <= end)
	{
		if(child+1 <= end && data[child+1] > data[child])
			child ++;
		if(data[child] <= tmp)
			break;
		else
		{	
			data[index] = data[child];
			index = child;
			child = 2* index+1;
		}
	}
	data[index] = tmp;
	return true;
}

int main()
{
	int data[] = {6,3,5,3,1,7};
	int len = 6;
	HeapSorting(data, len);
	for(int i = 0; i < len; ++i)
		cout << ":" << data[i];
	cout << endl;
	return 1;
}
