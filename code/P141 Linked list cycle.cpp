#define P141_Linked_list_cycle_cpp
#ifdef P141_Linked_list_cycle_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/linked-list-cycle/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}

};

#define P141_Solution_1		//¿ìÂýÖ¸Õë
#ifdef P141_Solution_1

class Solution {
public:
	bool hasCycle(ListNode* head) {
		ListNode* fast=head;
		ListNode* low=head;
		while(fast&&fast->next){
			fast=fast->next->next;
			low=low->next;
			if(fast==low){
				return true;
			}
		}
		return false;
	}
};

#endif // P141_Solution_1



#define P141_Solution_2
#ifdef P141_Solution_2



#endif // P141_Solution_2



//#define P141_Test
#ifdef P141_Test

int main(){
	Solution Lee;
}

#endif // P141_Test



#endif // P141_Linked_list_cycle_cpp