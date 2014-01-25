#include<iostream>
#include<algorithm>
#include<assert.h>
#include<string.h>

using namespace std;
#define MAXBUF 128

bool merge(int* data, int left, int step, int right);

bool MergeSorting(int* data, const int len)
{
/*
	Time Complexity = O(n* log(n))
*/
	for ( int i = 1; i < len ; i *= 2)
	{
		for(int j = 0; j < len; j += 2*i)
		{ // [left_start, left_start+ j-1][left_start + j,right]
			int right_end = j+2*i-1;
			if(right_end > len)
				right_end = len -1 ;
			merge(data, j, i, right_end );	
		}
	}
	return true; 
}

bool merge(int* data, int left_start, int step, int right_end)
{
	int left_end = left_start + step -1;
	int right_start = left_start + step; 
	if(left_end >= right_end)
		return true; // only 1 pair and return directly
	
	int tmp[MAXBUF];
	int len = right_end - left_start+1;
	assert(len < MAXBUF);
        int li = left_start;
	int ri = right_start;
	int i = 0;

	while(li <= left_end && ri <= right_end)
	{
		if(data[li]< data[ri])
			tmp[i++] = data[li++];
		else
			tmp[i++] = data[ri++];
	} 
	while(li <= left_end)
		tmp[i++] = data[li++];		
	while(ri <= right_end)
		tmp[i++] = data[ri++];
	memcpy(data+left_start, tmp, sizeof(int) * len);
	for(int i = 0; i < len; ++i)
 		cout << ":" << tmp[i];
	cout << endl;
	return true;
}

int main()
{
	int data[] = {6,3,5,3,1, 7};
	int len = 6;
	MergeSorting(data, len);
	for(int i = 0; i < len; ++i)
	{
		cout << ":" << data[i];
	}
	cout << endl;
	return 1;
}
