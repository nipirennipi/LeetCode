#define P120_Triangle_cpp
#ifdef P120_Triangle_cpp

//链接：https://leetcode-cn.com/problems/triangle/

#include"stdafx.h"

//#define P120_Solution_1		//动态规划
#ifdef P120_Solution_1

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int size=triangle.size();
		vector<vector<int>> dp(size,vector<int>(size));
		for(int j=0;j<size;++j){
			dp[size-1][j]=triangle[size-1][j];
		}
		for(int i=size-2;i>=0;--i){
			for(int j=0;j<=i;++j){
				dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
			}
		}
		return dp[0][0];
	}
};

#endif // P120_Solution_1



#define P120_Solution_2		//动态规划（使用triangle的最后一行来代替滚动数组，优化空间）
#ifdef P120_Solution_2

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int size=triangle.size();
		for(int i=size-2;i>=0;--i){
			for(int j=0;j<=i;++j){
				triangle[size-1][j]=min(triangle[size-1][j],triangle[size-1][j+1])+triangle[i][j];
			}
		}
		return triangle[size-1][0];
	}
};

#endif // P120_Solution_2



//#define P120_Test
#ifdef P120_Test

int main(){
	Solution Lee;
}

#endif // P120_Test



#endif // P120_Triangle_cpp