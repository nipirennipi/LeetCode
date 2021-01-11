#define P5_Longest_palindrome_substring_cpp
#ifdef P5_Longest_palindrome_substring_cpp

//链接：https://leetcode-cn.com/problems/longest-palindromic-substring/

#include"stdafx.h"

//#define P5_Solution_1			//暴力算法
#ifdef P5_Solution_1

class Solution {
public:
	string longestPalindrome(string s) {
		int size=s.size();
		int target=0;				//标记最长回文子串的起始位置
		int maxLen=1;				//记录最长回文子串长度，单个字符为一个回文子串
		for(int begin=0;begin<=size-2;++begin){
			for(int end=begin+1;end<size;++end){
				if(end-begin+1>maxLen&&isPalindrome(s,begin,end)){
					maxLen=end-begin+1;
					target=begin;
				}
			}
		}
		return s.substr(target,maxLen);
	}

	bool isPalindrome(string s,int begin,int end){
		while(end>begin){
			if(s[begin]!=s[end]){
				return false;
			}
			++begin;
			--end;
		}
		return true;
	}
};

#endif // P5_Solution_1



//#define P5_Solution_2			//中心扩散法
#ifdef P5_Solution_2

class Solution {
public:
	string longestPalindrome(string s) {
		int size=s.size();
		int target=0;				//标记最长回文子串的中心位置
		int maxLen=1;				//记录最长回文子串长度，单个字符为一个回文子串
		for(int i=0;i<=size-2;++i){
			int oddLen=centerSpread(s,i,i);		//寻找长度为奇数的回文子串，中心字符为i
			int evenLen=centerSpread(s,i,i+1);	//寻找长度为偶数的回文子串，中心字符为i、i+1
			if(max(oddLen,evenLen)>maxLen){
				maxLen=max(oddLen,evenLen);
				target=i;
			}
		}
		return s.substr(target-(maxLen-1)/2,maxLen);
	}

	int centerSpread(string s,int begin,int end){
		int size=s.size();
		while(0<=begin&&end<size){
			if(s[begin]!=s[end]){
				break;
			}
			--begin;
			++end;
		}
		return end-begin-1;
	}
};

#endif // P5_Solution_2



#define P5_Solution_3
#ifdef P5_Solution_3



#endif // P5_Solution_3



//#define P5_Test
#ifdef P5_Test

int main(){
	Solution Lee;
	cout<<Lee.longestPalindrome("gerfwe abababa dewfwe");
}

#endif // P5_Test



#endif // P5_Longest_palindrome_substring_cpp