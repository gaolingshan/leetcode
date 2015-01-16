// Read N Characters Given Read4 II - Call multiple times
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

string data="";
int now;
// Forward declaration of the read4 API.
int read4(char *buf)
{
	if(now+3<data.length())
	{
		for(int i=0;i<4;i++) buf[i]=data[now+i];
		now=now+4;
		return 4;
	}
	else
	{
		int i=0;
		while(now<data.length()) buf[i++]=data[now++];
		return i;
	}
}

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
	string outerBuff;
    int read(char *buf, int n) 
	{
        int pos=0;
		char *buff=new char[10];
		int cnt;
		while(1)
		{
			if(outerBuff.length()!=0) 
			{
				//big loop hole here! this is a shallow copy!!! may cause unexpected error!!!
				//buff=(char*)outerBuff.c_str();

				//correct way: deep copy
				for(int i=0;i<outerBuff.length();i++) buff[i]=outerBuff[i];
				cnt=outerBuff.length();
				if(pos+cnt<=n)
				{
					for(int i=0;i<cnt;i++) buf[pos++]=buff[i];
					//outerBuff consume fully
					outerBuff.clear();
					continue;
				}
				//only consume part of the outer buff
				cnt=n-pos;
				for(int i=0;i<cnt;i++) 
				{
					buf[pos++]=buff[i];
					outerBuff=outerBuff.substr(1,outerBuff.length()-1);
				}
				return pos;
			}
			else
			{
				cnt=read4(buff);
				if(cnt==0) return pos;	//file done
				if(pos+cnt<=n)//fully consume. OK
				{
					for(int i=0;i<cnt;i++) buf[pos++]=buff[i];
					continue;
				}
				//not fully consume, create outerBuff
				int cnt_org=cnt;
				cnt=n-pos;
				for(int i=0;i<cnt;i++) buf[pos++]=buff[i];
				for(int i=cnt;i<cnt_org;i++)outerBuff.push_back(buff[i]);
				return pos;
			}
		}
    }
};

void callRead(int n, Solution *s)
{
	char *res;	
	res = new char[n];
	memset(res,0,sizeof(char)*n);
	s->read(res,n);
	cout<<res<<endl;

}

int main()
{
	Solution *s = new Solution();
	
	//data="a";
	data="1234567";
	//data="hGBfyEfMOCxdLIIBeHCScmXupglxlLPLWDkAxxOHPSzBzibLqypQRIiNgCzWsqATwvXYdwZnrqvsTjMnyvYmCoukwgOHHcWfAUvbRbWZnlhnmmIIulLrepgUXzaUHyAbmoBBZKIdKlTAoriOjwjUSsiJAiCwiKkodimbihRoNrGJeITllNYfmzfZljFhpBqjJeQQWJFvdkaULBNgKgVeQWXNxLROhfcTZqaqlngNYfHRjlldiHRBnMSZbiZBAzVaXOisJpItWWFiMUNndAThbfQUcLRoFPFfDwADDOKJcWTavTTOHwQNKPmjxNrpHuJyscxEsGVZYJdjlNnNJQGtrJtJYLVnzDouhhIrFRmUwNCaDQvuyTfjnlDLMvdUacWzzeeTrtNYHQqvwNwsIeNHfdlvXHziCroXHMeDZfKIoAulkYQYdwJTivzEveTNUCKnOVLiMPjecvZzvHGvfugnjIzaWXhqbMVGzvEzNkwoIPLUiwNhetnz";
	
	for(int i=0;i<8;i++) 
		callRead(1,s);

	//callRead(0,s);
	//callRead(1,s);
	//callRead(2,s);

	system("pause");
	return 0;
}