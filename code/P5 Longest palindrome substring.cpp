#define P5_Longest_palindrome_substring_cpp
#ifdef P5_Longest_palindrome_substring_cpp

//���ӣ�https://leetcode-cn.com/problems/longest-palindromic-substring/

#include"stdafx.h"

//#define P5_Solution_1			//�����㷨
#ifdef P5_Solution_1

class Solution {
public:
	string longestPalindrome(string s) {
		int size=s.size();
		int target=0;				//���������Ӵ�����ʼλ��
		int maxLen=1;				//��¼������Ӵ����ȣ������ַ�Ϊһ�������Ӵ�
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



//#define P5_Solution_2			//������ɢ��
#ifdef P5_Solution_2

class Solution {
public:
	string longestPalindrome(string s) {
		int size=s.size();
		int target=0;				//���������Ӵ�������λ��
		int maxLen=1;				//��¼������Ӵ����ȣ������ַ�Ϊһ�������Ӵ�
		for(int i=0;i<=size-2;++i){
			int oddLen=centerSpread(s,i,i);		//Ѱ�ҳ���Ϊ�����Ļ����Ӵ��������ַ�Ϊi
			int evenLen=centerSpread(s,i,i+1);	//Ѱ�ҳ���Ϊż���Ļ����Ӵ��������ַ�Ϊi��i+1
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