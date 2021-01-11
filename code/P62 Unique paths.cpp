#define P62_Unique_paths_cpp
#ifdef P62_Unique_paths_cpp

//链接：https://leetcode-cn.com/problems/unique-paths/

#include"stdafx.h"

//#define P62_Solution_1		//动态规划
#ifdef P62_Solution_1

class Solution {
public:
	int uniquePaths(int m,int n) {
		vector<vector<int>> dp(m,vector<int>(n,1));
		for(int i=1;i<m;++i){
			for(int j=1;j<n;++j){
				dp[i][j]=dp[i][j-1]+dp[i-1][j];
			}
		}
		return dp[m-1][n-1];
	}	
};

#endif // P62_Solution_1



//#define P62_Solution_2		//动态规划 + 滚动数组
#ifdef P62_Solution_2

class Solution {
public:
	int uniquePaths(int m,int n) {
		vector<int> dp(n,1);
		for(int i=1;i<m;++i){
			for(int j=1;j<n;++j){
				dp[j]=dp[j-1]+dp[j];
			}
		}
		return dp[n-1];
	}
};

#endif // P62_Solution_2



#define P62_Solution_3		//排列组合
#ifdef P62_Solution_3

class Solution {
public:
	int uniquePaths(int m,int n) {
		if(m<n){
			return uniquePaths(n,m);
		}
		int ans=1;
		for(int j=2,i=m+n-2;i>=m;--i){
			ans*=i;
			while(j<=n-1&&!(ans%j)){
				ans/=j;
				++j;
			}
		}
		return ans;
	}
};

#endif // P62_Solution_3



//#define P62_Test
#ifdef P62_Test

int main(){
	Solution Lee;
	Lee.uniquePaths(13,23);
}

#endif // P62_Test



#endif // P62_Unique_paths_cpp