#define P122_Best_time_to_buy_and_sell_stock_ii_cpp
#ifdef P122_Best_time_to_buy_and_sell_stock_ii_cpp

//链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

#include"stdafx.h"

//#define P122_Solution_1		//贪心算法
#ifdef P122_Solution_1

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size=prices.size();
		int maxProfit=0;
		for(int i=1;i<size;++i){
			if(prices[i]>prices[i-1]){
				maxProfit+=(prices[i]-prices[i-1]);
			}
		}
		return maxProfit;
	}
};

#endif // P122_Solution_1



//#define P122_Solution_2			//动态规划
#ifdef P122_Solution_2

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size=prices.size();
		vector<int> cash(size);
		vector<int> stock(size);
		cash[0]=0;
		stock[0]=-prices[0];
		for(int i=1;i<size;++i){
			cash[i]=max(cash[i-1],stock[i-1]+prices[i]);
			stock[i]=max(stock[i-1],cash[i-1]-prices[i]);
		}
		return cash[size-1];
	}
};

#endif // P122_Solution_2



#define P122_Solution_3		//动态规划 + 滚动数组
#ifdef P122_Solution_3

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size=prices.size();
		int cash=0;
		int stock=-prices[0];
		int cashTemp;
		for(int i=1;i<size;++i){
			cashTemp=cash;
			cash=max(cash,stock+prices[i]);
			stock=max(stock,cashTemp-prices[i]);
		}
		return cash;
	}
};

#endif // P122_Solution_3



//#define P122_Test
#ifdef P122_Test

int main(){
	Solution Lee;
}

#endif // P122_Test



#endif // P122_Best_time_to_buy_and_sell_stock_ii_cpp