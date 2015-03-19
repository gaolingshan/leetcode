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
"Old panda is a big fat panda and smart panda. "£¬µ¥´Êpanda£¬ÕÒ×î¶Ì¾àÀë(BB)

two pointers prev=-1 & i=-1;
every step, find next string start from i+1, 
1. prev not -1, update ans=min(ans,i-prev);
2. prev=i;
until i=not found
*/
int solve1(string S, string T){
	int prev=-1,i=-1,ans=INT_MAX;
	while(1){
		i=S.find(T,i+1);
		if(i==-1) break;
		if(prev!=-1) ans=min(ans,i-prev);
		prev=i;
	}
	return (ans==INT_MAX)?-1:ans;
}

/*
input: "     the   sky is   blue    ", output: "the sky is blue". Remove Duplicate¿Õ¸ñ(BB)
pointer l: where should place char
traverse with i, 
1. not space, s[l++]=s[i++];
2. is space
	2.1 (i!=0 && s[i-1] not space), s[l++]=s[i++];
	2.2 (dup space case) i++
resize s to l
*/
string solve2(string s){
	int l=0;
	for(int i=0;i<s.length();++i)
		if(s[i]!=' ' || (i!=0 && s[i-1]!=' '))  s[l++]=s[i]; 
	if(s[l-1]==' ')--l;
	s.resize(l);
	return s;
}

int main()
{
	//cout<<solve1("Old panda is a big fat panda and smart panda.","panda")<<endl;
	cout<<solve2("     the   sky is   blue    ")<<endl;
	system("pause");
	return 0;
}