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

void print(vector<vector<int> > matrix)
{
	for(int i=0;i<matrix.size();i++)
	{
		for(int j=0;j<matrix.size();j++) cout<<matrix[i][j];
		cout<<endl;
	}
	

}

class Solution_old {
public:
    vector<vector<int> > generateMatrix(int n) {
       	vector<vector<int> > matrix;
		for(int i=0;i<n;i++)
		{
			vector<int> row;
			for(int j=0;j<n;j++)row.push_back(0);
			matrix.push_back(row);
		}
		//print(matrix);

		bool** flag = new bool*[n];
		for(int i=0;i<n;i++) flag[i]=new bool[n];

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				flag[i][j]=false;

		int i=0,j=0,dir=0,cnt=0;
		while(i!=n && j!=n)
		{
			cnt++;
			matrix[i][j]=cnt;
			flag[i][j]=true;
			switch (dir)
			{
			case 0:
				j++;
				if(j>=n || flag[i][j])
				{
					j--;
					i++;
					dir++;
					if(i>=n || flag[i][j]) return matrix;
				}
				break;
			case 1:
				i++;
				if(i>=n || flag[i][j])
				{
					i--;
					j--;
					dir++;
					if(j<0 || flag[i][j]) return matrix;
				}
				break;
			case 2:
				j--;
				if(j<0 || flag[i][j])
				{
					j++;
					i--;
					dir++;
					if(i<0 || flag[i][j]) return matrix;
				}
				break;
			case 3:
				i--;
				if(i<0 || flag[i][j])
				{
					i++;
					j++;
					dir=0;
					if(j>=n || flag[i][j]) return matrix;
				}
				break;
			default:
				break;
			}
		}
		return matrix;

    }
};

//2nd pass: 2015-03-04
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int count=0;
        int beginX=0,endX=n-1, beginY=0, endY=n-1;
        while(1){
            for(int i=beginX;i<=endX;i++) matrix[beginY][i]=++count;
            if(++beginY>endY) break;
            for(int i=beginY;i<=endY;i++) matrix[i][endX]=++count;
            if(--endX<beginX) break;
            for(int i=endX;i>=beginX;i--) matrix[endY][i]=++count;
            if(--endY<beginY) break;
            for(int i=endY;i>=beginY;i--) matrix[i][beginX]=++count;
            if(++beginX>endX) break;
        }
        return matrix;        
    }
};

int main()
{
	Solution *s = new Solution();
	print(s->generateMatrix(3));


	system("pause");
	return 0;
}