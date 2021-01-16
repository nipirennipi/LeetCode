#define P1_Sum_of_two_numbers_cpp
#ifdef P1_Sum_of_two_numbers_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/two-sum

#include"stdafx.h"

//#define P1_Solution_1
#ifdef P1_Solution_1

class Solution {
public:
	vector<int> twoSum(vector<int>& nums,int target) {
		for(int i=0;i<nums.size();++i){
			for(int j=i+1;j<nums.size();++j){
				if(nums[i]+nums[j]==target){
					return vector<int> {i,j};
				}
			}
		}
		return vector<int>();
	}
};

#endif // P1_Solution_1



//#define P1_Solution_2
#ifdef P1_Solution_2

class Solution {
public:
	vector<int> twoSum(vector<int>& nums,int target) {
		unordered_map<int,int> hashmap;
		for(int i=0;i<nums.size();++i){
			if(hashmap[target-nums[i]]){
				return vector<int> {i,hashmap[target-nums[i]]-1};
			}
			hashmap[nums[i]]=i+1;
		}
		return vector<int>();
	}
};

#endif // P1_Solution_2



#endif // P1_Sum_of_two_numbers_cpp
