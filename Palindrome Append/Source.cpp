// 
//   Author: 
//   Update: 
#include <iostream>
#include <functional>
#include <bitset>
#include <chrono>
#include <exception>
#include <fstream>
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
#include <deque>
#include <stack>
using namespace std;

/*
banana
find longest palindrome suffix, append reverse of non suffix part
*/
bool isPalindrome(string s){
	int left=0,right=s.length()-1;
	while(left<right){
		if(s[left]==s[right]){
			++left; --right;
		}else return false;
	}
	return true;
}

int solve(string s){
	for(int i=0;i<s.length();++i) if(isPalindrome(s.substr(i))) return i;
	return s.length();
}

/*
banana
build string ananab$banana
             0012300012345
find longest suffix==prefix, this is KMP preprocessing
next[0]=-1 boundary, next[i] means [0~i-1] longest suffix==prefix
i:[0,len), k=next[i]
compare s[i]&s[k] until k==-1
next[i+1]=k+1
*/

int solve2(string s){
	int len=s.length();
	string tmp=s;
	reverse(tmp.begin(),tmp.end());
	tmp+="$"+s;
	vector<int> next(tmp.length()+1,-1);
	for(int i=0;i<tmp.length();++i){
		int k=next[i];
		while(k!=-1 && tmp[i]!=tmp[k]) k=next[k];
		next[i+1]=k+1;
	}
	return s.length() - *max_element(next.begin(),next.end());
}

int main()
{
	cout<<solve("banana")<<endl;
	cout<<solve("coco")<<endl;
	cout<<solve("abc")<<endl;
	cout<<solve("ab")<<endl;
	cout<<solve("baloo")<<endl;
	cout<<endl;
	cout<<solve2("banana")<<endl;
	cout<<solve2("coco")<<endl;
	cout<<solve2("abc")<<endl;
	cout<<solve2("ab")<<endl;
	cout<<solve2("baloo")<<endl;


	system("pause");
	return 0;
}