#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	//int findkth(int A[], int Alen, int B[], int Blen, int k)
	//{
	//	if(Alen==0) return B[k-1];
	//	if(Blen==0) return A[k-1];
	//	if(k==1) return A[0]<B[0]?A[0]:B[0];
	//	int Amid= (double)k*Alen/(Alen+Blen)-1;
	//	int Bmid = k-Amid-2;
	//	if(A[Amid] > B[Bmid]) return findkth(A,Amid+1,&B[Bmid+1],Blen-Bmid-1,k-Bmid-1);
	//	if(A[Amid] == B[Bmid]) return A[Amid];
	//	if(A[Amid] < B[Bmid]) return findkth(&A[Amid+1],Alen-Amid-1,B,Bmid+1,k-Amid-1);
	//}

	int findkth(int A[], int Alen, int B[], int Blen, int k)
	{
		//if(Alen==0) return B[k-1];
		//if(Blen==0) return A[k-1];
		//if(k==1) return A[0]<B[0]?A[0]:B[0];
		//int Amid= (double)k*Alen/(Alen+Blen)-1;
		//int Bmid = k-Amid-2;
		//if(A[Amid] > B[Bmid]) return findkth(A,Amid+1,&B[Bmid+1],Blen-Bmid-1,k-Bmid-1);
		//if(A[Amid] == B[Bmid]) return A[Amid];
		//if(A[Amid] < B[Bmid]) return findkth(&A[Amid+1],Alen-Amid-1,B,Bmid+1,k-Amid-1);

		int Astart=0, Bstart=0;
		while(Alen > 0 && Blen > 0 && k > 1)
		{
			int Amid= (double)k*Alen/(Alen+Blen)-1;
			int Bmid = k-Amid - 2;
			Amid+=Astart;
			Bmid+=Bstart;
			if(A[Amid] > B[Bmid])
			{
				Blen=Blen-1+Bstart -Bmid;
				Bstart=Bmid+1;
				Alen=Amid-Astart+1;
	
				k=k-Bmid-1+Bstart;
			}
			if(A[Amid] == B[Bmid]) return A[Amid];
			if(A[Amid] < B[Bmid])
			{
				Alen=Alen+Astart-1 - Amid;
				k=k-Amid-1+Astart;
				Astart=Amid+1;

				Blen=Bmid-Bstart+1;
			}
		}
		if(Alen==0) return B[Bstart+k-1];
		if(Blen==0) return A[Astart+k-1];
		if(k==1) return A[Astart]<B[Bstart]?A[Astart]:B[Bstart];
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if((m+n)%2 == 0)
			return ((double)findkth(A,m,B,n,(m+n)/2) + (double)findkth(A,m,B,n,(m+n)/2+1))/2;
		else
			return findkth(A,m,B,n,(m+n)/2+1);
	}
};

int main()
{
	Solution *s = new Solution();
	int A[] = {4,5,6,7};
	int B[] = {1,2,10};
	cout << s->findkth(A,4,B,3,2) << endl;
	//cout << s->findMedianSortedArrays(A,4,B,3) << endl;
	//cout << (int)((double)2*1/3-1) << endl;
	system("pause");
	return 0;
}