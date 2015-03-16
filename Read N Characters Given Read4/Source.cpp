// Read N Characters Given Read4
//   Author: flashhack
//   Update: 2015-01-15
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

class Solution_old {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) 
	{
        int pos=0;
		char *buff=new char[10];
		while(1)
		{
			int cnt = read4(buff);
			if(cnt==0) return pos;
			if(pos+cnt<=n)
			{
				for(int i=0;i<cnt;i++) buf[pos++]=buff[i];
				continue;
			}
			cnt=n-pos;
			for(int i=0;i<cnt;i++) buf[pos++]=buff[i];
			return pos;
		}
    }
};

//2nd pass: 2015-02-22
class Solution {
public:
    int read(char *buf, int n) {
        int cnt=0;
        char buffer[4];
        while(1)
        {
            int tmp=read4(buffer);
            if(cnt+tmp>=n)
            {
                for(int i=0;cnt<n;i++) buf[cnt++]=buffer[i];
                return cnt;
            }
            for(int i=0;i<tmp;i++) buf[cnt++]=buffer[i];
            if(tmp<4) return cnt;
        }
    }
};

int main()
{
	Solution *s = new Solution();
	
	//data="a";
	data="hGBfyEfMOCxdLIIBeHCScmXupglxlLPLWDkAxxOHPSzBzibLqypQRIiNgCzWsqATwvXYdwZnrqvsTjMnyvYmCoukwgOHHcWfAUvbRbWZnlhnmmIIulLrepgUXzaUHyAbmoBBZKIdKlTAoriOjwjUSsiJAiCwiKkodimbihRoNrGJeITllNYfmzfZljFhpBqjJeQQWJFvdkaULBNgKgVeQWXNxLROhfcTZqaqlngNYfHRjlldiHRBnMSZbiZBAzVaXOisJpItWWFiMUNndAThbfQUcLRoFPFfDwADDOKJcWTavTTOHwQNKPmjxNrpHuJyscxEsGVZYJdjlNnNJQGtrJtJYLVnzDouhhIrFRmUwNCaDQvuyTfjnlDLMvdUacWzzeeTrtNYHQqvwNwsIeNHfdlvXHziCroXHMeDZfKIoAulkYQYdwJTivzEveTNUCKnOVLiMPjecvZzvHGvfugnjIzaWXhqbMVGzvEzNkwoIPLUiwNhetnz";
	int n=507;
	char * res= new char[n];
	memset(res,0,sizeof(char)*n);
	s->read(res,507);
	cout<<res<<endl;

	system("pause");
	return 0;
}