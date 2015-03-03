// N-Queens
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
	void dfs(int row,int n,vector<string> &board,vector<vector<string> > &sol)
	{
		if(row==n)
		{
			sol.push_back(board);
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
				dfs(row+1,n,board,sol);
				board[row][j]='.';
			}
		}
	}

    vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > sol;
        vector<string> board;
		string raw="";
		for(int i=0;i<n;i++) raw+=".";
		for(int i=0;i<n;i++) board.push_back(raw);
		dfs(0,n,board,sol);
		return sol;
    }
};

class Solution {
public:
    vector<int> now; //每一行的queen放在哪一列
    vector<vector<string>> res;
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
            vector<string> tmp(rows,string(rows,'.'));
            for(int i=0;i<rows;i++) tmp[i][now[i]]='Q';
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<rows;i++){
            now.push_back(i);
            if(check(now,rows)) dfs(now,rows);
            now.pop_back();
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        vector<int> now;
        dfs(now,n);
        return res;
    }
};

void print(vector<string> board)
{
	for(int i=0;i<board.size();i++)
		cout<<board[i]<<endl;
	cout<<endl;
}

int main()
{
	Solution *s = new Solution();

	vector<vector<string> > sol=s->solveNQueens(4);

	cout<<sol.size()<<endl;
	for(int k=0;k<sol.size();k++)print(sol[k]);

	system("pause");
	return 0;
}