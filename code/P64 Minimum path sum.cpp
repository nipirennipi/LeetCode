#define P64_Minimum_path_sum_cpp
#ifdef P64_Minimum_path_sum_cpp

//���ӣ�https://leetcode-cn.com/problems/minimum-path-sum/

#include"stdafx.h"

//#define P64_Solution_1		//��̬�滮�����ϵ��£�
#ifdef P64_Solution_1

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int row=grid.size();
		int column=grid[0].size();
		vector<vector<int>> dp(row,vector<int>(column));
		dp[0][0]=grid[0][0];
		for(int j=1;j<column;++j){
			dp[0][j]=grid[0][j]+dp[0][j-1];
		}
		for(int i=1;i<row;++i){
			dp[i][0]=grid[i][0]+dp[i-1][0];
		}
		for(int i=1;i<row;++i){
			for(int j=1;j<column;++j){
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
			}
		}
		return dp[row-1][column-1];
	}
};

#endif // P64_Solution_1



//#define P64_Solution_2		//��̬�滮�����ϵ��£�ʹ��grid�ĵ�һ�����Ż��ռ䣩
#ifdef P64_Solution_2

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if(!grid.size()||!grid[0].size()){
			return 0;
		}
		int row=grid.size();
		int column=grid[0].size();
		for(int j=1;j<column;++j){
			grid[0][j]=grid[0][j-1]+grid[0][j];
		}
		for(int i=1;i<row;++i){
			grid[0][0]=grid[0][0]+grid[i][0];
			for(int j=1;j<column;++j){
				grid[0][j]=min(grid[0][j],grid[0][j-1])+grid[i][j];
			}
		}
		return grid[0][column-1];
	}
};

#endif // P64_Solution_2



#define P64_Solution_3		//��̬�滮�����µ��ϣ�ʹ��grid�����һ�����Ż��ռ䣩
#ifdef P64_Solution_3

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if(!grid.size()||!grid[0].size()){
			return 0;
		}
		int row=grid.size();
		int column=grid[0].size();
		for(int j=column-2;j>=0;--j){
			grid[row-1][j]=grid[row-1][j+1]+grid[row-1][j];
		}
		for(int i=row-2;i>=0;--i){
			grid[row-1][column-1]=grid[row-1][column-1]+grid[i][column-1];
			for(int j=column-2;j>=0;--j){
				grid[row-1][j]=min(grid[row-1][j],grid[row-1][j+1])+grid[i][j];
			}
		}
		return grid[row-1][0];
	}
};

#endif // P64_Solution_3



//#define P64_Test
#ifdef P64_Test

int main(){
	Solution Lee;
	vector<vector<int>> grid{{1,2},{5,6},{1,1}};
	Lee.minPathSum(grid);
}

#endif // P64_Test



#endif // P64_Minimum_path_sum_cpp