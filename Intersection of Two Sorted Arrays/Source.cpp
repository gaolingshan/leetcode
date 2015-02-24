// Intersection of Two Sorted Arrays
//   Author: flashhack
//   Update: 2015-02-22
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

vector<int> intersection(vector<int>& a, vector<int>& b) {
	vector<int> res;
	for (int i = 0, j = 0; i<a.size() && j<b.size();)
	{
		if (a[i] == b[j])
		{
			res.push_back(a[i]);
			i++; j++;
		}
		else if (a[i]>b[j]) j++; else i++;
	}
	return res;
}

int main()
{
	vector<int> a = { 1, 2, 3, 4 };
	vector<int> b = { 1, 3, 5, 7 };
	auto res = intersection(a, b);
	for (int v : res) cout << v << " ";
	cout << endl;

	system("pause");
	return 0;
}