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
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

class Singleton{
private:
	Singleton(){}
public:
	static Singleton* getInstance(){
		static Singleton *m_instance=NULL;
		static mutex lock;	
		unique_lock<mutex> lck(lock);
		if(m_instance==NULL){
			m_instance = new Singleton();
		}
		return m_instance;
	}
	static Singleton* getInstance_efficent(){
		static Singleton *m_instance=NULL;
		static mutex lock;	
		Singleton* tmp=m_instance;
		// memory barrier
		if(tmp==NULL){
			unique_lock<mutex> lck(lock);
			tmp=m_instance;
			if(tmp==NULL){
				tmp=new Singleton();
				// memory barrier
				m_instance=tmp;
			}
		}
		return tmp;
	}
};


class CardGame{
public:
	static CardGame* createCardGame(string type);
};
class PokerGame : public CardGame{};
class BlackJackGame : public CardGame{};
CardGame* CardGame::createCardGame(string type){
	if(type=="Poker") return new PokerGame();	
	if(type=="BlackJack") return new BlackJackGame();
}

int main()
{


	system("pause");
	return 0;
}