#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution_1st {
public:
	int findkth(int A[], int Alen, int B[], int Blen, int k)
	{
		if(Alen==0) return B[k-1];
		if(Blen==0) return A[k-1];
		if(k==1) return A[0]<B[0]?A[0]:B[0];
		int Amid= (double)k*Alen/(Alen+Blen)-1;
		int Bmid = k-Amid-2;
		if(A[Amid] > B[Bmid]) return findkth(A,Amid+1,&B[Bmid+1],Blen-Bmid-1,k-Bmid-1);
		if(A[Amid] == B[Bmid]) return A[Amid];
		if(A[Amid] < B[Bmid]) return findkth(&A[Amid+1],Alen-Amid-1,B,Bmid+1,k-Amid-1);
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if((m+n)%2 == 0)
			return ((double)findkth(A,m,B,n,(m+n)/2) + (double)findkth(A,m,B,n,(m+n)/2+1))/2;
		else
			return findkth(A,m,B,n,(m+n)/2+1);
	}
};

//2nd pass: 2015-02-18
class Solution {
public:
    int findKth(int A[], int Alen, int B[], int Blen, int k)
    {
        if(Alen==0) return B[k-1];
        if(Blen==0) return A[k-1];
        if(k==1) return min(A[0],B[0]);
        int Amid=(double)k*Alen/(Alen+Blen)-1;
        int Bmid=k-Amid-2; 
        if(A[Amid]==B[Bmid]) return A[Amid];
        if(A[Amid]<B[Bmid]) return findKth(A+Amid+1,Alen-Amid-1,B,Bmid+1,k-Amid-1);
        else return findKth(A,Amid+1,B+Bmid+1,Blen-Bmid-1,k-Bmid-1);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2) return findKth(A,m,B,n,(m+n)/2+1);
        else return ((double)findKth(A,m,B,n,(m+n)/2) + (double)findKth(A,m,B,n,(m+n)/2+1))/2;
    }
};

int main()
{
	Solution *s = new Solution();
	int A[] = {4,5,6,7};
	int B[] = {1,2,10};
	//cout << s->findkth(A,3,B,3,6) << endl;
	cout << s->findMedianSortedArrays(A,4,B,3) << endl;
	//cout << (int)((double)2*1/3-1) << endl;
	system("pause");
	return 0;
}