#define P56_Merge_intervals_cpp
#ifdef P56_Merge_intervals_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/merge-intervals/

#include"stdafx.h"

#define P56_Solution_1
#ifdef P56_Solution_1

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(),intervals.end());
		vector<vector<int>> res;
		for(int i=0;i<intervals.size();++i){
			int begin=intervals[i][0];
			int end=intervals[i][1];
			while(i<intervals.size()-1&&end>=intervals[i+1][0]){
				end=max(end,intervals[i+1][1]);
				++i;
			}
			res.push_back(vector<int>{begin,end});
		}
		return res;
	}
};

#endif // P56_Solution_1



#define P56_Solution_2
#ifdef P56_Solution_2



#endif // P56_Solution_2



//#define P56_Test
#ifdef P56_Test

int main(){
	Solution Lee;
}

#endif // P56_Test



#endif // P56_Merge_intervals_cpp