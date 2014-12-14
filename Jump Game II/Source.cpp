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

class Solution {
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

int main()
{
	Solution *s = new Solution();
	int A[] = {1,1,1,1};
	cout<<s->jump(A,4)<<endl;


	system("pause");
	return 0;
}