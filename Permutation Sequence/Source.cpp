#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool visited[10];
	string getPermutation(int n, int k) {
		string res = "";
		k--;
		int factorial=1;
		memset(visited,0,sizeof(visited));
		for(int i=1;i<n;i++) factorial *= i;
		int tmp = 0;
		for(int i=1; i<= n; i++)
		{
			tmp=k/factorial;
			int count=0;
			for(int j=0;j<n;j++)
				if(!visited[j])
				{
					if(count == tmp) 
					{
						res += char('0'+j+1);
						visited[j]=true;
						break;
					}
					count ++;
				}
			k %= factorial;
			if(i!=n)factorial /= n-i;
		}
		return res;
	}
};

int main()
{
	Solution *s = new Solution();

	cout << s->getPermutation(9,100) << endl;

	system("pause");
	return 0;
}

