// Find Peak Element
//   Author: flashhack
//   Update: 2015-01-13
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
	
	int search(const vector<int> &num, int left, int right)
	{
		if(left>right) return -1;
		if(left==right) return left;
		if(left==right-1)
		{
			int ll=(left==0)?INT_MIN:num[left-1];
			int rr=(right==num.size()-1)?INT_MIN:num[right+1];
			if(num[left]>ll && num[left]>num[right]) return left;
			if(num[right]>num[left] && num[right]>rr) return right;
			return -1;
		}
		int mid=left+((right-left)>>1);
		if(mid>left && mid<right && num[mid-1]<num[mid] && num[mid+1]<num[mid]) return mid;
		if(mid>left && num[mid-1]>num[mid]) return search(num,left,mid-1);
		if(mid<right && num[mid+1]>num[mid]) return search(num,mid+1,right); 
	}
    int findPeakElement(const vector<int> &num) {
		return search(num,0,num.size()-1);
    }
};

int main()
{
	Solution *s = new Solution();
	int A[]={1,2,3,1};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->findPeakElement(data)<<endl;



	system("pause");
	return 0;
}