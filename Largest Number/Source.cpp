// Largest Number
//   Author: flashhack
//   Update: 2015-01-14
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

class Solution_old {
public:
	struct cmp
	{
		bool operator() (const int a, const int b)
		{
			int digitsA=(a!=0)?(int)log10(a)+1:1;
			int digitsB=(b!=0)?(int)log10(b)+1:1;
			long long ab=(int)pow(10,digitsB) * a + b;
			long long ba=(int)pow(10,digitsA) * b + a;
			if(ab > ba) return true; else return false;
		}
	}cmp_object;


    string largestNumber(vector<int> &num) {
		sort(num.begin(),num.end(),cmp_object);
		string res="";
		bool isFirstZero=true;
		for(int it:num) 
		{
			if(it!=0) isFirstZero=false; 
			if(it!=0 || !isFirstZero)res+=to_string(it);
		}
		if(res=="")return "0"; else
		return res;
    }
};

//2nd pass: 2015-03-11
/*
sort numbers: xy VS. yx
1. x==0 || y==0, do log10 careful
2. all zeros
*/
class Solution {
public:
	struct cmp_struct{
		bool operator () (int x, int y){
			int lenX=(x==0)?1:log10(x)+1, lenY=(y==0)?1:log10(y)+1;
			//100 -> 2, 1000->3
			long long xy=x*pow(10,lenY)+y, yx=y*pow(10,lenX)+x;
			return xy > yx;		
		}
	}cmp_obj;
    string largestNumber(vector<int> &num) {
        sort(num.begin(),num.end(),cmp_obj);
        string res="";
		bool notZero=false;
		for(int v:num){
			if(v!=0) notZero=true;
			if(v!=0 || notZero)res+=to_string(v);
		}
        return (res=="")?"0":res;
    }
};

int main()
{
	Solution *s = new Solution();
	//int A[] = {3, 30, 34, 5, 9};
	//int A[] = {121, 12};
	//int A[] = {0,1};
	int A[] = {0};
	vector<int> data(A,A+sizeof(A)/sizeof(int));
	cout<<s->largestNumber(data)<<endl;

	system("pause");
	return 0;
}