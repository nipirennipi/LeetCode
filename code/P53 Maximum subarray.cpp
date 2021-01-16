#define P53_Maximum_subarray_cpp
#ifdef P53_Maximum_subarray_cpp

//链接：https://leetcode-cn.com/problems/maximum-subarray/

#include"stdafx.h"

//#define P53_Solution_1		//动态规划（时间复杂度：O(n)，空间复杂度：O(n)）
#ifdef P53_Solution_1

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size=nums.size();
		vector<int> dp(size);
		dp[0]=nums[0];
		for(int i=1;i<size;++i){
			dp[i]=max(dp[i-1]+nums[i],nums[i]);
		}
		int maxSum=dp[0];
		for(int i=1;i<size;++i){
			maxSum=max(maxSum,dp[i]);
		}
		return maxSum;
	}
};

#endif // P53_Solution_1



//#define P53_Solution_2		//动态规划（时间复杂度：O(n)，空间复杂度：O(1)）
#ifdef P53_Solution_2

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int size=nums.size();
		int maxSum=nums[0];
		int dp=nums[0];
		for(int i=1;i<size;++i){
			dp=max(dp+nums[i],nums[i]);
			maxSum=max(maxSum,dp);
		}
		return maxSum;
	}
};

#endif // P53_Solution_2



#define P53_Solution_3		//分治
#ifdef P53_Solution_3

class Solution {
public:
	struct Info{
		int maxLSum;
		int maxRSum;
		int maxSubSum;
		int allSum;
	};
	
	Info pushUp(Info l,Info r){
		int maxLSum=max(l.maxLSum,l.allSum+r.maxLSum);
		int maxRSum=max(r.maxRSum,r.allSum+l.maxRSum);
		int maxSubSum=max(max(l.maxSubSum,r.maxSubSum),l.maxRSum+r.maxLSum);
		int allSum=l.allSum+r.allSum;
		return Info{maxLSum,maxRSum,maxSubSum,allSum};
	}

	Info get(vector<int>& nums,int begin,int end){
		if(end==begin+1){
			return Info{nums[begin],nums[begin],nums[begin],nums[begin]};
		}
		int mid=(end+begin)>>1;
		Info l=get(nums,begin,mid);
		Info r=get(nums,mid,end);
		return pushUp(l,r);
	}

	int maxSubArray(vector<int>& nums) {
		return get(nums,0,nums.size()).maxSubSum;
	}
};

#endif // P53_Solution_3



//#define P53_Test
#ifdef P53_Test

int main(){
	Solution Lee;
	vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
	cout<<Lee.maxSubArray(nums);
}

#endif // P53_Test



#endif // P53_Maximum_subarray_cpp