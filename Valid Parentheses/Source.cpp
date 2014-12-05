#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> pstack;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='(' || s[i]=='[' || s[i]=='{') pstack.push(s[i]);
			if(s[i]==')' || s[i]==']' || s[i]=='}') 
			{
				if(pstack.size()==0) return false;
				char tmp = pstack.top();
				switch (tmp)
				{
				case '(':
					if(s[i] != ')') return false;
					break;
				case '[':
					if(s[i] != ']') return false;
					break;
				case '{':
					if(s[i] != '}') return false;
					break;
				}
				pstack.pop();
			}
		}
		if(pstack.size()!=0) return false;
		return true;
	}
};

int main()
{
	Solution *s = new Solution();

	cout << s->isValid("(((([])))") << endl;

	system("pause");
	return 0;
}