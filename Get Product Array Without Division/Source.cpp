// Get Product Array Without Division
//   Author: flashhack
//   Update: 2015-03-18
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
Examples:
Input: {2, 3, 4, 5}
Output: {60, 40, 30, 24}

from [1,n-1] get prodcut first, res[i]=res[i-1]*A[i-1]
from [n-2,0] get another part of product, prod*=A[i+1], res[i]*=prod
1 2 6 24
60 20 5 1
60 40 30 24
*/
vector<int> solve(vector<int> A){
	if(A.empty()) return {};
	int n=A.size();
	vector<int> res(n,1);
	for(int i=1;i<n;++i) res[i]=res[i-1]*A[i-1];
	for(int i=n-2, prod=1;i>=0;--i) {
		prod*=A[i+1];
		res[i]*=prod;
	}
	return res;
}

int main()
{
	auto res = solve({2,3,4,5});
	for(int v:res) cout<<v<<" ";
	cout<<endl;

	system("pause");
	return 0;
}