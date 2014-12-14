// <filename>.<ext>
//   Author: <name>
//   Update: <date>
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
    bool canJump(int A[], int n) {
		if(n==1) return true;
		int now=0,next=0;
		while(1)
		{
			next=now;
			for(int i=now;i>=0;i--) 
			{
				next=max(next, i+A[i]);
			}
			if(next>=n-1) return true;
			if(now==next) return false;
			now=next;
		}        
    }
};

int main()
{
	Solution *s = new Solution();
	int A[] = {3,2,1,0,4};
	cout<<s->canJump(A,5)<<endl;

	system("pause");
	return 0;
}