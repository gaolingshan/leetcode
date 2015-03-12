// Text Justification
//   Author: flashhack
//   Update: 2015-01-15
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
	string justifyLine(vector<string> &now, int lengthCnt, int L)
	{
		if(now.size()==0) return "";
		string line;
		int numSpace=L-lengthCnt;
		int numSlots=now.size()-1;
		vector<int> Slots;
		if(numSlots!=0)
		{
			Slots.assign(numSlots,numSpace/numSlots);	//this is how many spaces in one slots between words. from left to right
			numSpace%=numSlots;
			int i=0;
			while(numSpace>0)
			{
				Slots[i++]++;
				numSpace--;
			}
		}
		for(int i=0;i<now.size();i++)
		{
			line+=(now[i]);
			if(i!=now.size()-1)
			{
				for(int j=0;j<Slots[i];j++) line+=" ";
			}
		}	
		while(line.length()<L)line+=" ";
		return line;
	}

	string justifyLastLine(vector<string> &now, int L)
	{
		if(now.size()==0) return "";
		string line;
		for(int i=0;i<now.size();i++)
		{
			line+=now[i];
			if(i!=now.size()-1)
			{
				line+=" ";
			}
		}	
		while(line.length()<L)line+=" ";
		return line;
	}

    vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> res;
		if(L==0) 
		{
			res.push_back("");
			return res;
		}
        string line;
		vector<string> now;
		int lengthCnt=0;
		for(string str:words)
		{
			int spaceNeeded=max((int)now.size()-1,0);
			if(lengthCnt + spaceNeeded +str.length() + 1<= L)
			{
				now.push_back(str);
				lengthCnt+=str.length();
				continue;
			}
			//cannot add more words to current line. start to justify this line

			line=justifyLine(now,lengthCnt,L);
			if(line!="")res.push_back(line);

			now.clear();
			now.push_back(str);
			lengthCnt=str.length();
		}
		//line = justifyLine(now,lengthCnt,L);
		line = justifyLastLine(now,L);
		if(line != "") res.push_back(line);
		return res;
    }
};

//2nd pass: 2015-03-11
/*
every line: at least len + n-1(spaces)
1. if(len + n + newword_len) > L , n words become a line
2. justify this line
3. begin=i
4. justify last line

justify normal line: 
spaces need to insert: L-len -> S  
space num: n-1 -> nS
every space: S/nS 
special case: nS==0 -> 0
8/2 ok~
3/2 [0,S%ns) space +1

justify last line:
every space: always 1

add trailing space to line until L


"This", "is", "an", "example", "of", "text", "justification."

len: 8
begin:0 
i: 3

S=8, nS=2, len=8, L=16
i:0,1,2
space: 4
This    is    an

len:13
begin:3
i: 6

S=3, nS=2, len=13, L=16
i:0,1,2
space: 2,1
exapmle  of text
*/

class Solution {
public:
    string justify(vector<string> &words, int begin, int end, int len, int L, bool isLast){
		if(begin>end) return"";
        int S=L-len, nS=end-begin;
        string res;
        for(int i=0;i<=nS;++i){
            int space=(isLast)?1:(nS==0)?0:(S/nS + ((i<(S%nS))?1:0));
            res+=words[begin+i];
            if(i!=nS)res.append(space,' ');
        }	
        if(res.size()<L)res.append(L-res.size(),' ');
        return res;
    }
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int begin=0,len=0;
        for(int i=0;i<words.size();++i){
            if(len+i-begin+words[i].length() > L){
                res.push_back(justify(words,begin,i-1,len,L,false));
                begin=i;
                len=0;
            }
            len+=words[i].length();
        }
        res.push_back(justify(words,begin,words.size()-1,len,L,true));
        return res;
    }
};

int main()
{
	Solution *s = new Solution();
	//string A[]={"This", "is", "an", "example", "of", "text", "justification."};
	//string A[]={"a"};
	//string A[]={""};
	string A[]={"What","must","be","shall","be."};
	vector<string> data,res;
	for(string str:A) data.push_back(str);
	//res=s->fullJustify(data,16);
	//res=s->fullJustify(data,1);
	//res=s->fullJustify(data,0);
	res=s->fullJustify(data,12);
	for(string str:res)cout<<str<<endl;

	system("pause");
	return 0;
}