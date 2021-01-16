#define P50_Powx_n_cpp
#ifdef P50_Powx_n_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/powx-n/

#include"stdafx.h"

#define P50_Solution_1		//¿ìËÙÃÝ
#ifdef P50_Solution_1

class Solution {
public:
	double myPow(double x,int n) {
		long long ln=n;
		if(!x){
			return 0;
		}
		double result=1;
		if(ln<0){
			x=1/x;
			ln=-ln;
		}
		while(ln>0){
			if(ln&1){
				result=result*x;
			}
			x*=x;
			ln>>=1;
		}
		return result;
	}
};

#endif // P50_Solution_1



#define P50_Solution_2
#ifdef P50_Solution_2



#endif // P50_Solution_2



//#define P50_Test
#ifdef P50_Test

int main(){
	Solution Lee;
	cout<<Lee.myPow(2.00000,10)<<"\n";
	cout<<Lee.myPow(2.10000,3)<<"\n";
	cout<<Lee.myPow(2.00000,-2)<<"\n";
}

#endif // P50_Test



#endif // P50_Powx_n_cpp