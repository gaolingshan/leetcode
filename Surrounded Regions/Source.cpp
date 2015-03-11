// Surrounded Regions
//   Author: flashhack
//   Update: 2015-01-09
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
	vector<vector<bool>> needFlip,visited;
	int lenX,lenY;
	void bfs(vector<vector<char>> &board, int startX, int startY)
	{
		int dx[]={1,0,-1,0};
		int dy[]={0,1,0,-1};
		vector<pair<int,int>> queue;
		bool flag=false;	//find an 'O' on the boarder
		queue.push_back(make_pair(startX,startY));
		int head=0,tail=0;
		while(head<=tail)
		{
			int x=queue[head].first;
			int y=queue[head].second;
			if(x==0 || x==lenX-1 || y==0 || y==lenY-1) flag=true;
			for(int i=0;i<4;i++)
			{
				int newx=x+dx[i];
				int newy=y+dy[i];
				if(newx>=0 && newx<lenX && newy>=0 && newy<lenY && board[newx][newy]=='O' && !visited[newx][newy])
				{
					queue.push_back(make_pair(newx,newy));
					visited[newx][newy]=true;
					tail++;
				}
			}
			head++;
		}
		if(!flag)
		{
			for(auto p:queue)
				needFlip[p.first][p.second]=true;
		}
	}
    void solve(vector<vector<char>> &board) {
		if(board.size()==0) return;
		lenX=board.size();
		lenY=board[0].size();
		visited.assign(lenX,vector<bool>(lenY,false));
		needFlip.assign(lenX,vector<bool>(lenY,false));
		for(int i=0;i<lenX;i++)
			for(int j=0;j<lenY;j++)
				if(board[i][j]=='O' && !visited[i][j])
					bfs(board,i,j);
		for(int i=0;i<lenX;i++)
			for(int j=0;j<lenY;j++)
				if(needFlip[i][j]) board[i][j]='X';
    }
};

//2nd pass: 2015-03-10
/*
bfs, start from boarder. turn these Os to Ts. 
T use as visited flag
after: 
	1. if O turn to X
	2. if T turn to O
*/
class Solution {
public:
    int m,n;
    void bfs(int x, int y, vector<vector<char>> &board){
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
		board[x][y]='T';
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty()){
            auto head=q.front(); q.pop();
            int x=head.first, y=head.second, newx=0,newy=0;
            for(int i=0;i<4;++i){
                newx=x+dx[i]; newy=y+dy[i];
                if(newx>=0 && newx<m && newy>=0 && newy<n && board[newx][newy]=='O'){
					q.push(make_pair(newx,newy));
					board[newx][newy]='T';
				}
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        if(board.empty() || board[0].empty()) return;
        m=board.size(); n=board[0].size();
        for(int i=0;i<m;++i) {
            if(board[i][0]=='O') bfs(i,0,board);
            if(board[i][n-1]=='O') bfs(i,n-1,board);
        }
        for(int i=0;i<n;++i){
            if(board[0][i]=='O') bfs(0,i,board);
            if(board[m-1][i]=='O') bfs(m-1,i,board);
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(board[i][j]=='O') board[i][j]='X';
				else if(board[i][j]=='T') board[i][j]='O';
    }
};

int main()
{
	Solution *s = new Solution();
	string A[]={"XXXX",
				"XOOX",
				"XXOX",
				"XOXX"};
	vector<vector<char>> matrix;
	for(int i=0;i<4;i++)
	{
		vector<char> row(A[i].begin(), A[i].end());
		matrix.push_back(row);
	}
	s->solve(matrix);
	for(auto c1:matrix)
	{
		for(auto c2:c1) cout<<c2;
		cout<<endl;
	}

	system("pause");
	return 0;
}