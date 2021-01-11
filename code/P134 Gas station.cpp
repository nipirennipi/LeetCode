#define P134_Gas_station_cpp
#ifdef P134_Gas_station_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/gas-station/

#include"stdafx.h"

#define P134_Solution_1		
#ifdef P134_Solution_1

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas,vector<int>& cost) {
		int size=gas.size();
		int lowest=0;
		int minLeft=0;
		int curLeft=0;
		for(int i=0;i<size;++i){
			curLeft+=gas[i]-cost[i];
			if(curLeft<minLeft){
				minLeft=curLeft;
				lowest=i+1;
			}
		}
		if(curLeft<0){
			return -1;
		}
		return lowest;
	}
};

#endif // P134_Solution_1



#define P134_Solution_2
#ifdef P134_Solution_2



#endif // P134_Solution_2



//#define P134_Test
#ifdef P134_Test

int main(){
	Solution Lee;
}

#endif // P134_Test



#endif // P134_Gas_station_cpp