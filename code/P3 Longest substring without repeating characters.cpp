#define P3_Longest_substring_without_repeating_characters_cpp
#ifdef P3_Longest_substring_without_repeating_characters_cpp

//链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

#include"stdafx.h"

//#define P3_Solution_1		//暴力算法（hashset）
#ifdef P3_Solution_1

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans=0;
		unordered_set<char> hashset;
		for(int begin=0;begin<s.size();++begin){
			hashset.clear();
			int end=begin;	//导致时间复杂度为O(n^2)
			while(!hashset.count(s[end])&&end<s.size()){
				hashset.insert(s[end]);
				++end;
			}
			ans=(end-begin>ans)?(end-begin):ans;
			if(end==s.size()){
				break;
			}
		}
		return ans;
	}
};

#endif // P3_Solution_1



//#define P3_Solution_2		//滑动窗口（双指针）
#ifdef P3_Solution_2

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int begin=0;
		int end=0;
		int ans=0;

		while(end<s.size()){
			for(int i=begin;i<end;++i){
				if(s[i]==s[end]){
					begin=i+1;
					break;
				}
			}
			++end;
			ans=(end-begin)>ans?(end-begin):ans;
		}
		return ans;
	}
};

#endif // P3_Solution_2



//#define P3_Solution_3		//滑动窗口（hashset）
#ifdef P3_Solution_3

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> hashset;
		int begin=0;
		int end=0;
		int ans=0;

		for(begin=0;begin<s.size();++begin){
			if(begin!=0){
				hashset.erase(s[begin-1]);
			}
			while(!hashset.count(s[end])&&end<s.size()){
				hashset.insert(s[end]);
				++end;
			}
			ans=(end-begin>ans)?(end-begin):ans;
			if(end==s.size()){
				break;
			}
		}
		return ans;
	}
};

#endif // P3_Solution_3



//#define P3_Test
#ifdef P3_Test

int main(){
	string s="abcabcbb";
	Solution Lee;
	cout<<Lee.lengthOfLongestSubstring(s);
}

#endif // P3_Test

#endif // P3_Longest_substring_without_repeating_characters_cpp