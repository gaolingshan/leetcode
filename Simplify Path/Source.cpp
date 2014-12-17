// Simplify Path
//   Author: flashhack
//   Update: 2014-12-17
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
    string simplifyPath(string path) {
        vector<string> st;
		string res="";
		string tmp="";
		bool find_dot=false;
		//simplify here
		path.push_back('/');
		for(int i=0;i<path.size();i++)
		{
			if(path[i]=='/') 
			{
				//trick here, /... could be a path
				if(tmp!="")
				{
					if(tmp=="..")
					{
						if(!st.empty()) st.pop_back();
					}
					else
						if(tmp!=".")
							st.push_back(tmp);
				}
				tmp="";
			}
			else
			{
				tmp+=path[i];
			}
		}
		

		for(int i=0;i<st.size();i++)
		{
			res+="/"+st[i];
		}
		if(st.size()==0) res="/";
		return res;

    }
};

int main()
{
	Solution *s = new Solution();
	cout << s->simplifyPath("/home/")<<endl;
	cout << s->simplifyPath("/a/./b/../../c/")<<endl;
	cout << s->simplifyPath("/../")<<endl;
	cout << s->simplifyPath("/home//foo/")<<endl;
	cout << s->simplifyPath("/...")<<endl;

	system("pause");
	return 0;
}