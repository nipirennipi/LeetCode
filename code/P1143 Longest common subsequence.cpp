#define P1143_Longest_common_subsequence_cpp
#ifdef P1143_Longest_common_subsequence_cpp

//链接：https://leetcode-cn.com/problems/longest-common-subsequence/

#include"stdafx.h"

#define P1143_Solution_1	//动态规划
#ifdef P1143_Solution_1

class Solution {
public:
	int longestCommonSubsequence(string text1,string text2) {
		int len1=text1.size();
		int len2=text2.size();
		int** dp=new int*[len1+1];
		for(int i=0;i<len1+1;++i){
			dp[i]=new int[len2+1];
		}
		for(int i=0;i<len1+1;++i){
			dp[i][0]=0;
		}
		for(int i=0;i<len2+1;++i){
			dp[0][i]=0;
		}
		for(int i=1;i<len1+1;++i){
			for(int j=1;j<len2+1;++j){
				if(text1[i-1]==text2[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		return dp[len1][len2];
	}
};

#endif // P1143_Solution_1



//#define P1143_Solution_2		//动态规划+滚动数组
#ifdef P1143_Solution_2

class Solution {
public:
	int longestCommonSubsequence(string text1,string text2) {
		int len1=text1.size();
		int len2=text2.size();
		if(len2>len1){
			return longestCommonSubsequence(text2,text1);
		}
		int* dp=new int[len2+1];
		int temp;
		for(int i=0;i<len2+1;++i){
			dp[i]=0;
		}
		for(int i=1;i<len1+1;++i){
			temp=dp[0];
			for(int j=1;j<len2+1;++j){
				if(text1[i-1]==text2[j-1]){
					int tp=temp;
					temp=dp[j];
					dp[j]=tp+1;
				}
				else{
					temp=dp[j];
					dp[j]=max(dp[j],dp[j-1]);
				}	
			}
		}
		return dp[len2];
	}
};

#endif // P1143_Solution_2



//#define P1143_Test
#ifdef P1143_Test

int main(){
	Solution Lee;
	string text1="abcde";
	string text2="ace";
	cout<<Lee.longestCommonSubsequence(text1,text2);
}

#endif // P1143_Test



#endif // P1143_Longest_common_subsequence_cpp