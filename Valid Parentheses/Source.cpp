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

class Solution_old {
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

//2nd pass: 2015-02-21
//3rd pass: 2015-03-18
/*
1. left bra, just push
2. right bra
    2.1 check stack NULL, false
    2.2 check stack top, if not correspond, false
    2.3 pop
3. check stack NULL at the end
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s)
        {
            if(c=='('||c=='['||c=='{') st.push(c);
            else
            {
                if(st.empty()) return false;
                if(c==')' && st.top()!='(') return false;
                if(c==']' && st.top()!='[') return false;
                if(c=='}' && st.top()!='{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};


int main()
{
	Solution *s = new Solution();

	cout << s->isValid("(((([])))") << endl;

	system("pause");
	return 0;
}
