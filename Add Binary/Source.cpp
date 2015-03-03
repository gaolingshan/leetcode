// Add Binary 
//   Author: flashhack
//   Update: 2014-12-16
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
    string addBinary(string a, string b) {
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		if(a.length()<b.length()) swap(a,b);
		string res="";
		int digit=0;
		for(int i=0;i<a.length();i++)
		{
			digit=a[i]-'0';
			if(res.length()>i) digit += res[i]-'0';
			if(b.length()>i) digit+=b[i]-'0';
			if(res.length()>i)
				res[i]='0'+digit;
			else
				res.push_back('0'+digit);
			int j=i;
			while((res[j]-'0') / 2)
			{
				if(res.length()>j+1)res[j+1]+=(res[j]-'0')/2;
				else
					res.push_back('0'+(res[j]-'0')/2);
				res[j]='0'+(res[j]-'0')%2;
				if(res.length()>j+1) j++;
			}
		}
		reverse(res.begin(),res.end());
		return res;
    }
};

//Need improve, more compact
//2nd Pass: 2015-02-04
class Solution_2nd {
public:
    string addBinary(string a, string b) {
        string res="";
        int lenA=a.length();
        int lenB=b.length();
        if(lenB>lenA) 
        {
            swap(a,b);
            swap(lenA,lenB);
        }
        int i=lenA-1,j=lenB-1;
        int numA=0,numB=0,numC=0;
        while(i>=0)
        {
            numA=a[i]-'0';
            numB=(j>=0)?b[j]-'0':0;
            int tmp=numA+numB+numC;
            res.insert(res.begin(),'0'+tmp%2);
            numC=tmp/2;
            i--;j--;
        }
        if(numC!=0) res.insert(res.begin(),'0'+numC);
        return res;
    }
};

//3rd pass: 2015-02-27
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length()<b.length()) swap(a,b);
        int lenA=a.length(), lenB=b.length(), carry=0;
        for(int i=lenA-1,j=lenB-1;i>=0;i--,j--){
            int numA=a[i]-'0', numB=(j>=0)?(b[j]-'0'):0;
            int num=numA+numB+carry;
            a[i]='0'+num%2;
            carry=num/2;
        }
        if(carry!=0) a.insert(a.begin(),'0'+carry);
        return a;
    }
};

int main()
{
	Solution *s = new Solution();
	cout << s->addBinary("1","11")<<endl;


	system("pause");
	return 0;
}