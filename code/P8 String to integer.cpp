#define P8_String_to_integer_cpp
#ifdef P8_String_to_integer_cpp

//链接：https://leetcode-cn.com/problems/string-to-integer-atoi/

#include"stdafx.h"

#define P8_Solution_1
#ifdef P8_Solution_1

class Solution {
public:
	int myAtoi(string str) {
		int size=str.size();
		if(size==0){
			return 0;
		}
		int pos=0;
		while(str[pos]==' '&&pos<size){
			++pos;
		}
		if(str[pos]!='+'&&str[pos]!='-'&&!('0'<=str[pos]&&str[pos]<='9')){
			return 0;
		}
		bool sign=true;			//true代表'+'，false代表'-'
		if(str[pos]=='+'||str[pos]=='-'){
			sign=str[pos]=='+';
			++pos;
		}
		int ans=0;
		while(pos<size&&('0'<=str[pos]&&str[pos]<='9')){
			if(ans>INT_MAX/10){
				if(sign){
					return INT_MAX;
				}
				return INT_MIN;
			}
			if(ans==INT_MAX/10){
				if(sign&&(str[pos]-'0')>=7){
					return INT_MAX;
				}
				if(!sign&&(str[pos]-'0')>=8){
					return INT_MIN;
				}
			}
			ans=ans*10+(str[pos]-'0');
			++pos;
		}
		return sign?ans:-ans;
	}
};

#endif // P8_Solution_1



#define P8_Solution_2
#ifdef P8_Solution_2



#endif // P8_Solution_2



//#define P8_Test
#ifdef P8_Test

int main(){
	Solution Lee;
	cout<<Lee.myAtoi("-2147483648");
}

#endif // P8_Test



#endif // P8_String_to_integer_cpp