// Plus One
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

//only 8ms! Not reversing the digits!
class Solution_old {
public:
    vector<int> plusOne(vector<int> &digits) {
		if(digits.empty())
		{
			digits.push_back(1);
			return digits;
		}
		int len=digits.size();
		digits[len-1]+=1;
		int residue=digits[len-1]/10;
		digits[len-1]%=10;
		int i=len-2;
		while(residue)
		{
			if(i>=0) 
			{
				digits[i]+=residue;
				residue=digits[i]/10;
				digits[i]%=10;
				i--;
			}
			else
			{
				digits.insert(digits.begin(),residue);
				residue=0;
			}
		}
		return digits;
    }
};

//2nd pass: 2015-02-25
class Solution {
public:
	int add(int a, int b){
		while (b){
			int sum = a^b;
			int carry = (a&b) << 1;
			a = sum;
			b = carry;
		}
		return a;
	}
	vector<int> plusOne(vector<int> &digits) {
		int len = digits.size();
		if (len == 0) return vector<int>(1, 1);

		int i = len - 1, carry = 1;
		while (1){
			int sum = (digits[i] + carry) % 10;
			carry = (digits[i] + carry) / 10;
			digits[i] = sum;
			if (carry == 0) break;
			if (i == 0){
				digits.insert(digits.begin(), carry);
				break;
			}
			i--;
		}
		return digits;
	}
};

int main()
{
	Solution *s = new Solution();
	int A[] = {9,9,9,9};
	vector<int> digits(A,A+sizeof(A)/sizeof(int));
	vector<int> res = s->plusOne(digits);
	for(auto it : res) cout<<it;
	cout<<endl;


	system("pause");
	return 0;
}