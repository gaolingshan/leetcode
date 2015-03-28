// Largest subarray with equal number of 0s and 1s
//   Author: flashhack
//   Update: 2015-03-25
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
{1, 0, 1, 1, 1, 0, 0} -> 1,6
{1, 1, 1, 1} -> -1,-1
{0, 0, 1, 1, 0} -> 0,3 or 1,4

-1 -2 -1 0 -1
1. turn 0 to -1, calc accumulate sum[i]=0~i
2. build hash<sum[i],i>, i is the first one.
3. traverse i:[0,n-1]
	3.1 sum[i]==0, 0~i is one solution
	3.2  table[sum[i]] < i, -> table[sum[i]]+1 ~ i is one solution
*/
pair<int,int> solve(vector<int> data){
	int left=-1,right=-1,n=data.size();
	vector<int> sum(n,0);
	unordered_map<int,int> table;
	for(int i=0;i<n;++i) {
		sum[i]=(i==0)?0:sum[i-1];
		sum[i]+=(data[i]==0)?-1:1;
		if(table.count(sum[i])==0) table[sum[i]]=i;
	}
	for(int i=0;i<n;++i){
		if(sum[i]==0){
			if(left==-1 || i>right-left) {left=0; right=i;}
		}else{
			if(table[sum[i]]<i && i-table[sum[i]]-1 > right-left) {left=table[sum[i]]+1; right=i;}
		}
	}
	return make_pair(left,right);
}

int main()
{
	//vector<int> data={1, 0, 1, 1, 1, 0, 0};
	//vector<int> data={1, 1, 1, 1};
	vector<int> data={0, 0, 1, 1, 0};
	auto res=solve(data);
	cout<<res.first<<" "<<res.second<<endl;

	system("pause");
	return 0;
}
