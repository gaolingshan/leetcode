// Sort Colors
//   Author: flashhack
//   Update: 2014-12-21
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Solution_old {
public:
    void sortColors(int A[], int n) {
		if(n==0 || n==1)return;
        int pt_0=-1,pt_1=-1,pt_2=0;
		int i=0;
		for(i=0;i<n;i++)if(A[i]!=0)break;	//ignore all prescedent 0s
		pt_0=i-1;
		pt_1=i-1;
		pt_2=i;
		while(pt_2<n)
		{
			while(A[pt_2] != 2)
			{
				if(A[pt_2]==0)
				{
					if(pt_0==pt_2)break;
					swap(A[++pt_0],A[pt_2]);	
					if(pt_1<pt_0)pt_1=pt_0;	//pt_1 must >= pt_0
					continue;
				}
				if(A[pt_2]==1)
				{
					if(pt_1==pt_2) break;
					swap(A[++pt_1],A[pt_2]);
					continue;
				}
			}
			pt_2++;
		}
    }
};

//2nd pass 2015-02-04
class Solution_2nd {
public:
    void sortColors(int A[], int n) {
        int i=0,j=n-1,k=0;
        while(1)
        {
            while(i<n && A[i]==0) i++;
            while(j>=0 && A[j]==2) j--;
            if(i>=j) break;
            if(A[i]==2)
            {
                swap(A[i],A[j]);
                j--;
                continue;
            }
            if(A[j]==0)
            {
                swap(A[i],A[j]);
                i++;
                continue;
            }
            k=i+1;
            while(k<n&&A[k]==1)k++;
            if(k>=j) break;
            swap(A[i],A[k]);
        }
    }
};

//3rd pass: 2015-02-09
class Solution_3rd {
public:
    void sortColors(int A[], int n) {
        int i=0,left=0,right=n-1;
        while(i<=right)
        {
            if(A[i]==0)
            {
                swap(A[i],A[left]);
                i++;
                left++;
                continue;
            }
            if(A[i]==1)
            {
                i++;
                continue;
            }
            if(A[i]==2)
            {
                swap(A[i],A[right]);
                right--;
            }
        }
    }
};

//4rd pass: 2015-02-27
class Solution {
public:
	void sortColors(int A[], int n) {
		int left = 0, right = n - 1, i = 0;
		while (i <= right){
			if (A[i] == 0) swap(A[left++], A[i++]); else
			if (A[i] == 1) i++; else
			swap(A[right--], A[i]);
		}
	}
};


int main()
{
	Solution *s = new Solution();

	//int A[] = {0,1,0,1,0,1};
	int A[] = {2,0,1,1,2,0};
	int n=6;
	s->sortColors(A,n);

	for(int i=0;i<n;i++) cout<<A[i]<<" ";
	cout<<endl;


	system("pause");
	return 0;
}