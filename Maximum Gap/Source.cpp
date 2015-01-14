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
class Solution {	
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

int main()
{
	Solution *s = new Solution();
	int A[]={0,0,55,1,5,6};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->maximumGap(data)<<endl;


	system("pause");
	return 0;
}