// Joseph Cycle
//   Author: flashhack
//   Update: 2015-03-21
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
1 2 3 4 5
i:[0,m-1 % n)
*/
void solve(list<int> data, int m){
	auto it=data.begin();
	while(!data.empty()){
		for(int i=0;i<(m-1)%data.size();++i)
			if(++it==data.end()) it=data.begin();
		cout<<*it<<endl;
		it=data.erase(it);
		if(it==data.end()) it=data.begin();
	}
}

/*
recursion: f(n,m) is the final answer (i th people is alive finally)

f(1,m) = 1;
f(n,m) = (f(n-1,m) + m-1) % n +1.
if already know a is the n-1 safe person, then n th safe person: a_next=(a+m-1)%n+1
*/

int f(int n, int m){
	if(n==1) return 1;
	return (f(n-1,m) + m-1) %n + 1;
}

int main()
{
	//solve({1,2,3,4,5},2);
	cout<<f(5,2)<<endl;

	system("pause");
	return 0;
}