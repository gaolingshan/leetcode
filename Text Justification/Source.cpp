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

class Solution {
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