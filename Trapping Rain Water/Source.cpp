// Trapping Rain Water
//   Author: flashhack
//   Update: 2014-12-13
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

class Solution_TwoPointer {
public:
    int trap(int A[], int n) {
        int left=0,right=0;
		int ans=0;
		while(right<n)
		{
			if(left==right) right++;
			else
			{
				if(A[right]<=A[left]) right++;
				else
				{
					for(int i=left;i<right;i++)ans+=A[left]-A[i];
					left=right;
				}
			}
		}
		left=n-1;
		right=n-1;
		while(left>=0)
		{
			if(left==right) left--;
			else
			{
				if(A[left]<A[right]) left--;
				else
				{
					for(int i=right;i>left;i--) ans += A[right]-A[i];
					right=left;
				}
			}
		}
		return ans;
    }
};

//stack
class Solution_old {
public:
    int trap(int A[], int n) {
        stack<int> st;
		int ans=0,tmp=0,h=0;
		for(int i=0;i<n;i++)
		{
			if(st.empty())st.push(i);
			else
			{
				if(A[i]<=A[st.top()])st.push(i);
				else
				{
					while(!st.empty())
					{
						h=A[st.top()];
						st.pop();
						if(st.empty())break;
						if(A[st.top()]<=A[i])ans+=(A[st.top()]-h)*(i-1-st.top());
						else
						{
							ans+=(A[i]-h)*(i-1-st.top());
							break;
						}
					}
					st.push(i);
					
				}
			}
		}
		return ans;
    }
};

//2nd pass: 2015-02-04
class Solution {
public:
    int trap(int A[], int n) {
        vector<int> st;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(st.empty() || A[i]<A[st.back()])
            {
                st.push_back(i);
                continue;
            }
            while(1)
            {
                int h=A[st.back()];
                st.pop_back();
                if(st.empty()) break;
                //two diff situation
                if(A[i]>A[st.back()])
                    ans += (A[st.back()]-h) * (i-st.back()-1);
                else
                {
                    ans += (A[i]-h) * (i-st.back()-1);
                    break;
                }
            }
            st.push_back(i);
        }
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();

	//int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	//int A[] = {2,1,0,2};
	//int A[] = {1,0,2};
	int A[] = {4,2,3};

	cout<<s->trap(A,sizeof(A)/sizeof(int))<<endl;


	system("pause");
	return 0;
}