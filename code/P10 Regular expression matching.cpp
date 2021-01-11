#define P10_Regular_expression_matching_cpp
#ifdef P10_Regular_expression_matching_cpp

//链接：https://leetcode-cn.com/problems/regular-expression-matching/

#include"stdafx.h"

#define P10_Solution_1		//动态规划
#ifdef P10_Solution_1

class Solution {
public:
	bool isMatch(string s,string p) {
		int m=s.size();
		int n=p.size();
		bool** dp=new bool* [m+1];
		for(int i=0;i<m+1;++i){
			dp[i]=new bool[n+1];
			for(int j=0;j<n+1;++j){
				dp[i][j]=false;
			}
		}
		dp[0][0]=true;
		for(int i=0;i<m+1;++i){
			for(int j=1;j<n+1;++j){
				if(p[j-1]=='*'){
					dp[i][j]=dp[i][j-2];
					if(i!=0&&(p[j-2]=='.'||s[i-1]==p[j-2])){
						dp[i][j]|=dp[i-1][j];
					}
				}
				else{
					if(i!=0&&(p[j-1]=='.'||s[i-1]==p[j-1])){
						dp[i][j]=dp[i-1][j-1];
					}
				}
			}
		}
		return dp[m][n];
	}
};

#endif // P10_Solution_1



#define P10_Solution_2
#ifdef P10_Solution_2



#endif // P10_Solution_2



//#define P10_Test
#ifdef P10_Test

int main(){
	Solution Lee;
	cout<<Lee.isMatch("aa","a*");
}

#endif // P10_Test



#endif // P10_Regular_expression_matching_cpp