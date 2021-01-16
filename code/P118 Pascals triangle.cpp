#define P118_Pascals_triangle_cpp
#ifdef P118_Pascals_triangle_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/pascals-triangle/

#include"stdafx.h"

#define P118_Solution_1
#ifdef P118_Solution_1

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows);
		for(int i=0;i<numRows;++i){
			res[i]=vector<int>(i+1,1);
			for(int j=1;j<i;++j){
				res[i][j]=res[i-1][j-1]+res[i-1][j];
			}
		}
		return res;
	}
};

#endif // P118_Solution_1



#define P118_Solution_2
#ifdef P118_Solution_2



#endif // P118_Solution_2



//#define P118_Test
#ifdef P118_Test

int main(){
	Solution Lee;
}

#endif // P118_Test



#endif // P118_Pascals_triangle_cpp