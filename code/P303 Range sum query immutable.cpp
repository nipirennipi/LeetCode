#define P303_Range_sum_query_immutable_cpp
#ifdef P303_Range_sum_query_immutable_cpp

//链接：https://leetcode-cn.com/problems/range-sum-query-immutable/

#include"stdafx.h"

#define P303_Solution_1			//动态规划
#ifdef P303_Solution_1

class NumArray {
private:
	vector<int> dp;		//dp[i]: nums[0]~nums[i-1] 之和
public:
	NumArray(vector<int>& nums) {
		int size=nums.size();
		dp.resize(size+1,0);
		for(int i=1;i<=size;++i){
			dp[i]=dp[i-1]+nums[i-1];
		}
	}

	int sumRange(int i,int j) {
		return dp[j+1]-dp[i];
	}
};

#endif // P303_Solution_1



#define P303_Solution_2
#ifdef P303_Solution_2



#endif // P303_Solution_2



//#define P303_Test
#ifdef P303_Test

int main(){
	Solution Lee;
}

#endif // P303_Test



#endif // P303_Range_sum_query_immutable_cpp