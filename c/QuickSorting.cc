#include<iostream>
#include<stdio.h>

using namespace std;
bool QuickSorting(int* data, const int start, const int end)
{
	if(start < end)
	{
		int pivotindex = start;
		int pivot = data[start];
		for( int i = start; i <= end; ++i)
		{
			if(data[i] < pivot)
			{
				++ pivotindex;
				if( pivotindex != i)
				{
					std::swap(data[pivotindex], data[i]);
				}
				
			}
		}
		std::swap(data[pivotindex], data[start]);
		QuickSorting(data, start, pivotindex -1);
		QuickSorting(data, pivotindex +1, end);
	}	
	return true;
}

int main()
{
	int data[] = {6,3,5,3,1, 7};
	int len = 6;
	QuickSorting(data, 0, len-1);
	for(int i = 0; i < len; ++i)
	{
		cout << ":" << data[i];
	}
	cout << endl;
	return 1;
}
