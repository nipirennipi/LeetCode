#define P7_Reverse_integer_cpp
#ifdef P7_Reverse_integer_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/reverse-integer/

#include"stdafx.h"

//#define P7_Solution_1
#ifdef P7_Solution_1

class Solution {
public:
	int reverse(int x) {
		int ans=0;
		int temp;
		while(x){
			temp=(unsigned)(ans)*10;
			if(temp/10!=ans){
				return 0;
			}
			ans=temp+x%10;
			x/=10;
		}
		return ans;
	}
};

#endif // P7_Solution_1



#define P7_Solution_2
#ifdef P7_Solution_2

class Solution {
public:
	int reverse(int x) {
		int ans=0;
		while(x){
			if(ans>INT_MAX/10||ans<INT_MIN/10){
				return 0;
			}
			ans=ans*10+x%10;
			x/=10;
		}
		return ans;
	}
};

#endif // P7_Solution_2



//#define P7_Test
#ifdef P7_Test

int main(){
	Solution Lee;
	cout<<Lee.reverse(1534236469);
}


#endif // P7_Test



#endif // P7_Reverse_integer_cpp