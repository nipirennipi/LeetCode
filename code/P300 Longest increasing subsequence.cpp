#define P300_Longest_increasing_subsequence_cpp
#ifdef P300_Longest_increasing_subsequence_cpp

//链接：https://leetcode-cn.com/problems/longest-increasing-subsequence/

#include"stdafx.h"

#define P300_Solution_1		//动态规划
#ifdef P300_Solution_1

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if(nums.size()==0){
			return 0;
		}
		int size=nums.size();
		vector<int> dp(size,1);
		int maxLen=dp[0];
		for(int i=1;i<size;++i){
			int temp=1;
			for(int j=0;j<i;++j){
				if(nums[i]>nums[j]){
					temp=dp[j]+1>temp?dp[j]+1:temp;
				}
			}
			dp[i]=temp;
			maxLen=dp[i]>maxLen?dp[i]:maxLen;
		}
		return maxLen;
	}
};

#endif // P300_Solution_1



#define P300_Solution_2
#ifdef P300_Solution_2



#endif // P300_Solution_2



//#define P300_Test
#ifdef P300_Test

int main(){
	Solution Lee;
	vector<int> nums{10,9,2,5,3,7,101,18};
	Lee.lengthOfLIS(nums);
}

#endif // P300_Test



#endif // P300_Longest_increasing_subsequence_cpp