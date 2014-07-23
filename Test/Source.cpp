#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
using namespace std;

template <class T>
int sum(T a, T b) {return a+b;}

int main()
{
	const int* foo;
	int a = 1;
	const int b = 3;
	int *const bar = &a;
	foo = &b;

	*bar = 2;

	cout<<*foo<<endl;
	foo = &b;
	cout << bar << endl;

	//int A[] = {1,2,3};
	int * A = new int[10];
	cout << A<<endl;
	
	cout << sum(*foo,*bar) << endl;
	int(*pfunc)(int,int);
	pfunc = &sum;
	cout << pfunc(*foo,*bar) << endl;
	system("pause");
	return 0;
}