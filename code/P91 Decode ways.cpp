#define P91_Decode_ways_cpp
#ifdef P91_Decode_ways_cpp

//链接：https://leetcode-cn.com/problems/decode-ways/

#include"stdafx.h"

//#define P91_Solution_1			//动态规划	T(n)=O(n)	S(n)=O(n)
#ifdef P91_Solution_1

class Solution {
public:
	int numDecodings(string s) {
		if(!s.size()||s[0]=='0'){
			return 0;
		}
		vector<int> dp(s.size()+1,1);
		for(int i=1;i<s.size();++i){
			if(s[i]=='0'){
				if(s[i-1]=='1'||s[i-1]=='2'){
					dp[i+1]=dp[i-1];
				}
				else{
					return 0;
				}
			}
			else{
				if(s[i-1]=='1'||(s[i-1]=='2'&&'1'<=s[i]&&s[i]<='6')){
					dp[i+1]=dp[i]+dp[i-1];
				}
				else{
					dp[i+1]=dp[i];
				}	
			}
		}
		return dp.back();
	}
};

#endif // P91_Solution_1



#define P91_Solution_2			//动态规划优化	T(n)=O(n)	S(n)=O(1)
#ifdef P91_Solution_2

class Solution {
public:
	int numDecodings(string s) {
		if(!s.size()||s[0]=='0'){
			return 0;
		}
		int dp1=1;
		int dp2=1;
		for(int i=1;i<s.size();++i){
			int temp;
			if(s[i]=='0'){
				if(s[i-1]=='1'||s[i-1]=='2'){
					temp=dp2;
				}
				else{
					return 0;
				}
			}
			else{
				if(s[i-1]=='1'||(s[i-1]=='2'&&'1'<=s[i]&&s[i]<='6')){
					temp=dp1+dp2;
				}
				else{
					temp=dp1;
				}
			}
			dp2=dp1;
			dp1=temp;
		}
		return dp1;
	}
};

#endif // P91_Solution_2



//#define P91_Test
#ifdef P91_Test

int main(){
	Solution Lee;
	Lee.numDecodings("10");
}

#endif // P91_Test



#endif // P91_Decode_ways_cpp