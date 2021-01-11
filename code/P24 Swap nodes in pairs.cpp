#define P24_Swap_nodes_in_pairs_cpp
#ifdef P24_Swap_nodes_in_pairs_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/swap-nodes-in-pairs/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}
};

#define P24_Solution_1		//µü´ú
#ifdef P24_Solution_1

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* useless=new ListNode(0);
		useless->next=head;
		ListNode* front=useless;
		ListNode* begin=front->next;
		while(begin){	
			ListNode* end=begin->next;
			if(!end){
				break;
			}
			ListNode* back=end->next;
			end->next=begin;
			begin->next=back;
			front->next=end;
			front=begin;
			begin=back;
		}
		ListNode* ans=useless->next;
		delete useless;
		return ans;
	}
};

#endif // P24_Solution_1



#define P24_Solution_2
#ifdef P24_Solution_2



#endif // P24_Solution_2



//#define P24_Test
#ifdef P24_Test

int main(){
	Solution Lee;
	ListNode* head=new ListNode(1);
	ListNode* cur=head;
	for(int i=2;i<=4;++i){
		cur->next=new ListNode(i);
		cur=cur->next;
	}
	Lee.swapPairs(head);
}

#endif // P24_Test



#endif // P24_Swap_nodes_in_pairs_cpp