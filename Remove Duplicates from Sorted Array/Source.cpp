#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution_old {
public:
    int removeDuplicates(int A[], int n) {
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(i==n-1 || A[i] != A[i+1]) 
				A[cnt++]=A[i];
		}
		return cnt;
    }
};

//2nd pass: 2015-02-22
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int left = -1;
		for (int i = 0; i < n; i++) 
			if (left==-1 || A[i] != A[left]) A[++left] = A[i];
		return left+1;
	}
};

int main()
{
	Solution *s = new Solution();
	int arr[] = {2, 2, 11, 11, 13,13,13,15};
	int len = s->removeDuplicates(arr, sizeof(arr) / sizeof(int));
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}
