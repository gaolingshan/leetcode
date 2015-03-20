// Valid UTF-8
//   Author: flashhack
//   Update: 2015-03-19
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

/*
UTF-8µÄ¹æÔò£º
1byte: 0xxxxxxxx
2byte: 110xxxxxx 10xxxxxxx
3byte: 1110xxxxx 10xxxxxxx 10xxxxxxx
4byte: 11110xxxx 10xxxxxxx 10xxxxxxx 10xxxxxxx
*/
bool isValid(vector<unsigned char> &data){
	int len=0;
	for(auto c:data){
		if(len==0){
			if((c>>6) == 8u) len=1; else
			if((c>>5) == 16u) len=2; else
			if((c>>4) == 32u) len=3; else
			if((c>>7)) return false;
		} else{
			if((c>>6) != 2u) return false;
			--len;
		}
	}
	return len==0;
}

int main()
{


	system("pause");
	return 0;
}