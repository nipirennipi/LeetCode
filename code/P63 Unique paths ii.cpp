#define P63_Unique_paths_ii_cpp
#ifdef P63_Unique_paths_ii_cpp

//链接：https://leetcode-cn.com/problems/unique-paths-ii/

#include"stdafx.h"

//#define P63_Solution_1		//动态规划
#ifdef P63_Solution_1

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int rows=obstacleGrid.size();
		int columns=obstacleGrid[0].size();
		vector<vector<int>> dp(rows,vector<int>(columns,0));
		for(int j=0;j<columns&&obstacleGrid[0][j]==0;++j){
			dp[0][j]=1;
		}
		for(int i=0;i<rows&&obstacleGrid[i][0]==0;++i){
			dp[i][0]=1;
		}
		for(int i=1;i<rows;++i){
			for(int j=1;j<columns;++j){
				if(obstacleGrid[i][j]==0){
					dp[i][j]=dp[i][j-1]+dp[i-1][j];
				}
			}
		}
		return dp[rows-1][columns-1];
	}
};

#endif // P63_Solution_1



#define P63_Solution_2		//动态规划 + 滚动数组
#ifdef P63_Solution_2

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int rows=obstacleGrid.size();
		int columns=obstacleGrid[0].size();
		vector<int> dp(columns+1,0);
		for(int j=0;j<columns&&obstacleGrid[0][j]==0;++j){
			dp[j+1]=1;
		}
		for(int i=1;i<rows;++i){
			for(int j=0;j<columns;++j){
				dp[j+1]=obstacleGrid[i][j]==0?dp[j]+dp[j+1]:0;
			}
		}
		return dp[columns];
	}
};

#endif // P63_Solution_2



//#define P63_Test
#ifdef P63_Test

int main(){
	Solution Lee;
	//vector<vector<int>> obstacleGrid={{1},{0}};
	vector<vector<int>> obstacleGrid={{0,0,0},{0,1,0},{0,0,0}};
	cout<<Lee.uniquePathsWithObstacles(obstacleGrid);
}

#endif // P63_Test



#endif // P63_Unique_paths_ii_cpp