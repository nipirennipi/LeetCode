#define P392_Is_subsequence_cpp
#ifdef P392_Is_subsequence_cpp

//¡¥Ω”£∫https://leetcode-cn.com/problems/is-subsequence/

#include"stdafx.h"

//#define P392_Solution_1		//±©¡¶À„∑®
#ifdef P392_Solution_1

class Solution {
public:
	bool isSubsequence(string s,string t) {
		if(!s.size()){
			return true;
		}
		int sLen=s.size();
		int tLen=t.size();
		int sCur=0;
		int tCur=0;
		while(tCur<tLen){
			if(s[sCur]==t[tCur]){
				++sCur;
				if(sCur==sLen){
					return true;
				}
			}
			++tCur;
		}
		return false;
	}
};

#endif // P392_Solution_1



#define P392_Solution_2
#ifdef P392_Solution_2



#endif // P392_Solution_2



//#define P392_Test
#ifdef P392_Test

int main(){
	Solution Lee;
}

#endif // P392_Test



#endif // P392_Is_subsequence_cpp