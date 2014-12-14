// <filename>.<ext>
//   Author: <name>
//   Update: <date>
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

class Solution {
public:
	bool check(vector<vector<char> > &board, int x,int y)
	{
		int i=0,j=0;
		if(board[x][y]=='.') return true;
		for(i=0;i<9;i++)
		{
			if(i!=x)
				if(board[i][y] == board[x][y]) return false;
		}
		for(i=0;i<9;i++)
		{
			if(i!=y)
				if(board[x][i] == board[x][y]) return false;
		}
		int region_x=x/3*3,region_y=y/3*3;
		for(i=0;i<3;i++)
			for(j=0;j<3;j++)
			{
				int xx=i+region_x,yy=j+region_y;
				if(xx!=x && yy!=y)
					if(board[xx][yy]==board[x][y]) return false;			
			}
		return true;
	}

	bool finish;
	void dfs(int i, int j, vector<vector<char> > &board)
	{
		if(finish) return;
		if(i==9)
		{
			finish = true;
			return;
		}
		int nextj=j+1;
		int nexti=i;
		if(nextj==9)
		{
			nexti++;
			nextj=0;
		}
		if(board[i][j]!='.')
		{
			dfs(nexti,nextj,board);
			if(finish) return;
		}
		else
		{
			for(int num=0;num<9;num++)
			{
				board[i][j]='1'+num;
				if(check(board,i,j))
					dfs(nexti,nextj,board);
				if(finish) return;
				board[i][j]='.';
			}

		}
	}


    void solveSudoku(vector<vector<char> > &board) {
		finish=false;
		dfs(0,0,board);
    }
};

int main()
{
	Solution *s = new Solution();
	vector<string> bb;
	bb.push_back("53..7....");
	bb.push_back("6..195...");
	bb.push_back(".98....6.");
	bb.push_back("8...6...3");
	bb.push_back("4..8.3..1");
	bb.push_back("7...2...6");
	bb.push_back(".6....28.");
	bb.push_back("...419..5");
	bb.push_back("....8..79");
	vector<vector<char> > board;
	for(int i=0;i<9;i++)
	{
		vector<char> tmp;
		for(int j=0;j<9;j++)
			tmp.push_back(bb[i][j]);
		board.push_back(tmp);
	}
	s->solveSudoku(board);
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++) cout<<board[i][j];
		cout<<endl;
	}



	system("pause");
	return 0;
}