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

class Solution {
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

int main()
{
	Solution *s = new Solution();
	int arr[] = {2, 2, 11, 11};

	for(int i=0;i<s->removeDuplicates(arr,4);i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}
