// Compare Version Numbers
//   Author: flashhack
//   Update: 2015-01-14
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

class Solution_strtok_fail {
public:
    int compareVersion(string version1, string version2) {
		char *v1 = strdup(version1.c_str());
		char *v2 = strdup(version2.c_str());
		char* tmp1=strtok(v1,".");
		char* tmp2=strtok(v2,".");
		while(tmp1!=NULL || tmp2!=NULL)
		{
			if(tmp1==NULL) return -1;
			if(tmp2==NULL) return 1;
			int a=atoi(tmp1);
			int b=atoi(tmp2);
			if(a>b) return 1;
			if(a<b) return -1;
			tmp1=strtok(NULL,".");
			tmp2=strtok(NULL,".");
		}
		return 0;
    }
};

class Solution_old {
public:
    int compareVersion(string version1, string version2) {
		istringstream ss1(version1);
		istringstream ss2(version2);
		string v1,v2;
		while(1)
		{
			bool b1=(bool)getline(ss1,v1,'.');
			bool b2=(bool)getline(ss2,v2,'.');
			if(!b1 && !b2) return 0;
			if(!b1) 
			{
				int b=atoi(v2.c_str());
				if(b==0) continue; else
				return -1;
			}
			if(!b2) 
			{
				int a=atoi(v1.c_str());
				if(a==0) continue; else
				return 1;
			}
			int a=atoi(v1.c_str());
			int b=atoi(v2.c_str());
			if(a>b) return 1;
			if(a<b) return -1;		
		}
		return 0;
    }
};

//2nd pass: 2015-02-07
class Solution_2nd {
public:
    int compareVersion(string version1, string version2) {
        istringstream ss1(version1);
        istringstream ss2(version2);
        string tmp1,tmp2;
        bool b1,b2;
        while(1)
        {
            b1=(bool)getline(ss1,tmp1,'.');
            b2=(bool)getline(ss2,tmp2,'.');
            if(b1&&b2)
            {
                int num1=stoi(tmp1), num2=stoi(tmp2);
                if(num1<num2) return -1;
                if(num1>num2) return 1;
                continue;            
            }
            if(b1)
            {
                int num1=stoi(tmp1);
                int num2=0;
                if(num1<num2) return -1;
                if(num1>num2) return 1;
                continue;            
            }
            if(b2)
            {
                int num1=0;
                int num2=stoi(tmp2);
                if(num1<num2) return -1;
                if(num1>num2) return 1;
                continue;            
            }
            break;
        }
        return 0;
    }
};

//3rd pass: 2015-03-17
/*
partition by '.'

corner case:
1.0.0.0.0.0
1.0
if one finish, other must all be 0.
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream ss1(version1),ss2(version2);
        string tmp1, tmp2;
        while(1){
            bool b1=(bool)getline(ss1,tmp1,'.');
            bool b2=(bool)getline(ss2,tmp2,'.');
            if(!b1 && !b2) break;
            if(b1 && b2){
                if(stoi(tmp1) > stoi(tmp2)) return 1;
                if(stoi(tmp1) < stoi(tmp2)) return -1;
                continue;
            }
            if(b1 && stoi(tmp1)!=0) return 1;
            if(b2 && stoi(tmp2)!=0) return -1;
        }
        return 0;
    }
};


int main()
{
	Solution *s = new Solution();
	cout<<s->compareVersion("1.0.1","1")<<endl;

	system("pause");
	return 0;
}