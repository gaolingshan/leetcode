// Meeting Rooms
//   Author: flashhack
//   Update: 
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

int maxConflict(vector<pair<int,int>> intervals) {
    vector<int> start_time;
    vector<int> end_time;
    for(int i=0; i<intervals.size();i++){
        start_time.push_back(intervals[i].first);
        end_time.push_back(intervals[i].second);
    }
    sort(start_time.begin(),start_time.end());
    sort(end_time.begin(),end_time.end());
    int ans=1,now=1;
    int i=1,j=0,time=start_time[0];
    while(i<start_time.size()){        
        if(start_time[i]<end_time[j]){
            now++;
            ans=max(ans,now);
            i++;
        }else{
            now--;
            j++;
        }
    }
    return ans;
}

struct cmp_struct
{
	bool operator() (const pair<int, int> &a, const pair<int, int> &b){
		return a.first < b.first;
	}
};
bool hasConflict(vector<pair<int,int>> intervals) {
    sort(intervals.begin(), intervals.end()); //sort here base on pair.first
    for(int i=0; i+1<intervals.size();i++){
        if(intervals[i].second > intervals[i+1].first) return false;
    }
    return true;
}

int main()
{
	//Solution *s = new Solution();
	vector<pair<int, int>> data = {make_pair<int,int>(1,4),make_pair<int,int>(2,3),make_pair<int,int>(3,4),make_pair<int,int>(4,5)};
	cout << maxConflict(data)<<endl;
	cout << hasConflict(data)<< endl; 

	system("pause");
	return 0;
}