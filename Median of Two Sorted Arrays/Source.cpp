#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int BinarySearch(int A[], int start, int from, int data)
	{
		int i=start, j=from;
		while(i<j)
		{
			int mid = (i + j) / 2;
			if(data <= A[mid]) j=mid-1;
			if(data > A[mid]) i=mid+1;
		}
		return i;
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		
	}
};

int main()
{
	return 0;
}