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

class Solution {
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
		for(auto c2:c1) cout<<c2<<" ";
		cout<<endl;
	}

	system("pause");
	return 0;
}