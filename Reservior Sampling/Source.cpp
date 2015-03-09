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


int main()
{
	srand(time(NULL));
	int A[]={1,2,3,4,5,6,7,8,9,10};
	int n=sizeof(A)/sizeof(int);
	int k=0;
	for(int i=0;i<n;i++){
		int j=rand()%(i+1);
		//if(j<k) 
		swap(A[j],A[i]);
	}
	for(int i=0;i<n;i++) cout<<A[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}