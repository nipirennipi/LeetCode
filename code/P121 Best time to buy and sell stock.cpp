#define P121_Best_time_to_buy_and_sell_stock_cpp
#ifdef P121_Best_time_to_buy_and_sell_stock_cpp

//¡¥Ω”£∫https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

#include"stdafx.h"

//#define P121_Solution_1		//±©¡¶À„∑®£®Time Limit Exceed£©
#ifdef P121_Solution_1

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size=prices.size();
		int maxProfit=0;
		for(int i=0;i<size;++i){
			for(int j=i+1;j<size;++j){
				maxProfit=max(maxProfit,prices[j]-prices[i]);
			}
		}
		return maxProfit;
	}
};

#endif // P121_Solution_1



#define P121_Solution_2
#ifdef P121_Solution_2

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if(!prices.size()){
			return 0;
		}
		int minPrices=prices[0];
		int maxProfit=0;
		for(int i=1;i<prices.size();++i){
			maxProfit=max(maxProfit,prices[i]-minPrices);
			minPrices=min(prices[i],minPrices);
		}
		return maxProfit;
	}
};

#endif // P121_Solution_2



//#define P121_Test
#ifdef P121_Test

int main(){
	Solution Lee;
}

#endif // P121_Test



#endif // P121_Best_time_to_buy_and_sell_stock_cpp