#include<iostream>
#include<stdio.h>

using namespace std;

int BinarySearch( int* data, const int, const int);
bool BinaryInsertSorting(int* data, const int len)
{
/*
	BinaryInsertSorting is a improvement for InsertSorting
	TimeComplexity = O(n*log(n))
	SpaceComplexity = 1
*/
	int tmp ;
	int index;
	for(int i = 1; i < len; ++i)
	{
		tmp = data[i];
		index = BinarySearch(data, i, tmp);
		for(int j = i; j > index; --j)
		{
			data[j] = data[j-1];
		}	
		data[index] = tmp;
	}
	return true;
}

int BinarySearch(int* data, const int len, const int value)
{
	int i = 0; 
	int j = len-1;
	int m = (i+j)/2;
	while(j >= i)
	{
		if(value > data[m])
			i = m+1;
		else
			j = m-1;
		m = (i+j)/2;
	} 

	return i;
}

int main()
{
	int data[] = {6,3,5,3,1, 7};
	int len = 6;
	cout << "(int) half of -1 is " << (-1)/2 << endl;
	BinaryInsertSorting(data, len);
	for(int i = 0; i < len; ++i)
	{
		cout << ":" << data[i];
	}
	return 1;
}
