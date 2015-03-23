#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution_old {
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


//2nd pass:  2015-02-24
class Solution_2nd {
public:
	string getPermutation(int n, int k) {
		k--;
		int total = 1;
		for (int i = 2; i <= n; i++) total *= i;
		string candidates = "", res = "";
		for (int i = 1; i <= n; i++) candidates += to_string(i);
		for (int i = 0; i<n; i++)
		{
			total /= (n - i);
			int idx = k / total;
			res += candidates[idx];
			candidates.erase(idx, 1);
			k %= total;
		}
		return res;
	}
};

//3rd pass: 2015-03-22
/*
n number has n! permutation
loop until n==1
num idx: k/(n-1)!
k = k%(n-1)!
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        --k;
        int fac=1;
        for(int i=2;i<n;++i) fac*=i;
        string res,nums;
        for(int i=1;i<=n;++i) nums.push_back('0'+i);
        while(n>1){
            int idx=k/fac;
            res.push_back(nums[idx]);
            nums.erase(nums.begin()+idx);
            k=k%fac;
            fac/=--n;
        }
        res.push_back(nums[0]);
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

