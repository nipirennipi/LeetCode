#define P123_Best_time_to_buy_and_sell_stock_iii_cpp
#ifdef P123_Best_time_to_buy_and_sell_stock_iii_cpp

//链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

#include"stdafx.h"

//#define P123_Solution_1		//递归（Time Limit Exceed）
#ifdef P123_Solution_1

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		return ways(prices,0,0,0);
	}

	int ways(vector<int>& prices,int pos,int statu,int count){
		if(pos==prices.size()||count==2){
			return 0;
		}
		int hold=ways(prices,pos+1,statu,count);
		int sell=0;
		int buy=0;
		if(statu){
			sell=ways(prices,pos+1,0,count+1)+prices[pos];
		}
		else{
			buy=ways(prices,pos+1,1,count)-prices[pos];
		}
		return max(max(hold,sell),buy);
	}
};

#endif // P123_Solution_1



//#define P123_Solution_2		//记忆型递归（Time Limit Exceed）
#ifdef P123_Solution_2

struct Key{
	int pos;
	int statu;
	int count;
	Key(){}
	Key(int p,int s,int c):pos(p),statu(s),count(c){}
	bool operator<(const Key& right)const{
		return pos<right.pos||(!(right.pos<pos)&&statu<right.statu)||(!(right.pos<pos)&&!(right.statu<statu)&&!(statu<right.statu)&&count<right.count);
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		map<Key,int> memory;
		return ways(memory,prices,0,0,0);
	}

	int ways(map<Key,int>& memory,vector<int>& prices,int pos,int statu,int count){
		if(pos==prices.size()||count==2){
			memory[Key(pos,statu,count)]=0;
			return 0;
		}
		if(memory.count(Key(pos,statu,count))){
			return memory[Key(pos,statu,count)];
		}
		int hold=ways(memory,prices,pos+1,statu,count);
		int sell=0;
		int buy=0;
		if(statu){
			sell=ways(memory,prices,pos+1,0,count+1)+prices[pos];
		}
		else{
			buy=ways(memory,prices,pos+1,1,count)-prices[pos];
		}
		int maxProfit=max(max(hold,sell),buy);
		memory[Key(pos,statu,count)]=maxProfit;
		return maxProfit;
	}
};

#endif // P123_Solution_2



//#define P123_Solution_3		//动态规划 + 三维数组
#ifdef P123_Solution_3

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size=prices.size();
		if(size<=1){
			return 0;
		}
		if(size==2){
			return max(0,prices[1]-prices[0]);
		}
		vector<vector<vector<int>>> dp(size,vector<vector<int>>(2,vector<int>(3,0)));
		dp[0][1][0]=-prices[0];

		dp[1][0][1]=dp[0][1][0]+prices[1];
		dp[1][1][0]=max(dp[0][1][0],dp[0][0][0]-prices[1]);

		dp[2][0][1]=max(dp[1][0][1],dp[1][1][0]+prices[2]);
		dp[2][1][0]=max(dp[1][1][0],dp[1][0][0]-prices[2]);
		dp[2][1][1]=dp[1][0][1]-prices[2];
		if(size==3){
			return max(dp[2][0][0],dp[2][0][1]);
		}
		for(int i=3;i<size;++i){
			dp[i][0][1]=max(dp[i-1][0][1],dp[i-1][1][0]+prices[i]);
			dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-prices[i]);
			dp[i][1][1]=max(dp[i-1][1][1],dp[i-1][0][1]-prices[i]);
			dp[i][0][2]=max(dp[i-1][0][2],dp[i-1][1][1]+prices[i]);
		}
		return max(dp[size-1][0][0],max(dp[size-1][0][1],dp[size-1][0][2]));
	}
};

#endif // P123_Solution_3



//#define P123_Solution_4		//动态规划 + 二维数组
#ifdef P123_Solution_4

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size=prices.size();
		if(size<=1){
			return 0;
		}
		if(size==2){
			return max(0,prices[1]-prices[0]);
		}
		vector<vector<int>> dp(2,vector<int>(3,0));
		
		dp[1][0]=-prices[0];

		dp[0][1]=dp[1][0]+prices[1];
		dp[1][0]=max(dp[1][0],dp[0][0]-prices[1]);

		dp[1][1]=dp[0][1]-prices[2];
		dp[0][1]=max(dp[0][1],dp[1][0]+prices[2]);
		dp[1][0]=max(dp[1][0],dp[0][0]-prices[2]);

		if(size==3){
			return max(dp[0][0],dp[0][1]);
		}
		for(int i=3;i<size;++i){
			dp[0][2]=max(dp[0][2],dp[1][1]+prices[i]);
			dp[1][1]=max(dp[1][1],dp[0][1]-prices[i]);
			dp[0][1]=max(dp[0][1],dp[1][0]+prices[i]);
			dp[1][0]=max(dp[1][0],dp[0][0]-prices[i]);
		}
		return max(dp[0][0],max(dp[0][1],dp[0][2]));
	}
};

#endif // P123_Solution_4



#define P123_Solution_5		//动态规划 + 变量
#ifdef P123_Solution_5

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size=prices.size();
		int dp1=0;				//(0,1)
		int dp2=-prices[0];		//(1,0)
		int dp3=-prices[0];		//(1,1)
		int dp4=0;				//(0,2)
		for(int i=1;i<size;++i){
			dp4=max(dp4,dp3+prices[i]);
			dp3=max(dp3,dp1-prices[i]);
			dp1=max(dp1,dp2+prices[i]);
			dp2=max(dp2,-prices[i]);
		}
		return max(0,max(dp1,dp4));
	}
};

#endif // P123_Solution_5



//#define P123_Test
#ifdef P123_Test

int main(){
	Solution Lee;
	vector<int> prices{1,2,3,4,5};
	cout<<Lee.maxProfit(prices);
}

#endif // P123_Test



#endif // P123_Best_time_to_buy_and_sell_stock_iii_cpp