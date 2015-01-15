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


// Forward declaration of the read4 API.
int read4(char *buf);
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int pos=0;
		int cnt=0;
		while(pos+4<=n)
		{
			cnt = read4(buf+pos);
			pos+=cnt;
			if(cnt<4) break;
		}
		if(pos==n || cnt<4) return pos;
		char *buff=new char[10];
		cnt=min(read4(buff),n-pos);
		for(int i=0;i<cnt;i++)buf[pos++]=buff[i];
		delete(buff);
		return pos;
    }
};

int main()
{
	//Solution *s = new Solution();

	system("pause");
	return 0;
}