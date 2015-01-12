// LRU Cache
//   Author: flashhack
//   Update: 2015-01-12
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
#include <list>
using namespace std;

class LRUCache{
public:
	list<pair<int,int>> KV_list;	
	unordered_map<int,list<pair<int,int>>::iterator> key_map;
	int cap;
	
    LRUCache(int capacity) {
		cap=capacity;
    }
    
    int get(int key) {
		if(key_map.find(key)==key_map.end()) return -1;
		//need to update pos in KV_List
		auto it=key_map[key];
		KV_list.splice(KV_list.end(),KV_list,it);
		return it->second;
    }
    
    void set(int key, int value) {
		if(key_map.find(key)==key_map.end())	//key not found, need insert
		{
			if(KV_list.size()>=cap) 
			{
				//remove front of the list, i.e. the oldest
				if(KV_list.size()!=0)
				{
					int key=KV_list.front().first;
					key_map.erase(key);
					KV_list.pop_front();				
				}
			}
			//insert the new one
			if(KV_list.size()<cap)
			{
				KV_list.push_back(make_pair(key,value));
				key_map[key]=prev(KV_list.end());
			}
		}
		else//key found, update KV_list
		{
			auto it=key_map[key];
			it->second=value;
			KV_list.splice(KV_list.end(),KV_list,it);
		}
    }
};

int main()
{
	LRUCache *s = new LRUCache(2);
	cout<<s->get(1)<<endl;
	s->set(1,10);
	s->set(2,11);
	s->set(3,12);
	cout<<s->get(1)<<endl;
	cout<<s->get(3)<<endl;
	cout<<s->get(2)<<endl;
	s->set(4,13);
	cout<<s->get(3)<<endl;
	cout<<s->get(4)<<endl;


	system("pause");
	return 0;
}