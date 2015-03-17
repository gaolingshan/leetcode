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

class Solution_KMP {
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

//2nd pass: 2015-02-21
class Solution_BF_2nd {
public:
    int strStr(char *haystack, char *needle) {
        int lenHay=strlen(haystack), lenNee=strlen(needle);
        for(int start=0;start<=lenHay-lenNee;start++)
        {
            char*i=haystack+start,*j=needle;
            while(*i && *j && *i==*j){i++;j++;}
            if(!*j) return start;
        }
        return -1;
    }
};
//2nd pass: 2015-02-21 KMP
class Solution_2nd {
public:
    int strStr(char *haystack, char *needle) {
        int lenHay=strlen(haystack),lenNee=strlen(needle);
        if(lenNee==0) return 0;
        vector<int> next(lenNee+1,0);
        int p=1,k=0;
        while(needle[p])
        {
            if(needle[p]==needle[k]) next[++p]=++k; else k=next[k];
            if(k==0)next[++p]=k;
        }
        for(int i=1,j=1;i<=lenHay-lenNee+1;)
        {
            while(needle[j-1] && haystack[i-1]==needle[j-1]){i++; j++;}
            if(!needle[j-1]) return i-j;
            if(j==1) i++; else j=next[j-1]+1;
        }
        return -1;
    }
};

//3rd pass: BF
/*
abc a
start idx in hay from [0,lenH-lenN]

1. compare until needle == \0. found!
2. start idx loop finish, not found.
*/
class Solution_BF_3rd {
public:
    int strStr(char *haystack, char *needle) {
        int lenH=strlen(haystack), lenN=strlen(needle);
        for(int start=0;start<=lenH-lenN;++start){
            char *i=haystack+start, *j=needle;
            while(*j && *i==*j) {++i; ++j;}
            if(!*j) return start;
        }
        return -1;
    }
};

/*
abc a
start idx in hay from [0,lenH-lenN]

1. compare until needle == \0. found!
2. start idx loop finish, not found.

KMP preprocessing
next: [1,lenN], next[0]=-1 bondary
next[i]: means pattern string [0,i-1], longest len suffix==prefix, len cannot exceed i
example:  a n a n a
       -1 0 0 1 2 3
          a a a a a
       -1 0 1 2 3 4
1. loop i [0,lenN), k=next[i]
2. compare H[k] and H[i], 
    2.1 match, break
    2.2 not match, k=next[k], until k==-1
    next[i+1]=k+1
    
use next to enhance the main loop:
haystack i [0,lenH-lenN]
needle j=0
compare hay[i]==nee[j]
1. match i++,j++
2. not match, 
    2.1 reach needle end, found
    2.2 j=next[j] until j==-1, then i++
*/
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int lenH=strlen(haystack), lenN=strlen(needle);
        vector<int> next(lenN+1,-1);
        for(int i=0;i<lenN;++i){
            int k=next[i];
            while(k!=-1 && needle[i]!=needle[k]) k=next[k];
            next[i+1]=k+1;
        }
        for(int i=0,j=0;i<=lenH-lenN;){
            while(needle[j] && haystack[i]==needle[j]) {++i; ++j;}
            if(!needle[j]) return i-j;
            j=next[j];
            if(j==-1) {++i;j=0;}
        }
        return -1;
    }
};

int main()
{
	Solution *s = new Solution();
	//char hay[] = "baa";
	//char need[] = "aa";
	char hay[] = "mississippi";
	char need[] = "a";

	cout<< s->strStr(hay,need) <<endl;

	system("pause");
	return 0;
}
