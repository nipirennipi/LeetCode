#define P32_Longest_valid_parentheses_cpp
#ifdef P32_Longest_valid_parentheses_cpp

//链接：https://leetcode-cn.com/problems/longest-valid-parentheses/

#include"stdafx.h"

#define P32_Solution_1		//动态规划
#ifdef P32_Solution_1

class Solution {
public:
	int longestValidParentheses(string s) {	
		if(!s.size()){
			return 0;
		}
		int size=s.size();
		vector<int> dp(size);
		dp[0]=0;
		if(s[0]=='('&&s[1]==')'){
			dp[1]=2;
		}
		for(int i=2;i<size;++i){
			dp[i]=0;
			if(s[i]==')'){
				if(s[i-1]=='('){
					dp[i]=dp[i-2]+2;
				}
				else if((i-dp[i-1]>=1&&s[i-dp[i-1]-1]=='(')){
					dp[i]=i-dp[i-1]>=2?(dp[i-1]+dp[i-dp[i-1]-2]+2):dp[i-1]+2;
				}
			}
		}
		int maxLen=0;
		for(int i=0;i<size;++i){
			maxLen=max(maxLen,dp[i]);
		}
		return maxLen;
	}
};

#endif // P32_Solution_1



#define P32_Solution_2
#ifdef P32_Solution_2



#endif // P32_Solution_2



//#define P32_Test
#ifdef P32_Test

int main(){
	Solution Lee;
	string s=")()())";
	Lee.longestValidParentheses(s);
}

#endif // P32_Test



#endif // P32_Longest_valid_parentheses_cpp