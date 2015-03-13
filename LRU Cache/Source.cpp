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

class LRUCache_old{
public:
	list<pair<int,int>> KV_list;	
	unordered_map<int,list<pair<int,int>>::iterator> key_map;
	int cap;
	
    LRUCache_old(int capacity) {
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

//2nd pass: 2015-02-23
class LRUCache_2nd{
private:
	int cap;
	list<pair<int, int>> data;
	unordered_map<int, list<pair<int, int>>::iterator> table;
public:
	LRUCache_2nd(int capacity) {
		cap = capacity;
		data.clear();
		table.clear();
	}

	int get(int key) {
		if (table.count(key) == 0) return -1;
		auto it = table[key]; 
		int val = it->second;
		data.erase(it);
		data.emplace_back(key,val);
		table[key] = prev(data.end());
		return data.back().second;
	}

	void set(int key, int value) {
		if (table.count(key))  //exist, move to end
		{
			auto it = table[key];
			data.erase(it);
			data.emplace_back(key, value);
			table[key] = prev(data.end());
		}
		else //non-exist, insert and 
		{
			if (data.size() >= cap) //invalid lru
			{
				table.erase(data.front().first);
				data.erase(data.begin());
			}
			data.emplace_back(key, value);
			table[key] = prev(data.end());
		}
	}
};

//3rd pass: 2015-03-12
/*
list store K-V, hashtable store K-iter in list
set:
1. K not in table, need insert
    1.1 capacity full, invalid list head, delete this Key in table
    1.2 append at list end, insert this key in table
2. K in table, need update
    2.1 delete this key in list(use iter) & table
    2.2 add this key at list end, with new value
    
get:
1 K not in table, -1
2.K in table
    2.1 delete this key in list(use iter) & table
    2.2 add this key at list end, with old value
*/
class LRUCache{
private:
    int cap;
    list<pair<int,int>> data;
    unordered_map<int,list<pair<int,int>>::iterator> table;
public:
    LRUCache(int capacity) {
        cap=capacity;
        data.clear();
        table.clear();
    }
    int get(int key) {
        if(table.count(key)==0) return -1;
        int value=table[key]->second;
        data.erase(table[key]);
        data.emplace_back(key,value);
        table[key]=prev(data.end());
		return value;
    }
    void set(int key, int value) {
        if(table.count(key)==0){
            if(data.size()==cap){
                int headKey=data.front().first;
                data.pop_front();
                table.erase(headKey);
            }
            data.emplace_back(key,value);
            table[key]=prev(data.end());
        }else{
            data.erase(table[key]);
            data.emplace_back(key,value);
            table[key]=prev(data.end());
        }
    }
};

int main()
{
	LRUCache *s = new LRUCache(2);
	//cout<<s->get(1)<<endl;
	//s->set(1,10);
	//s->set(2,11);
	//s->set(3,12);
	//cout<<s->get(1)<<endl;
	//cout<<s->get(3)<<endl;
	//cout<<s->get(2)<<endl;
	//s->set(4,13);
	//cout<<s->get(3)<<endl;
	//cout<<s->get(4)<<endl;

	s->set(2, 1);
	s->set(3, 2);
	cout<<s->get(3)<<endl;
	cout << s->get(2) << endl;
	s->set(4, 3);
	cout << s->get(2) << endl;
	cout << s->get(3) << endl;
	cout << s->get(4) << endl;



	system("pause");
	return 0;
}