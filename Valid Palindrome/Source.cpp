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

class Solution_old {
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

//2nd pass: 2015-02-22
class Solution_2nd {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.length()-1;
        while(left<=right)
        {
            while(left<s.length()&&!isalnum(s[left]))left++;
            while(right>=0&&!isalnum(s[right]))right--;
            if(left>=right) break;
            if(tolower(s[left])==tolower(s[right])) 
            {
                left++; right--;
            }
            else return false;
        }
        return true;
    }
};

//3rd pass: 2015-03-12
/*
two pointers l&r
1. proceed l&r if not alnum
2. make sure l<r
3. compare tolower(s[l])==tolower(s[r])
4. l++, r--
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length();
        while(1){
            while(l<s.length() && !isalnum(s[l])) ++l;
            while(r>=0 && !isalnum(s[r])) --r;
            if(l>=r) break;
            if(tolower(s[l++])!=tolower(s[r--])) return false;
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