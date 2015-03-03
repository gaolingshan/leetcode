// N-Queens II
//   Author: flashhack
//   Update: 2014-12-14
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
	int res;
	void dfs(int row,int n,vector<string> &board)
	{
		if(row==n)
		{
			res++;
			return;
		}
		bool flag=true;
		for(int j=0;j<n;j++)
		{
			flag=true;
			for(int i=1;i<=row;i++) 
			{
				//North
				if(board[row-i][j]=='Q')
				{
					flag=false;
					break;
				}
				//NorthEast
				if(j+i<n && board[row-i][j+i]=='Q')
				{
					flag=false;
					break;
				}
				//NorthWest
				if(j-i>=0 && board[row-i][j-i]=='Q')
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				board[row][j]='Q';
				dfs(row+1,n,board);
				board[row][j]='.';
			}
		}
	}
    int totalNQueens(int n) {
        vector<string> board;
		string raw="";
		for(int i=0;i<n;i++) raw+=".";
		for(int i=0;i<n;i++) board.push_back(raw);
		dfs(0,n,board);
		return res;        
    }
};

//2nd pass: 2015-03-04
class Solution {
public:
    vector<int> now; //每一行的queen放在哪一列
	int res{0};
    bool check(vector<int> &now, int rows){
        vector<bool> flag(rows,false);
        for(int q:now) if(flag[q]) return false; else flag[q]=true;
        for(int i=0;i<now.size();i++)
            for(int j=i+1;j<now.size();j++)
                if(abs(i-j)==abs(now[i]-now[j])) return false;
        return true;
    }
    void dfs(vector<int> &now, int rows){
        if(now.size()==rows){
            res++;
            return;
        }
        for(int i=0;i<rows;i++){
            now.push_back(i);
            if(check(now,rows)) dfs(now,rows);
            now.pop_back();
        }
    }

	int totalNQueens(int n) {
        vector<int> now;
        dfs(now,n);
        return res;        
    }
};

int main()
{
	Solution *s = new Solution();
	cout<<s->totalNQueens(8)<<endl;


	system("pause");
	return 0;
}