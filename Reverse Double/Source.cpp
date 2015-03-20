// Reverse Double
//   Author: flashhack
//   Update: 2015-03-20
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
123.45  ->  54.321
0.1234 -> 4321.0

1. get len of int part.
2. *10 until frac part == 0
3. %10 can get one digit, until x==0
	3.1 ans=ans*10+digit
	3.3 x=(int)x/10
4. / pow(10, len int part)
*/
const double eps=1e-8;
int dblcmp(double x){
	return (x>eps)?1:(x<-eps)?-1:0;
}
double reverse(double num){
	double intPart=(int)num;
	int lenInt=(dblcmp(intPart))?log10(intPart)+1:0;
	double x=num,ans=0;
	while(dblcmp(x-(int)x) != 0) x*=10;
	
	while(dblcmp(x)!=0){
		ans=ans*10 + (int)fmod(x,10);
		x=(int)(x/10);
	}
	ans /= pow(10, lenInt);
	return ans;
}

int main()
{
	cout<<reverse(123.4568)<<endl;
	cout<<reverse(0.12345)<<endl;

	system("pause");
	return 0;
}