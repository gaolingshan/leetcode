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
    int removeElement(int A[], int n, int elem) {
        int cnt = 0;
		for(int i=0;i<n;i++)
		{
			if(A[i] != elem)
				A[cnt++]=A[i];
		}
		return cnt;
    }
};

int main()
{
	Solution *s = new Solution();
	int arr[] = {2, 2, 11, 11};
	int newLen = s->removeElement(arr,4,3);
	for(int i=0;i<newLen;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	system("pause");
	return 0;
}