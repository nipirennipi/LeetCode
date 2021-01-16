#define P657_Robot_return_to_origin_cpp
#ifdef P657_Robot_return_to_origin_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/robot-return-to-origin/

#include"stdafx.h"

#define P657_Solution_1
#ifdef P657_Solution_1

class Solution {
public:
	bool judgeCircle(string moves) {
		int x=0;
		int y=0;
		int len=moves.size();
		for(int i=0;i<len;++i){
			switch(moves[i]){
				case 'R':
					++x;
					break;
				case 'L':
					--x;
					break;
				case 'U':
					++y;
					break;
				case 'D':
					--y;
			}
		}
		return x==0&&y==0;
	}
};

#endif // P657_Solution_1



#define P657_Solution_2
#ifdef P657_Solution_2



#endif // P657_Solution_2



//#define P657_Test
#ifdef P657_Test

int main(){
	Solution Lee;
}

#endif // P657_Test



#endif // P657_Robot_return_to_origin_cpp