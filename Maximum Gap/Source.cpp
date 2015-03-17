// Maximum Gap
//   Author: flashhack
//   Update: 2015-01-14
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

//radix sort
class Solution_old {	
public:
	void countingSort(vector<int> &num, int base)
	{
		int n=num.size();
		vector<int> count(10,0);
		vector<int> output(n,0);
		for(int it:num)
			count[(it/base)%10]++;
		for(int i=1;i<10;i++) count[i]+=count[i-1];
		//trick here. fill back the result, need backward!!
		for(int i=num.size()-1;i>=0;i--)
		{
			int it=num[i];
			output[(count[(it/base)%10]--)-1]=it;
		}
		num=output;
	}
    int maximumGap(vector<int> &num) {
		if(num.size()<=1) return 0;
        //radix sort
		int maxNum=*max_element(num.begin(),num.end());
		int base=1;
		while(base <= maxNum)
		{
			countingSort(num,base);
			base *= 10;
		}
		//done
		int ans=0;
		for(int i=1;i<num.size();i++) ans=max(ans,num[i]-num[i-1]);
		return ans;
    }
};

//2nd pass: 2015-02-07
class Solution_2nd {
public:
    void countingSort(vector<int> &num, int base)
    {
        vector<int> count(10,0);
        vector<int> output(num.size(),0);
        for(int i=0;i<num.size();i++)
            count[(num[i]/base)%10]++;
        for(int i=1;i<10;i++)
            count[i]+=count[i-1];
        for(int i=num.size()-1;i>=0;i--)
            output[--count[(num[i]/base)%10]]=num[i];
        num=output;
    }
    int maximumGap(vector<int> &num) {
        if(num.size()<2) return 0;
        int max_num=*max_element(num.begin(),num.end());
        int base=1;
        while(base<=max_num)
        {
            countingSort(num,base);
            base*=10;
        }
        int ans=0;
        for(int i=1;i<num.size();i++) ans=max(ans,num[i]-num[i-1]);
        return ans;
    }
};

//3rd pass: 2015-03-17
/*
Bucket Sort
MAX, MIN, N. gap >= ceil (MAX-MIN)/N = len
num = (MAX-MIN)/len+1.  to make sure MIN+num*len > MAX
[MIN, MIN+len) [MIN+len,MIN+2len) ...   so number x belongs to #(x-MIN)/len

ans=len-1 at the beginning
1st pass: get bucket min/max & count. 
2nd pass: two consecutive cnt!=0 bucket, ans=max(ans, min_i - max_i-1)
*/
class Solution {
public:
    int maximumGap(vector<int> &num) {
        int N=num.size();
        if(N<2) return 0;
        int MAX=*max_element(num.begin(),num.end()), MIN=*min_element(num.begin(),num.end());
        int len=ceil((double)(MAX-MIN)/N), num_b=(MAX-MIN)/len+1;
        vector<vector<int>> bucket(num_b,{INT_MAX, INT_MIN, 0});
        for(int x:num){
            bucket[(x-MIN)/len][0]=min(bucket[(x-MIN)/len][0],x);
            bucket[(x-MIN)/len][1]=max(bucket[(x-MIN)/len][1],x);
            ++bucket[(x-MIN)/len][2];
        }
        int ans=len-1, prev=-1;
        for(int i=0;i<num_b;++i) if(bucket[i][2]){
            if(prev!=-1) ans=max(ans, bucket[i][0]-bucket[prev][1]);
            prev=i;
        }
        return ans;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[]={0,0,55,1,5,6};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->maximumGap(data)<<endl;


	system("pause");
	return 0;
}