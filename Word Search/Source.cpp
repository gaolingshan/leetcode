// Word Search
//   Author: flashhack
//   Update: 2014-12-21
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
	bool finished;
	int dx[4];
	int dy[4];
	int m,n;
	unordered_map<char,int> hashtable;
	
	void dfs(vector<vector<char> > &board, int x, int y, vector<vector<bool> > &visited, int k, string &word)
	{
		if(finished) return;
		if(k==word.length()-1)
		{
			finished = true;
			return;
		}

		visited[x][y]=true;

		int newx=0,newy=0;
		for(int i=0;i<4;i++)
		{
			newx=x+dx[i];
			newy=y+dy[i];
			if(newx >= m || newx <0) continue;
			if(newy >= n || newy <0) continue;
			if(visited[newx][newy]) continue;
			if(board[newx][newy]==word[k+1])
				dfs(board,newx,newy,visited,k+1,word);
		}

		visited[x][y]=false;
	}

    bool exist(vector<vector<char> > &board, string word) {
		if(word=="") return true;
		
		m=board.size();
		if(m==0) return false;
		n=board[0].size();
		if(n==0) return false;

		dx[0]=0;dx[1]=1;dx[2]=-1;dx[3]=0;
		dy[0]=1;dy[1]=0;dy[2]=0;dy[3]=-1;

		finished = false;

		vector<vector<bool> > visited(m,vector<bool>(n,false));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(board[i][j] == word[0])
				{
					dfs(board,i,j,visited,0,word);
					if(finished) return true;
				}

		return false;
    }
};

//2nd pass: 2015-02-26
class Solution {
public:
	bool isFinish{ false };
	void dfs(int x, int y, string word, vector<vector<bool>> &visited, vector<vector<char> > &board){
		if (isFinish) return;
		if (word == ""){
			isFinish = true;
			return;
		}
		visited[x][y] = true;
		int dx[4] = { 0, 1, 0, -1 };
		int dy[4] = { 1, 0, -1, 0 };
		for (int i = 0; i<4; i++){
			int newx = x + dx[i], newy = y + dy[i];
			if (newx<0 || newx >= m || newy<0 || newy >= n) continue;
			if (!visited[newx][newy] && board[newx][newy] == word.front())
				dfs(newx, newy, word.substr(1, word.length() - 1), visited, board);
		}
		visited[x][y] = false;
	}
	int m, n;
	bool exist(vector<vector<char> > &board, string word) {
		if (word == "") return true;
		m = board.size();
		if (m == 0) return false;
		n = board[0].size();
		if (n == 0) return false;
		isFinish = false;
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) if (board[i][j] == word[0]){
				dfs(i, j, word.substr(1,word.length()-1), visited, board);
				if (isFinish) return true;
			}
		return false;
	}
};

int main()
{
	Solution *s = new Solution();
	vector<vector<char> > matrix;
	char A[][4]={{'A','B','C','E'},
				{'S','F','C','S'},
				{'A','D','E','E'}};
	for(int i=0;i<3;i++)
	{
		vector<char> row(A[i],A[i]+sizeof(A[i])/sizeof(char));
		matrix.push_back(row);
	}
	cout<<s->exist(matrix,"ABCCEEE")<<endl;

	cout<<s->exist(matrix,"ABCCED")<<endl;

	cout<<s->exist(matrix,"SEE")<<endl;
	cout<<s->exist(matrix,"ABCB")<<endl;



	system("pause");
	return 0;
}