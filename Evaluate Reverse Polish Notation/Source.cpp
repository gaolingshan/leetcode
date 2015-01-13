// Evaluate Reverse Polish Notation
//   Author: flashhack
//   Update: 2015-01-12
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
    int evalRPN(vector<string> &tokens) {
        vector<int> stack;
		int res=0,a=0,b=0;
		for(string it:tokens)
		{
			if(it=="+")
			{
				b=stack.back();
				stack.pop_back();
				a=stack.back();
				stack.pop_back();
				stack.push_back(a+b);
			}
			else
			if(it=="-")
			{
				b=stack.back();
				stack.pop_back();
				a=stack.back();
				stack.pop_back();
				stack.push_back(a-b);
			}
			else
			if(it=="*")
			{
				b=stack.back();
				stack.pop_back();
				a=stack.back();
				stack.pop_back();
				stack.push_back(a*b);
			}
			else
			if(it=="/")
			{
				b=stack.back();
				stack.pop_back();
				a=stack.back();
				stack.pop_back();
				stack.push_back(a/b);
			}
			else
			{
				stack.push_back(atoi(it.c_str()));
			}
		}
		if(stack.size() != 0)
			return stack.back();
		else
			return 0;
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}