#define P830_Positions_of_large_groups_cpp
#ifdef P830_Positions_of_large_groups_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/positions-of-large-groups/

#include"stdafx.h"

#define P830_Solution_1
#ifdef P830_Solution_1

class Solution {
public:
	vector<vector<int>> largeGroupPositions(string s) {
		vector<vector<int>> res;
		int count=1;
		for(int i=0;i<s.size();++i){
			if(i!=s.size()-1&&s[i]==s[i+1]){
				++count;
			}
			else{
				if(count>=3){
					res.push_back(vector<int>{i-count+1,i});
				}
				count=1;
			}
		}
		return res;
	}
};

#endif // P830_Solution_1



#define P830_Solution_3
#ifdef P830_Solution_3



#endif // P830_Solution_3



//#define P830_Test
#ifdef P830_Test

int main(){
	Solution Lee;
	Lee.largeGroupPositions("abbxxxxzz");
}

#endif // P830_Test



#endif // P830_Positions_of_large_groups_cpp