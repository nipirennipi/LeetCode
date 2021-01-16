#define P200_Number_of_islands_cpp
#ifdef P200_Number_of_islands_cpp

//链接：https://leetcode-cn.com/problems/number-of-islands/

#include"stdafx.h"

//#define P200_Solution_1			//DFS
#ifdef P200_Solution_1

class Solution {
private:
	void DFS(vector<vector<char>>& grid,int x,int y){
		if(grid[x][y]=='0'){
			return;
		}
		grid[x][y]='0';
		if(x-1>=0&&grid[x-1][y]=='1'){
			DFS(grid,x-1,y);
		}
		if(x+1<grid.size()&&grid[x+1][y]=='1'){
			DFS(grid,x+1,y);
		}
		if(y-1>=0&&grid[x][y-1]=='1'){
			DFS(grid,x,y-1);
		}
		if(y+1<grid[0].size()&&grid[x][y+1]=='1'){
			DFS(grid,x,y+1);
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int count=0;
		for(int x=0;x<grid.size();++x){
			for(int y=0;y<grid[x].size();++y){
				if(grid[x][y]=='1'){
					++count;
					DFS(grid,x,y);
				}
			}
		}
		return count;
	}
};

#endif // P200_Solution_1



//#define P200_Solution_2			//BFS
#ifdef P200_Solution_2

class Solution {
private:
	void BFS(vector<vector<char>>& grid,int x,int y){
		grid[x][y]='0';
		queue<pair<int,int>> posQ;
		posQ.push({x,y});
		while(!posQ.empty()){
			pair<int,int> tempPos=posQ.front();
			posQ.pop();
			int tempX=tempPos.first;
			int tempY=tempPos.second;
			//grid[tempX][tempY]='0';		//若在这里才置为'0',会重复检查
			if(tempX-1>=0&&grid[tempX-1][tempY]=='1'){
				posQ.push({tempX-1,tempY});
				grid[tempX-1][tempY]='0';		//一旦遍历到陆地,直接置为'0'
			}
			if(tempX+1<grid.size()&&grid[tempX+1][tempY]=='1'){
				posQ.push({ tempX+1,tempY});
				grid[tempX+1][tempY]='0';
			}
			if(tempY-1>=0&&grid[tempX][tempY-1]=='1'){
				posQ.push({ tempX,tempY-1});
				grid[tempX][tempY-1]='0';
			}
			if(tempY+1<grid[0].size()&&grid[tempX][tempY+1]=='1'){
				posQ.push({ tempX,tempY+1});
				grid[tempX][tempY+1]='0';
			}
		}
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		int count=0;
		for(int x=0;x<grid.size();++x){
			for(int y=0;y<grid[x].size();++y){
				if(grid[x][y]=='1'){
					++count;
					BFS(grid,x,y);
				}
			}
		}
		return count;
	}
};

#endif // P200_Solution_2



#define P200_Solution_3				//并查集
#ifdef P200_Solution_3

class UFS{
private:
	int initSize;
	int* fa;
	int* depth;
public:
	UFS(int n){
		initSize=n;
		fa=new int[n];
		depth=new int[n];
		for(int i=0;i<n;++i){
			fa[i]=i;
			depth[i]=1;
		}
	}

	int find(int x){
		if(fa[x]==x){
			return x;
		}
		return find(fa[x]);
	}

	void unionPro(int x,int y){
		x=find(x);
		y=find(y);
		if(depth[x]<=depth[y]){
			fa[x]=y;
		}
		else{
			fa[y]=x;
		}
		if(depth[x]==depth[y]&&x!=y){
			++depth[y];
		}
	}

	int connectedComponentCount(){
		int count=0;
		for(int i=0;i<initSize;++i){
			if(fa[i]==i){
				++count;
			}
		}
		return count;
	}
};

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if(!grid.size()){
			return 0;
		}
		int row=grid.size();
		int col=grid[0].size();
		UFS s(row*col);
		int isSea=row*col;
		for(int x=0;x<row;++x){
			for(int y=0;y<col;++y){
				if(grid[x][y]=='1'){
					grid[x][y]='0';
					if(x>0&&grid[x-1][y]=='1'){
						s.unionPro((x-1)*col+y,x*col+y);
					}
					if(x<row-1&&grid[x+1][y]=='1'){
						s.unionPro((x+1)*col+y,x*col+y);
					}
					if(y>0&&grid[x][y-1]=='1'){
						s.unionPro(x*col+y-1,x*col+y);
					}
					if(y<col-1&&grid[x][y+1]=='1'){
						s.unionPro(x*col+y+1,x*col+y);
					}
					--isSea;
				}
			}
		}
		return s.connectedComponentCount()-isSea;
	}
};

#endif // P200_Solution_3



//#define P200_Test
#ifdef P200_Test

int main(){
	Solution Lee;
	vector<vector<char>> grid={
		{'1'},
		{'1'}
		/*{'1','1','1','1','0'},
		{'1','1','0','1','0'},
		{'1','1','0','0','0'},
		{'0','0','0','0','0'}*/
	};
	Lee.numIslands(grid);
}

#endif // P200_Test	



#endif // P200_Number_of_islands_cpp