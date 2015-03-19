// Remove Duplicates from Sorted Array II
//   Author: flashhack
//   Update: 2014-12-21
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution_old {
public:
    int removeDuplicates(int A[], int n) {
		if(n==0 || n==1) return n;
        bool isTwice=false;
		int left=0;
		for(int i=1;i<n;i++)
		{
			if(A[left] != A[i])
			{
				swap(A[i],A[++left]);
				isTwice=false;
			}
			else
			{
				if(!isTwice)
				{
					isTwice=true;
					swap(A[i],A[++left]);
				}
				else
					continue;
			}
		}
		return left+1;
    }
};

//2nd pass: 2015-02-22
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int left = -1, cnt = 0;
		for (int i = 0; i<n; i++)
		{
			if (left == -1 || A[i] != A[left] || (A[i] == A[left] && cnt<2))
			{
				if (left != -1 && A[left] == A[i]) cnt++; else cnt = 1;
				A[++left] = A[i];
			}
		}
		return left + 1;
	}
};

//3rd pass: 2015-03-18
/*
l pointer: where to place next number
cnt: count of A[l-1]
traverse i:[1,n), cnt=1
1. A[i]!=A[l-1], A[l++]=A[i]; cnt=1;
2. A[i]==A[l-1] && cnt==1, A[l++]=A[i], cnt=2;
3. A[i]==A[l-1] && cnt==2, not put

corner case, n==0;
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        int l=1,cnt=1;
        for(int i=1;i<n;++i){
            if(A[i]!=A[l-1]){ A[l++]=A[i]; cnt=1;}
			else if(cnt==1){ A[l++]=A[i]; cnt=2;}
        }
        return l;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[] = {1,1,1,2,2,3};
	
	int len=s->removeDuplicates(A,sizeof(A)/sizeof(int));

	for(int i=0;i<len;i++) cout<<A[i]<<" ";
	cout<<endl;


	system("pause");
	return 0;
}