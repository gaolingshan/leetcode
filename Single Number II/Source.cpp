// Single Number II
//   Author: flashhack
//   Update: 2015-01-09
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
    int singleNumber(int A[], int n) {
		int t1=0,t2=0,new_t1=0,new_t2=0;
		for(int i=0;i<n;i++)
		{
			new_t2=(t2^A[i])&(~t1);
			new_t1=(t1^A[i])&(t1|t2);
			t1=new_t1;
			t2=new_t2;
		}
		return t2;
    }
};

//2nd pass: 2015-03-11
/*
count by bit, occurance %3=final bit
*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int j=0;j<n;j++)
                cnt+=((A[j]>>i)&1);
            if(cnt%3) ans|=(1<<i);
        }
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[] ={1,1,1,2,2,2,6,3,3,3,4,4,4};
	cout<<s->singleNumber(A,13)<<endl;


	system("pause");
	return 0;
}