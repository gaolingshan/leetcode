// Maximum Expression Value
//   Author: flashhack
//   Update: 2015-02-25
#include <iostream>
#include <sstream>
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


class Solution{
public:
	int maxValue(vector<int> nums){
		int N = nums.size();
		vector<vector<int>> f(N, vector<int>(N, 0));
		for (int i = 0; i<N; i++) f[i][i] = nums[i];
		for (int i = 0; i<N; i++)
			for (int len = 2; i + len - 1<N; len++)
			{
				for (int j = i; j + 1 <= i + len - 1; j++){
					f[i][i + len - 1] = max(f[i][i + len - 1], f[i][j] + f[j + 1][i + len - 1]);
					f[i][i + len - 1] = max(f[i][i + len - 1], f[i][j] * f[j + 1][i + len - 1]);
				}
			}
		return f[0][N - 1];
	}
};

int main() {
	vector<int> data = { 3, 1, 3 };
	Solution s;
	cout << s.maxValue(data) << endl;

	getchar();
	return 0;
}