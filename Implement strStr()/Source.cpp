#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution_KMP_ugly {
public:
	int next[1000000];
	void get_next(char *u)
	{
		int p=2,k=0;
		memset(next,0,sizeof(next));
		while(u[p-1] != '\0')
		{
			if(u[p-1]==u[k]) 
			{
				next[p] = k+1;
				p++;
				k++;
			}
			else 
				k=next[k];
			if(k==0)
			{
				next[p]=k;
				p++;
			}
		}
	}

    int strStr(char *haystack, char *needle) {
		get_next(needle);
		int i=1,j=1;
		while(needle[j-1]!='\0') 
		{
			if(haystack[i-1] == '\0')
				return -1;
			if(haystack[i-1] == needle[j-1])
			{
				i++;
				j++;
			}
			else
				if(j==1) 
					i++; 
				else 
					j=next[j-1]+1;
		}
		return i-j;
    }
};

class Solution {
public:
	int next[100000];
	void get_next(char *u)
	{
		int p=2,k=0;
		memset(next,0,sizeof(next));
		while(u[p-1] != '\0')
		{
			if(u[p-1]==u[k]) next[p++] = ++k; else k=next[k];
			if(k==0) next[p++]=k;
		}
	}

    int strStr(char *haystack, char *needle) {
		get_next(needle);
		int i=1,j=1;
		while(needle[j-1]!='\0') 
		{
			if(haystack[i-1] == '\0') return -1;
			if(haystack[i-1] == needle[j-1])
			{
				i++; j++;
			}
			else
				if(j==1) i++; else j=next[j-1]+1;
		}
		return i-j;
    }
};


class Solution_BruteForce {
public:
    int strStr(char *haystack, char *needle) {
		int i=0;
		int len_a = strlen(haystack);
		int len_b = strlen(needle);
		while(haystack[i]!='\0')
		{
			if(i+len_b>len_a) break;
			int j=i,k=0;
			while(haystack[j] != '\0' && needle[k]!='\0')
			{
				if(haystack[j] == needle[k])
				{
					j++; k++;
				}
				else
					break;
			}
			if(needle[k]=='\0') return i; else i++;
		}
		if(haystack[0] == '\0' && needle[0]=='\0') return 0;
		return -1;
    }
};

int main()
{
	Solution *s = new Solution();
	char hay[] = "aaa";
	char need[] = "aaa";

	cout<< s->strStr(hay,need) <<endl;

	system("pause");
	return 0;
}
