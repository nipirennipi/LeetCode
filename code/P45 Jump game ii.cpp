#define P45_Jump_game_ii_cpp
#ifdef P45_Jump_game_ii_cpp

//链接：https://leetcode-cn.com/problems/jump-game-ii/

#include"stdafx.h"

#define P45_Solution_1		//贪心算法（时间复杂度:O(n)）
#ifdef P45_Solution_1

class Solution {
public:
	int jump(vector<int>& nums) {
		if(nums.size()==1){
			return 0;
		}
		int size=nums.size();
		int maxPos=nums[0];
		int bound=nums[0];
		int count=1;
		for(int i=1;i<size-1;++i){
			maxPos=max(maxPos,i+nums[i]);
			if(i==bound){
				++count;
				bound=maxPos;
			}
		}
		return count;
	}
};

#endif // P45_Solution_1



//#define P45_Solution_2		//动态规划（时间复杂度:O(n^2)）（Time Limit Exceed）
#ifdef P45_Solution_2

class Solution {
public:
	int jump(vector<int>& nums) {
		int size=nums.size();
		vector<int> dp(size,0x3f3f3f3f);
		dp[0]=0;
		for(int i=1;i<size;++i){
			for(int j=0;j<i;++j){
				if(j+nums[j]>=i){
					dp[i]=min(dp[i],dp[j]+1);
				}
			}
		}
		return dp[size-1];
	}
};

#endif // P45_Solution_2



//#define P45_Test
#ifdef P45_Test

int main(){
	Solution Lee;
	vector<int> nums{2,3,1,1,4};
	Lee.jump(nums);
}

#endif // P45_Test



#endif // P45_Jump_game_ii_cpp