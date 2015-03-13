// containsDuplicate
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

/**
* Write a function that is given an array of integers. It should return true if
* any value appears at least twice in the array, and it should return false if
* every element is distinct.
*/
bool containsDuplicate(vector<int> arr) {
	unordered_set<int> table;
	for(int v:arr){
		if(table.count(v)!=0) return true;
		table.insert(v);
	}
	return false;
}

/**
* Write a function that is given an array of integers and an integer k. It
* should return true if and only if there are two distinct indices i and j into
* the array such that arr = arr[j] and the difference between i and j is at
* most k.
*/     
bool containsNearbyDuplicate(vector<int> arr, int k) {
	if(arr.empty()) return false;
	unordered_set<int> table={arr[0]};
	for(int i=1,j=0;i<arr.size();++i){
		if(i-j+1>k) table.erase(arr[j++]);
		if(table.count(arr[i])!=0) return true; else table.insert(arr[i]);
	}
	return false;
}

/**
* Write a function that is given an array of integers. It should return true if
* and only if there are two distinct indices i and j into the array such that
* the difference between arr and arr[j] is at most l and the difference
* between i and j is at most k.
*/
bool containsNearbyAlmostDuplicate(vector<int> arr, int k, int l) {
    if(arr.empty()) return false;
	set<int> table={arr[0]};
	for(int i=1,j=0;i<arr.size();++i){
		if(i-j+1>k) table.erase(arr[j++]);
		if(table.count(arr[i])!=0) return true;
		table.insert(arr[i]);
		auto it=table.find(arr[i]);
		if(next(it)!=table.end() && abs(*it - *next(it))<=l) return true;
		if(it!=table.begin() && abs(*it - *prev(it))<=l) return true;
	}
	return false;
}

int main()
{
	vector<int> data={1,3,5,6,7,9,11};
	//cout<<containsDuplicate(data)<<endl;
	//cout<<containsNearbyDuplicate(data,3)<<endl;
	cout<<containsNearbyAlmostDuplicate(data,3,1)<<endl;

	system("pause");
	return 0;
}