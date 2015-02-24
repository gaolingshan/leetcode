// Jump Game II
//   Author: flashhack
//   Update: 2014-12-14
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
    int jump(int A[], int n) {
		if(n==1) return 0;
		int step=1,now=0,next=0;
		while(1)
		{
			next=now;
			for(int i=now;i>=0;i--) 
			{
				next=max(next, i+A[i]);
			}
			if(next>=n-1) return step;
			now=next;
			step++;
		}
    }
};

//2nd pass: 2015-02-23
class Solution {
public:
	int jump(int A[], int n) {
		int begin = 0, end = 0, step = 0, tmp = 0;
		while (end<n-1)
		{
			step++; tmp = 0;
			for (int i = begin; i <= end; i++) 
				tmp = max(tmp, i + A[i]);
			begin = end + 1;
			end = tmp;
		}
		return step;
	}
};

int main()
{
	Solution *s = new Solution();
	//int A[] = {1,1,1,1};
	int A[] = { 2, 3, 1, 1 ,4};
	cout<<s->jump(A,sizeof(A)/sizeof(int))<<endl;


	system("pause");
	return 0;
}