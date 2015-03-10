// Reverse Bits
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

/*
swap like merge sort. len=1,2,4,8 do & mask
01010101 55 << 1
10101010 AA >> 1

00110011 33 << 2
11001100 CC >> 2

00001111 0F << 4
11110000 F0 >> 4

00FF00FF << 8
FF00FF00 >> 8

0000FFFF << 16
FFFF0000 >> 16

O(logn)
*/
class Solution_2 {
public:
    uint32_t reverseBits(uint32_t n) {
        n=((n&0x55555555) << 1) | ((n&0xAAAAAAAA) >> 1);
        n=((n&0x33333333) << 2) | ((n&0xCCCCCCCC) >> 2);
        n=((n&0x0F0F0F0F) << 4) | ((n&0xF0F0F0F0) >> 4);
        n=((n&0x00FF00FF) << 8) | ((n&0xFF00FF00) >> 8);
        n=((n&0x0000FFFF) << 16) | ((n&0xFFFF0000) >> 16);
        return n;
    }
};

/*
swap bit at i,j, xor==1 need swap
O(32)
*/
class Solution {
public:
    void swap(uint32_t &n, int i,int j){
        if(((n>>i)&1U) ^ ((n>>j)&1U)) n=n^((1U<<i)|(1U<<j));
    }
    uint32_t reverseBits(uint32_t n) {
        for(int i=0;i<16;i++) swap(n,i,31-i);
        return n;
    }
};

int main()
{
	Solution s;
	cout<<s.reverseBits(4294967295U)<<endl;


	system("pause");
	return 0;
}