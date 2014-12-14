// Multiply Strings
//   Author: flashhack
//   Update: 2014-12-14
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
    string multiply(string num1, string num2) {
		string res="";
		int data[100000];
		memset(data,0,sizeof(data));
		if(num1.length()<num2.length()) swap(num1,num2);
		int len1=num1.length(),len2=num2.length();
		reverse(num1.begin(),num1.end());
		reverse(num2.begin(),num2.end());
		for(int i=0;i<len1;i++)
			for(int j=0;j<len2;j++)
			{
				int digit=(num1[i]-'0')*(num2[j]-'0');
				//int single=digit%10,dec=digit/10;
				data[i+j]+=digit;
				int k=i+j;
				while(data[k]>=10)
				{
					data[k+1]+=data[k]/10;
					data[k]%=10;
					k++;
				}
			}
		int res_len=0;
		for(int i=len1+len2;i>=0;i--) 
			if(data[i]!=0) 
			{
				res_len = i; 
				break;
			}
		for(int i=res_len;i>=0;i--) res+=('0'+data[i]);
		return res;
    }
};

int main()
{
	Solution *s = new Solution();

	cout<<s->multiply("3","456")<<endl;


	system("pause");
	return 0;
}