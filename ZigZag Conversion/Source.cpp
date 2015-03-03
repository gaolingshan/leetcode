#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution_old {
public:
	string convert(string s, int nRows) {
		vector<vector<char>> data;
		string res;
		for(int i=0;i<nRows;i++) data.push_back(vector<char>());
		int row = 0, d=1;
		if(nRows==1) d=0;
		for(int i=0;i<s.length();i++) 
		{
			data[row].push_back(s[i]);
			row += d;
			if(row == nRows-1) d *= -1;
			if(row == 0) d*= -1;
		}
		for(int i=0;i<nRows;i++) 
			for(int j=0;j<data[i].size();j++) res+=data[i][j];
		return res;
	}
};

//2nd pass: 2015-03-03
class Solution {
public:
    string convert(string s, int nRows) {
		if (nRows==1) return s;
        vector<string> rows(nRows,"");
        bool isGoingDown=true;
        int i=0;
        for(char c:s){
            if(i==nRows-1) isGoingDown=false;
            if(i==0) isGoingDown=true;
            rows[i]+=c;
            i=(isGoingDown)?i+1:i-1;
        }
        string res;
        for(auto str:rows)res+=str;
        return res;
    }
};

int main()
{
	Solution *s = new Solution();

	cout << s->convert("PAYPALISHIRING",3) << endl;
	system("pause");
	return 0;
}