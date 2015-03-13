// Tower of Hanoi
//   Author: flashhack
//   Update: 2015-03-12
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
recursion
T(1)=1
T(n)=2T(n-1)+1
	=4T(n-2)+1+2
	=8T(n-3)+1+2+4...
	=2^(n-1)T(1)+1+2+4+..
	=2^(n-1) + 2^(n-2) + ... + 1
	=2^n - 1
*/
void TowerOfHanoi(int n, char from, char to, char aux){
	if(n==1) {
		cout<<"Move "<<n<<" from "<<from<<" to "<<to<<endl;
		return;
	}
	TowerOfHanoi(n-1,from,aux,to);
	cout<<"Move "<<n<<" from "<<from<<" to "<<to<<endl;
	TowerOfHanoi(n-1,aux,to,from);
}

int main()
{
	TowerOfHanoi(3,'A','B','C');

	system("pause");
	return 0;
}