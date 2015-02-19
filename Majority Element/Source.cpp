// Majority Element
//   Author: flashhack
//   Update: 2015-01-14
#include <iostream>
#include <sstream>
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
	int total;
	int search(vector<int> &num)
	{
		int mid=(num.size()>>1);
		int tmp=num[mid];
		vector<int> smaller, greater;
		for(int it:num) 
		{
			if(it<tmp) smaller.push_back(it);
			if(it>tmp) greater.push_back(it);
		}

		if(num.size()-smaller.size()-greater.size() > total/2) return tmp;
		if(smaller.size() > greater.size()) return search(smaller);
		return search(greater);
	}
    int majorityElement(vector<int> &num) {
		total=num.size();
		return search(num);
    }
};

//2nd pass: 2015-02-09
class Solution_2rd {
public:
    int majorityElement(vector<int> &num) {
        int left=0,right=num.size()-1,mid;
        while(left<=right)
        {
            mid=left+((right-left)>>1);
            int ll=left,rr=right,i=left,pivot=num[mid];
            while(i<=rr)
            {
                if(num[i]<pivot)
                {
                    swap(num[i],num[ll]);
                    i++; ll++;
                    continue;
                }
                if(num[i]==pivot)
                {
                    i++;
                    continue;
                }
                if(num[i]>pivot)
                {
                    swap(num[i],num[rr]);
                    rr--;
                }
            }
            int len=right-left+1, left_len=ll-left, right_len=right-rr, middle_len=rr-ll+1;
            if(middle_len > len/2) return pivot;
            if(left_len>right_len) right=ll-1; else left=rr+1;
        }
    }
};


//3rd pass: 2015-02-19
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int left=0,right=num.size()-1;
        while(1)
        {
            int l=left,r=right,pivot=num[l+((r-l)>>1)],i=left;
            while(i<=r)
            {
                if(num[i]<pivot) swap(num[i++],num[l++]);
                else if(num[i]==pivot) i++;
                else swap(num[i],num[r--]);
            }
            if(r-l+1 > num.size()/2) return pivot;
            else if(l-left>num.size()/2) right=l-1; else left=r+1;
        }
        return -1;
    }
};

int main()
{
	Solution *s = new Solution();
	//int A[]={1,2,2,2,3,3,2};
	//int A[]={4,5,4};
	//int A[]={12,52,12,70,12,61,12,12,50,72,82,12,11,25,28,43,40,12,12,53,12,12,98,12,12,92,81,2,12,15,40,12,12,9,12,31,12,12,12,12,77,12,12,50,12,12,12,93,41,92,12,12,12,12,12,12,12,12,12,37,48,14,12,70,82,12,80,12,12,12,12,56,30,12,8,12,50,12,20,12,21,97,12,42,12,10,12,38,73,15,9,11,79,12,12,28,51,12,15,12};
	int A[]={32,32,58,32,32,32,32,32,50,77,77,32,32,32,51,32,61,32,32,88,44,32,7,32,32,92,28,1,32,32,44,97,99,32,1,40,32,20,32,68,85,32,32,32,32,98,13,32,32,7,74,32,32,52,32,86,28,45,73,19,32,32,27,32,83,32,68,94,32,32,32,32,27,24,32,32,96,32,99,60,46,32,22,71,25,32,32,32,32,53,54,26,32,32,32,32,13,32,23,6};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->majorityElement(data)<<endl;

	//for(auto it:data) cout<<it<<" ";

	system("pause");
	return 0;
}