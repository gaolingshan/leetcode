// Inverse Pairs
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
left ...  mid, mid+1 ...  right
        i                       j
L:A[left,mid+1)
R:A[mid+1,right+1)

when merge, L[i] > R[j] , cnt_cross += L.size() - i
i or j reach end, just append

count=cnt_left + cnt_right + cnt_cross
*/

int merge(vector<int> &A, int left, int right){
	if(left>=right) return 0;
	int mid=left+((right-left)>>1);
	int cnt_left=merge(A,left,mid), cnt_right=merge(A,mid+1,right), cnt_cross=0;
	vector<int> L(A.begin()+left,A.begin()+mid+1), R(A.begin()+mid+1,A.begin()+right+1);
	int i=0,j=0,k=left;
	while(i<L.size() && j<R.size()){
		if(L[i]<=R[j])
			A[k++]=L[i++];
		else{
			cnt_cross += L.size()-i;
			A[k++]=R[j++];
		}
	}
	while(i<L.size()) A[k++]=L[i++];
	while(j<R.size()) A[k++]=R[j++];
	return cnt_left + cnt_right + cnt_cross;
}

int main()
{
	//vector<int> data={2,4,1,3,5};
	vector<int> data={1,20,6,4,5};
	cout<<merge(data,0,data.size()-1)<<endl;

	system("pause");
	return 0;
}