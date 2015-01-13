// Min Stack
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

class MinStack {
public:
	stack<int> st_main;
	stack<int> st_min;
    void push(int x) {
		st_main.push(x);
		//trick here! must be <=. otherwise element will be missing when pop
		if(st_min.empty() || x<=st_min.top())st_min.push(x);
    }

    void pop() {
		if(st_main.empty()) return;
		//same here. before any pop, must check isempty
		if(!st_min.empty() && st_main.top()==st_min.top()) st_min.pop();
		st_main.pop();
    }

    int top() {
		if(st_main.empty()) return 0;
        return st_main.top();
    }

    int getMin() {
		if(st_main.empty()) return 0;
        return st_min.top();
    }
};

int main()
{
	MinStack *s = new MinStack();
	s->push(0);
	s->push(1);
	s->push(0);
	//s->push(1);
	cout<<s->getMin()<<endl;
	s->pop();
	cout<<s->getMin()<<endl;
	s->pop();


	system("pause");
	return 0;
}