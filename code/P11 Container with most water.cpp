#define P11_Container_with_most_water_cpp
#ifdef P11_Container_with_most_water_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/container-with-most-water/

#include"stdafx.h"

#define P11_Solution_1
#ifdef P11_Solution_1

class Solution {
public:
	int maxArea(vector<int>& height) {
		int size=height.size();
		int left=0;
		int right=size-1;
		int ans=0;
		while(left<right){
			int temp=(right-left)*min(height[left],height[right]);
			ans=temp>ans?temp:ans;
			if(height[left]>height[right]){
				--right;
			}
			else{
				++left;
			}
		}
		return ans;
	}
};

#endif // P11_Solution_1



#define P11_Solution_2
#ifdef P11_Solution_2



#endif // P11_Solution_2



//#define P11_Test
#ifdef P11_Test

int main(){
	Solution Lee;
}

#endif // P11_Test



#endif // P11_Container_with_most_water_cpp