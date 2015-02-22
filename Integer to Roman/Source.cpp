// Integer to Roman
//   Author: flashhack
//   Update: 2014-12-13
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
    string intToRoman(int num) {
        string res="";
		char list[] = {'I','V','X','L','C','D','M'};
		int digit=0,base=1000,n=3;
		while(base > 0)
		{
			digit=num/base;
			int i=0;
			if(digit<=3)
				for(i=1;i<=digit;i++)
				{
					res += list[2*n];
				}
			if(digit==4)
			{
				res += list[2*n];
				res += list[2*n+1];
			}
			if(digit>=5 && digit <=8)
			{
				res += list[2*n+1];
				for(i=6;i<=digit;i++)
				{
					res += list[2*n];
				}
			}
			if(digit==9)
			{
				res += list[2*n];
				res += list[2*n+2];
			}
			num%=base;
			base/=10;
			n--;
		}
		return res;
    }
};

//2nd pass: 2015-02-21
class Solution {
public:
    string intToRoman(int num) {
		int numbers[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
		string romans[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string res="";
        while(num>0)
        {
			for(int i=12;i>=0;i--) if(num>=numbers[i])
            {
                while(num>=numbers[i]) 
                {
                    res+=romans[i];
                    num-=numbers[i];
                }
                break;
            }
        }
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->intToRoman(14)<<endl;

	system("pause");
	return 0;
}