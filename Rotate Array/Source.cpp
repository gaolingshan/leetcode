// Rotate Array
//   Author: flashhack
//   Update: 2015-02-24
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
	void reverse(int nums[], int n)
	{
		int left = 0, right = n - 1;
		while (left<right) swap(nums[left++], nums[right--]);
	}
	void rotate(int nums[], int n, int k) {
		if (n == 0) return;
		k %= n;
		reverse(nums, n);
		reverse(nums, k);
		reverse(nums + k, n - k);
	}
};

//2nd pass: 2015-03-12
/*
make k mod n first, in case large k
1. reverse whole
2. reverse 0~k-1
3. reverse k~n-1
*/
class Solution {
public:
    void reverse(int nums[],int begin, int end){
        while(begin<end) swap(nums[begin++],nums[end--]);
    }
    void rotate(int nums[], int n, int k) {
        if(n==0) return;
        k%=n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};

int main()
{
	//Solution *s = new Solution();

	system("pause");
	return 0;
}