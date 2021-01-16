#define P283_Move_zeroes_cpp
#ifdef P283_Move_zeroes_cpp

//链接：https://leetcode-cn.com/problems/move-zeroes/

#include"stdafx.h"

//#define P283_Solution_1			//两次遍历
#ifdef P283_Solution_1

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int count=0;
		for(int i=0;i<nums.size();++i){
			if(nums[i]){
				nums[count]=nums[i];
				++count;
			}
		}
		for(int i=count;i<nums.size();++i){
			nums[i]=0;
		}
	}
};

#endif // P283_Solution_1



#define P283_Solution_2			//一次遍历(双指针)
#ifdef P283_Solution_2

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int j=0;
		for(int i=0;i<nums.size();++i){
			if(nums[i]){
				if(j<i){			//交换nums[i]、nums[j]
					nums[i]+=nums[j];
					nums[j]=nums[i]-nums[j];
					nums[i]=nums[i]-nums[j];
				}				
				++j;
			}
		}
	}
};

#endif // P283_Solution_2



//#define P283_Test
#ifdef P283_Test

int main(){
	Solution Lee;
}

#endif // P283_Test



#endif // P283_Move_zeroes_cpp