// Number of 1 Bits 
//   Author: flashhack
//   Update: 2015-03-10
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

class Solution {
public:
    int hammingWeight(uint32_t n) {
        //bitset<32> b(n);
        //return b.count();
		int cnt=0;
		while(n){
			cnt++;
			n&=n-1;
		}
		return cnt;
    }
};

int main()
{


	system("pause");
	return 0;
}