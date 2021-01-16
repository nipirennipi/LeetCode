#define P9_Palindrome_number_cpp
#ifdef P9_Palindrome_number_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/palindrome-number/

#include"stdafx.h"

//#define P9_Solution_1
#ifdef P9_Solution_1

class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0){
			return false;
		}
		string str;
		do{
			str+=(x%10+48);
			x/=10;
		}while(x);
		int size=str.size();
		for(int i=0;i<=size/2-1;++i){
			if(str[i]!=str[size-1-i]){
				return false;
			}
		}
		return true;
	}
};

#endif // P9_Solution_1



#define P9_Solution_2
#ifdef P9_Solution_2

class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0||(x!=0&&x%10==0)){
			return false;
		}
		int secondHalf=0;
		while(x>secondHalf){
			secondHalf=secondHalf*10+x%10;
			x/=10;
		}
		return x==secondHalf||x==secondHalf/10;
	}
};

#endif // P9_Solution_2



//#define P9_Test
#ifdef P9_Test

int main(){
	Solution Lee;
	cout<<Lee.isPalindrome(121)<<'\n';
	cout<<Lee.isPalindrome(-121)<<'\n';
	cout<<Lee.isPalindrome(1)<<'\n';
	cout<<Lee.isPalindrome(123)<<'\n';
}

#endif // P9_Test



#endif // P9_Palindrome_number_cpp