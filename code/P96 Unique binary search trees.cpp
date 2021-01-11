#define P96_Unique_binary_search_trees_cpp
#ifdef P96_Unique_binary_search_trees_cpp

//链接：https://leetcode-cn.com/problems/unique-binary-search-trees/

#include"stdafx.h"

#define P96_Solution_1		//动态规划
#ifdef P96_Solution_1

class Solution {
public:
	int numTrees(int n) {
		vector<int> dp(n+1,0);
		dp[0]=1;
		for(int i=1;i<=n;++i){
			for(int j=0;j<i;++j){
				dp[i]+=(dp[j]*dp[i-j-1]);
			}
		}
		return dp[n];
	}
};

#endif // P96_Solution_1



#define P96_Solution_2
#ifdef P96_Solution_2



#endif // P96_Solution_2


	
//#define P96_Test
#ifdef P96_Test

int main(){
	Solution Lee;
}

#endif // P96_Test



#endif // P96_Unique_binary_search_trees_cpp