#define P55_Jump_game_cpp
#ifdef P55_Jump_game_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/jump-game/

#include"stdafx.h"

#define P55_Solution_1		//Ì°ÐÄËã·¨
#ifdef P55_Solution_1

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size=nums.size();
		int maxPos=0;
		for(int i=0;i<size&&i<=maxPos;++i){
			maxPos=max(i+nums[i],maxPos);
			if(maxPos>=size-1){
				return true;
			}
		}
		return false;
	}
};

#endif // P55_Solution_1



#define P55_Solution_2
#ifdef P55_Solution_2



#endif // P55_Solution_2



//#define P55_Test
#ifdef P55_Test

int main(){
	Solution Lee;
}

#endif // P55_Test



#endif // P55_Jump_game_cpp