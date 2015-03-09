// 
//   Author: 
//   Update: 
#include <iostream>
#include <functional>
#include <bitset>
#include <chrono>
#include <exception>
#include <fstream>
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
#include <deque>
#include <stack>
using namespace std;

void ReadFile(vector<string> &res, string filename)
{
	ifstream file(filename);
	string tmp;
	while(getline(file,tmp)){
		int pos=tmp.find("read#");
		if(pos == string::npos){
			res.push_back(tmp);
		}else{
			string new_filename=tmp.substr(pos+6);
			ReadFile(res,new_filename);
		}
	}
	file.close();
}

int main()
{
	vector<string> res;
	ReadFile(res,"a1.txt");
	for(auto s:res) cout<<s<<endl;
	system("pause");
	return 0;
}