#define P14_Longest_common_prefix_cpp
#ifdef P14_Longest_common_prefix_cpp

//链接：https://leetcode-cn.com/problems/longest-common-prefix/

#include"stdafx.h"

//#define P14_Solution_1		//纵向检查
#ifdef P14_Solution_1

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int size=strs.size();
		if(!size){
			return "";
		}
		int len=strs[0].size();
		for(int i=0;i<len;++i){
			char ref=strs[0][i];
			for(int j=1;j<size;++j){
				if(i==strs[j].size()||strs[j][i]!=ref){
					return strs[0].substr(0,i);
				}
			}
		}
		return strs[0];
	}
};

#endif // P14_Solution_1



#define P14_Solution_2		//横向检查
#ifdef P14_Solution_2

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int size=strs.size();
		if(!size){
			return "";
		}
		string ans=strs[0];
		for(int i=1;i<size;++i){
			for(int j=0;j<ans.size();++j){
				if(j==strs[i].size()||strs[i][j]!=ans[j]){
					ans=ans.substr(0,j);
					if(ans.empty()){
						return "";
					}
					break;
				}
			}
		}
		return ans;
	}
};

#endif // P14_Solution_2



//#define P14_Solution_3	//二分查找
#ifdef P14_Solution_3

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int size=strs.size();
		if(!size){
			return "";
		}
		int minLen=strs[0].size();
		for(int i=1;i<strs.size();++i){
			int temp=strs[i].size();
			minLen=temp<minLen?temp:minLen;
		}
		int left=0;
		int right=minLen;
		while(left<right){
			int mid=left+(right-left+1)/2;
			if(isCommonPrefix(strs,left,mid)){
				left=mid;
			}
			else{
				right=mid-1;
			}
		}
		return strs[0].substr(0,left);
	}

	bool isCommonPrefix(vector<string>& strs,int begin,int end){		//检查strs中各字符串[begin,end)是否相同
		int size=strs.size();
		for(int i=1;i<size;++i){
			for(int j=begin;j<end;++j){
				if(strs[i][j]!=strs[0][j]){
					return false;
				}
			}
		}
		return true;
	}
};

#endif // P14_Solution_3



//#define P14_Solution_4
#ifdef P14_Solution_4

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

	}
};

#endif // P14_Solution_4



//#define P14_Test
#ifdef P14_Test

int main(){
	Solution Lee;
	vector<string> strs{"aa","a"};
	Lee.longestCommonPrefix(strs);
}

#endif // P14_Test



#endif // P14_Longest_common_prefix_cpp