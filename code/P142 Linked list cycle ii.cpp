#define P142_Linked_list_cycle_ii_cpp
#ifdef P142_Linked_list_cycle_ii_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/linked-list-cycle-ii/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}
};

#define P142_Solution_1		//¿ìÂýÖ¸Õë
#ifdef P142_Solution_1

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		ListNode* fast=head;
		ListNode* low=head;
		while(fast&&fast->next){
			fast=fast->next->next;
			low=low->next;
			if(fast==low){
				break;
			}
		}
		if(!fast||!fast->next){		
			return nullptr;
		}
		fast=head;
		while(fast!=low){
			fast=fast->next;
			low=low->next;
		}
		return fast;
	}
};

#endif // P142_Solution_1



#define P142_Solution_2
#ifdef P142_Solution_2



#endif // P142_Solution_2



//#define P142_Test
#ifdef P142_Test

int main(){
	Solution Lee;
}

#endif // P142_Test



#endif // P142_Linked_list_cycle_ii_cpp