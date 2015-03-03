// Non-repeating Chracter
//   Author: flashhack
//   Update: 2015-03-02
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

//Palantir
string firstNonRepeatingCharacter(string input) {
	int table[256]={0};
	string res = "";
	for (char c : input) table[c]++;
	for (char c : input) if (table[c] == 1) {
		res += c;
		return res;
	}
	return res;
}

/*
hhhttttataht

*/
string characterReverse(string input) {
    int pos_t=-1;
	string res=input;
	for (int i = 0; i<res.length(); i++){
		if (res[i] == 't'){
			if (pos_t==-1) pos_t=i;
			continue;
		}
		if (res[i] == 'h'){
			if (pos_t != -1){
				swap(res[pos_t], res[i]);
				pos_t++;
			}
			continue;
		}
		pos_t=-1;
	}
	return res;
}

//int main()
//{
//	//cout << firstNonRepeatingCharacter("AAABCDDLHBH") << endl;
//	//cout << firstNonRepeatingCharacter("BANANAS ARE BLUE") << endl;
//	//cout << characterReverse("theater")<<endl;
//	//cout << characterReverse("the author of the book")<<endl;
//	//cout << characterReverse("ttth")<<endl;
//	//cout << characterReverse("ttthhhhth")<<endl;
//	int a,b;
//	cin >> a >> b;
//	cout<<a+b<<endl;
//
//	system("pause");
//	return 0;
//}


//Two Sigma
void JumbleSort(){
	string tmp,res="";
	deque<int> numbers;
	deque<string> words;
	vector<bool> isNumber;
	while (cin >> tmp){
		if (tmp == "") break;
		if (!isalpha(tmp[0])){
			numbers.push_back(stoi(tmp));
			isNumber.push_back(true);
		} else{
			words.push_back(tmp);
			isNumber.push_back(false);
		}
	}
	sort(numbers.begin(), numbers.end());
	sort(words.begin(), words.end());
	for (int i = 0; i<isNumber.size(); i++){
		if (isNumber[i]) {
			res += to_string(numbers.front()) + " ";
			numbers.pop_front();
		} else{
			res += words.front()+" ";
			words.pop_front();
		}
	}
	if(!res.empty())res.pop_back();
	cout<<res<<endl;
	getchar();
}

void CopyFile(){
	map<int,int> data_set_ids; //key: data_set_id, value: data_center_id
	vector<set<int>> data_centers;
	int N=0,M=0,tmp;
	cin >> N;
	for (int i = 0; i<N; i++){
		cin >> M;
		set<int> data_center;
		for (int j = 0; j<M; j++) {
			cin >> tmp;
			data_center.insert(tmp);
			data_set_ids[tmp]=i;
		}
		data_centers.push_back(data_center);
	}
	for (int i = 0; i<N; i++){
		for (auto it : data_set_ids){
			if (data_centers[i].count(it.first)==0)	//this center don't have this data set
				cout << it.first << " " << it.second+1 << " " << i+1 << endl;
		}
	}
	cout<<"done"<<endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	CopyFile();
	//system("pause");
    return 0;
}



