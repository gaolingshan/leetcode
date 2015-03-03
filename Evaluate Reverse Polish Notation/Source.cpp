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

class Solution_old {
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

//2nd pass: 2015-02-27
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                st.push(num1+num2);
            }else
            if(tokens[i]=="-"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                st.push(num1-num2);
            }else
            if(tokens[i]=="*"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                st.push(num1*num2);
            }else
            if(tokens[i]=="/"){//Attention! must perserve order of num1 & num2
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                st.push(num1/num2);
            }else
				st.push(stoi(tokens[i]));
        }
        if(st.empty()) return 0; else return st.top();
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}