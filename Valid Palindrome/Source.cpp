// Valid Palindrome
//   Author: flashhack	
//   Update: 2015-01-07
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
    bool isPalindrome(string s) {
		int len=s.length();
		if(len==0) return true;
		int left=0,right=len-1;
		while(left<right)
		{
			while(left<len && !isalnum(s[left]))left++;
			while(right >=0 && !isalnum(s[right]))right--;
			if(left>=right) break;
			if(tolower(s[left++])!=tolower(s[right--])) return false;
		}
		return true;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->isPalindrome("A man, a plan, a canal: Panama")<<endl;
	cout<<s->isPalindrome("race a car")<<endl;


	system("pause");
	return 0;
}