// Character Bridge
//   Author: flashhack
//   Update: 2015-02-26
#include <iostream>
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
#include <stack>
using namespace std;

/*
string convert(string input){
	if (input == "") return "";
	int i = 0, p = 0, q = 0;
	i = input.find_first_not_of('-');
	p = q = i;
	string res = input;
	//string res=input.substr(0,i);
	while (i != res.length()){
		i++;
		if (res[i] == '-') continue;
		if (res[i] != res[p]){
			if(p!=q) for (int j = p; j <= q; j++) res[j] = '+';
			p = q = i;
			continue;
		}
		if (res[i] != '-') q = i;
		if (i >= res.length()) break;
		if (res[i] == res[p]) continue;
	}
	return res;
}
*/

/*
Character Bridge

input  : a-aa-b-a-b--c--c-
output : ++++-b-a-b--++++-

a-aa-b
p  q i
++++
++++-b-a-b--c--c-
	 i
	 p
	 q
++++
q is the last chracter == p

a-aa-b-a-b--c--c-
	             i
            p
++++           q

*/

string convert(string input){
	if (input == "") return "";
	int i = 0, p = 0, q = 0;
	i = input.find_first_not_of('-');
	p = q = i;
	string res = input;
	while (1){
		i++;
		if (i >= res.length()) {
			if (p != q) for (int j = p; j <= q; j++) res[j] = '+';
			break;
		}
		if (res[i] == '-') continue;
		if (res[i] == res[p]) {
			q = i;
			continue;
		}
		if (res[i] != res[p]){
			if(p!=q) for (int j = p; j <= q; j++) res[j] = '+';
			p = q = i;
		}
	}
	return res;
}

int main()
{
	//Solution *s = new Solution();
	cout << convert("a-aa-b-a-b--c--c-") << endl;
	system("pause");
	return 0;
}