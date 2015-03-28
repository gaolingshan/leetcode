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
#include <functional>
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
class Solution_2nd {
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

//3rd pass: 2015-03-26
/*
use stack
use operator table, K:operator, V:function
num2 num1
should push back num2 op num1
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        unordered_map<string,function<int(int,int)>> optable={
            {"+",[](int a, int b){return a+b;}},
            {"-",[](int a, int b){return a-b;}},
            {"*",[](int a, int b){return a*b;}},
            {"/",[](int a, int b){return a/b;}}
        };
        stack<int> st;
        for(auto s:tokens){
            if(optable.count(s)!=0){
                int num1=st.top(); st.pop();
                int num2=st.top(); st.pop();
                st.push(optable[s](num2,num1));
            }else st.push(stoi(s));
        }
        return st.top();
    }
};

int main()
{
	//Solution *s = new Solution();


	system("pause");
	return 0;
}