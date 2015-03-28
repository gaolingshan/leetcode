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


/*
"Old panda is a big fat panda and smart panda. "，单词panda，找最短距离(BB)

two pointers prev=-1 & i=-1;
every step, find next string start from i+1, 
1. prev not -1, update ans=min(ans,i-prev);
2. prev=i;
until i=not found
*/
int solve1(string S, string T){
	int prev=-1,i=-1,ans=INT_MAX;
	while(1){
		i=S.find(T,i+1);
		if(i==-1) break;
		if(prev!=-1) ans=min(ans,i-prev);
		prev=i;
	}
	return (ans==INT_MAX)?-1:ans;
}

/*
input: "     the   sky is   blue    ", output: "the sky is blue". Remove Duplicate空格(BB)
pointer l: where should place char
traverse with i, 
1. not space, s[l++]=s[i++];
2. is space
	2.1 (i!=0 && s[i-1] not space), s[l++]=s[i++];
	2.2 (dup space case) i++
resize s to l
*/
string solve2(string s){
	int l=0;
	for(int i=0;i<s.length();++i)
		if(s[i]!=' ' || (i!=0 && s[i-1]!=' '))  s[l++]=s[i]; 
	if(s[l-1]==' ')--l;
	s.resize(l);
	return s;
}

/*
马拉松
at the beginnin, Runner CPid=0, CPTime=0
use hashtable<id,Runner> to keep all runners data
use pq<Runner> to keep top 10 as leader board. pq is max heap, 10 smallest, top is the 10th player
cmp: 
Runner A < Runner B
1.CPid large, 2. CPtime smaller, 3.id smaller

message come, Runner r passed CP c at time t
1.locate r.id by hashtable, update r.CPid & r.CPtime
2.check pq to see whether need update
*/
class Runner{
public:
	int id;
	string name;
	int CPid;	//the latest CP passed
	int CPtime; //the time pass the latest CP
	Runner(){}
	Runner(int _id, string _name):id(_id),name(_name){}
};
class CheckPoint{
public:
	int id;
};
class LeaderBoard{
	struct cmp_struct{
		bool operator() (const Runner &a, const Runner &b) const{
			if(a.CPid > b.CPid) return true;
			if(a.CPid < b.CPid) return false;
			if(a.CPtime < b.CPtime) return true;
			if(a.CPtime > b.CPtime) return false;
			return a.id < b.id;
		}
	}cmp_obj;
	unordered_map<int, Runner> table;
	priority_queue<Runner,vector<Runner>,cmp_struct> pq;
	int cap;
public:
	LeaderBoard(vector<Runner> runners, int capacity){
		table.clear();
		cap=capacity;
		for(auto r:runners) {
			r.CPid=0;
			r.CPtime=0;
			table[r.id]=r;
			if(pq.size() < cap)pq.push(r);
		}
	}
	void onMessage(int r, int c, int t){
		table[r].CPid=c;
		table[r].CPtime=t;
		if(cmp_obj(table[r],pq.top())) {
			pq.pop();
			pq.push(table[r]);
		}
	}
	void PrintBoard(){
		auto tmp=pq;
		while(!tmp.empty()){
			cout<<tmp.top().name<<endl;
			tmp.pop();
		}
		cout<<endl;
	}
};

/*
a#3b#4cddf#4 -> aaabbbbcddffff
i:traverse,
if s[i]=='#'
1. repeate s[i-1]
2. j from i+1, collect all nums, repeat nums-1 time
3. i jump to j-1
if not, just append
*/
string solve3(string str){
	string res="";
	for(int i=0,j=0;i<str.length();++i){
		if(str[i]=='#'){
			string tmp;
			for(j=i+1;j<str.length();++j) if(isdigit(str[j])) tmp+=str[j]; else break;
			int nums=stoi(tmp);
			if(i!=0) res.append(nums-1,str[i-1]);
			i=j-1;
		} else res+=str[i];
	}
	return res;
}


/*
反向转换 aaabbccccbaddd -> a3b2c4bad3
要求in-place!!
traverse i, record cnt, cnt>1 compress
use left pointer indicate where to put
1. s[i] != s[i+1] || i==n-1, check if need compress
1.1 cnt>1 need compress
	s[i]+cnt put at left
	cnt=1
1.2 cnt=1 don't compress, just append
2. otherwise ++count;
*/
string solve4(string str){
	int left=0,cnt=1;
	for(int i=0;i<str.length();++i){
		if(i==str.length()-1 || str[i]!=str[i+1]){
			if(cnt>1){
				str[left++]=str[i];
				for(char c:to_string(cnt)) str[left++]=c;
				cnt=1;
			}else str[left++]=str[i];
		}else ++cnt;
	}
	str.resize(left);
	return str;
}

/*
2-4-5-6-7-10-13  ->  2,4-7,10,13
token -
traverse by token, maintian lower=upper=INT_MIN
1. num > upper+1, save lower-upper, then update lower=upper=num
	1.1 upper != lower, save in form lower-upper
	1.2 otherwise, save lower
2. otherwise, upper=num
3. finnaly, save lower-upper
*/
string solve5(string str){
	int lower=INT_MIN, upper=lower;
	istringstream ss(str);
	string tmp,res;
	while(getline(ss,tmp,'-')){
		int num=stoi(tmp);
		if(num > upper+1){
			if(upper!=INT_MIN){
				if(upper==lower) res+=to_string(lower)+",";
				else res+=to_string(lower)+"-"+to_string(upper)+",";
			}
			lower=upper=num;
		}else upper=num;
	}
	if(upper!=INT_MIN){
		if(upper==lower) res+=to_string(lower)+",";
		else res+=to_string(lower)+"-"+to_string(upper)+",";
	}
	res.pop_back();
	return res;
}

/*
malloc 2D array, pass nD array as args
*/
void solv6_func(int A[], int m, int n){
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j) 
			printf("%d ", *(A+i*n + j));
			//printf("%d ", A[i][j]);
			//printf("%d ", *(*(A+i)+j));
		cout<<endl;
	}
}
void solve6(){
	int m=5,n=6;
	int *A=(int*)malloc(m*n*sizeof(int));
	//int **A=(int**)malloc(m*sizeof(int*));
	//for(int i=0;i<m;++i) A[i]=(int*)malloc(n*sizeof(int));
	//for(int i=0,cnt=0;i<m;++i) for(int j=0;j<n;++j) A[i][j]=++cnt;
	for(int i=0,cnt=0;i<m;++i) for(int j=0;j<n;++j) *(A+i*n+j)=++cnt;
	//for(int i=0;i<m;++i){
	//	for(int j=0;j<n;++j) 
	//		printf("%d ", A[i][j]);
	//	cout<<endl;
	//}
	//solv6_func(A,m,n);

	int B[][3]={{1,2,3},{4,5,6}};
	solv6_func((int*)B,2,3);
	B[0][0];
	//for(int i=0;i<2;++i){
	//	for(int j=0;j<3;++j) 
	//		printf("%d ", B[i][j]);
	//	cout<<endl;
	//}
}

int main()
{
	//cout<<solve1("Old panda is a big fat panda and smart panda.","panda")<<endl;
	//cout<<solve2("     the   sky is   blue    ")<<endl;


	vector<Runner> data={Runner(1,"1"),Runner(2,"2"),Runner(3,"3"),Runner(4,"4"),Runner(5,"5")};
	LeaderBoard LB(data,3);
	LB.onMessage(1,1,10);
	LB.onMessage(1,2,12);
	LB.onMessage(1,3,13);
	//LB.onMessage(3,1,12);
	//LB.onMessage(5,1,13);
	LB.PrintBoard();
	LB.onMessage(4,1,15);
	LB.onMessage(2,1,17);
	LB.onMessage(5,2,20);
	LB.PrintBoard();
	LB.onMessage(3,2,22);
	LB.PrintBoard();

	//cout<<solve3("a#13b#14cddf#24")<<endl;
	//cout<<solve4("aaabbccccbaddd")<<endl;
	//cout<<solve4("aaaaaaaaaaaaaaaaaaaaaaa")<<endl;
	//cout<<solve5("2-4-5-6-7-10-13")<<endl;
	//solve6();

	system("pause");
	return 0;
}