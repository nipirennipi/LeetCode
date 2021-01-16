#define P6_Zigzag_conversion_cpp
#ifdef P6_Zigzag_conversion_cpp

//链接：https://leetcode-cn.com/problems/zigzag-conversion/

#include"stdafx.h"

#define P6_Solution_1		//逐行访问
#ifdef P6_Solution_1

class Solution {
public:
	string convert(string s,int numRows) {
		if(numRows==1){
			return s;
		}
		int size=s.size();
		int con=2*(numRows-1);
		string ans;
		for(int i=0;i<numRows;++i){
			for(int j=0;i+j<size;j+=con){
				ans+=s[i+j];
				if(i!=0&&i!=numRows-1&&j+con-i<size){
					ans+=s[j+con-i];
				}
			}
		}
		return ans;
	}
};

//class Solution {
//public:
//	string convert(string s,int numRows) {
//		if(numRows==1){
//			return s;
//		}
//		int size=s.size();
//		int con=2*(numRows-1);
//		string ans;
//		for(int i=0;i<numRows;++i){
//			if(i!=numRows-1){
//				ans+=s[i];
//			}
//			for(int j=con;j-i<size;j+=con){
//				ans+=s[j-i];
//				if(i!=0&&i!=numRows-1&&i+j<size){
//					ans+=s[j+i];
//				}
//			}
//		}
//		return ans;
//	}
//};

#endif // P6_Solution_1



//#define P6_Solution_2		//逐行组合
#ifdef P6_Solution_2

class Solution {
public:
	string convert(string s,int numRows) {
		if(numRows==1){
			return s;
		}
		int size=s.size();
		int pos=0;
		bool turnTo=false;
		vector<string> bucket(numRows);
		for(int i=0;i<s.size();++i){
			bucket[pos]+=s[i];
			if(i%(numRows-1)==0){
				turnTo=!turnTo;
			}
			turnTo?++pos:--pos;
		}
		string ans;
		for(int i=0;i<bucket.size();++i){
			ans+=bucket[i];
		}
		return ans;
	}
};

//class Solution {
//public:
//	string convert(string s,int numRows) {
//		if(numRows==1){
//			return s;
//		}
//		int size=s.size();
//		vector<string> bucket(numRows);
//		int temp;
//		for(int i=0;i<s.size();++i){
//			temp=i%(numRows-1);
//			if(i/(numRows-1)%2){
//				bucket[numRows-1-temp]+=s[i];
//			}
//			else{
//				bucket[temp]+=s[i];
//			}
//		}
//		string ans;
//		for(int i=0;i<bucket.size();++i){
//			ans+=bucket[i];
//		}
//		return ans;
//	}
//};

#endif // P6_Solution_2



//#define P6_Test
#ifdef P6_Test

int main(){
	Solution Lee;
	cout<<Lee.convert("LEETCODEISHIRING",3);
}

#endif // P6_Test



#endif // P6_Zigzag_conversion_cpp