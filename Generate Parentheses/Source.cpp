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
	void dfs(vector<string>& res, string& now, int l, int r)
	{
		if(l==0 && r==0)
		{
			res.push_back(now);
			return;
		}
		if(l<=r && l>0)
		{
			now.push_back('(');
			dfs(res,now,l-1,r);
			now.resize(now.size()-1);
		}
		if(r>l)
		{
			now.push_back(')');
			dfs(res,now,l,r-1);
			now.resize(now.size()-1);
		}
	}

    vector<string> generateParenthesis(int n) {
        vector<string> result;
		string now = "";
		dfs(result,now,n,n);
		return result;
    }
};

//2nd pass: 2015-02-21
class Solution {
public:
    void dfs(vector<string>&res, string now, int l, int r)
    {
        if(l==0 && r==0)
        {
            res.push_back(now);
            return;
        }
        if(l>0) dfs(res,now+"(",l-1,r);
        if(r>l) dfs(res,now+")",l,r-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res,"",n,n);
        return res;
    }
};

int main()
{
	Solution *s = new Solution();

	vector<string> result = s->generateParenthesis(3);

	for(int i=0;i<result.size();i++)
	{
		cout<<result[i]<<endl;
	}

	system("pause");
	return 0;
}