// Valid Palindrome
//   Author: flashhack	
//   Update: 2015-01-07
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
    bool isPalindrome(string s) {
		int len=s.length();
		if(len==0) return true;
		int left=0,right=len-1;
		while(left<right)
		{
			while(left<len && !isalnum(s[left]))left++;
			while(right >=0 && !isalnum(s[right]))right--;
			if(left>=right) break;
			if(tolower(s[left++])!=tolower(s[right--])) return false;
		}
		return true;
    }
};

//2nd pass: 2015-02-22
class Solution_2nd {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.length()-1;
        while(left<=right)
        {
            while(left<s.length()&&!isalnum(s[left]))left++;
            while(right>=0&&!isalnum(s[right]))right--;
            if(left>=right) break;
            if(tolower(s[left])==tolower(s[right])) 
            {
                left++; right--;
            }
            else return false;
        }
        return true;
    }
};

//3rd pass: 2015-03-12
/*
two pointers l&r
1. proceed l&r if not alnum
2. make sure l<r
3. compare tolower(s[l])==tolower(s[r])
4. l++, r--
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.length();
        while(1){
            while(l<s.length() && !isalnum(s[l])) ++l;
            while(r>=0 && !isalnum(s[r])) --r;
            if(l>=r) break;
            if(tolower(s[l++])!=tolower(s[r--])) return false;
        }
        return true;
    }
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
1. split list in two
2. reverse second list
3. compare two lists one by one, until one reach end.
4. reverse back 2nd list and append
*/
ListNode* reverse(ListNode* head){
	ListNode *p=head, *prev=NULL;
	while(p){
		auto p_next=p->next;
		p->next=prev;
		prev=p;
		p=p_next;
	}
	return prev;
}
bool isPalindrome(ListNode *head){
	ListNode *slow=head, *prev=head, *fast=head;
	while(fast){
		prev=slow;
		slow=slow->next;
		fast=(fast->next)?fast->next->next:NULL;
	}
	prev->next=NULL;
	auto p=head, q=reverse(slow), tmp=q;
	bool res=true;
	while(p&&q){
		if(p->val!=q->val) {
			res=false;
			break;
		}
		p=p->next; q=q->next;
	}
	prev->next=reverse(tmp);
	return res;
}

void print(ListNode *l)
{
	while(l!=NULL)
	{
		cout<<l->val<<endl;
		l=l->next;
	}
	cout<<endl;
}

int main()
{
	Solution *s = new Solution();
	//cout<<s->isPalindrome("A man, a plan, a canal: Panama")<<endl;
	//cout<<s->isPalindrome("race a car")<<endl;

	ListNode a(1);
	ListNode b(2);
	ListNode c(4);
	ListNode d(2);
	ListNode e(1);
	ListNode f(1);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	//e.next = &f;

	print(&a);
	cout<<isPalindrome(&a)<<endl;


	system("pause");
	return 0;
}