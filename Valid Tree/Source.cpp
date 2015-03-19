// Valid Tree
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

class UnionFind{
/*
find: recurse until x==parent[x], then path compress when pop stack
union: 
	1. find parent of node x & y
	2. smaller size union merge into larger size union
num_union: count # of x==parent[x]
*/
private:
	vector<int> parent, total;
	int num;
public:
	UnionFind(int num_node):num(num_node){
		parent.clear(); total.clear();
		for(int i=0;i<num_node;++i){
			parent.push_back(i);
			total.push_back(1);
		}
	}
	int find(int x){
		if(parent[x]==x) return x;
		parent[x]=find(parent[x]);
	}
	void combine(int a, int b){
		int ax=find(a), bx=find(b);
		if(ax==bx) return;
		if(total[ax]>total[bx]){
			parent[bx]=ax;
			total[ax]+=total[bx];
		}else{
			parent[ax]=bx;
			total[bx]+=total[ax];
		}
	}
	int num_union(){
		int ans=0;
		for(int i=0;i<num;++i) if(parent[i]==i) ++ans;
		return ans;
	}
};

bool valid_tree(int n, vector<pair<int,int>> edges){
	UnionFind u(n);
	for(auto e:edges){
		if(u.find(e.first) == u.find(e.second)) return false;
		u.combine(e.first,e.second);
	}
	return u.num_union() == 1;
}

int main()
{


	system("pause");
	return 0;
}