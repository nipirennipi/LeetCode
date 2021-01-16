#define P206_Reverse_linked_list_cpp
#ifdef P206_Reverse_linked_list_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/reverse-linked-list/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}
	
};

//#define P206_Solution_1		//µü´ú
#ifdef P206_Solution_1

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* front=nullptr;
		ListNode* cur=head;
		while(cur){
			ListNode* back=cur->next;
			cur->next=front;
			front=cur;
			cur=back;
		}
		return front;
	}
};

#endif // P206_Solution_1



#define P206_Solution_2		//µÝ¹é
#ifdef P206_Solution_2

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if(!head||!head->next){
			return head;
		}
		ListNode* back=reverseList(head->next);
		head->next->next=head;
		head->next=nullptr;
		return back;
	}
};

#endif // P206_Solution_2



//#define P206_Test
#ifdef P206_Test

int main(){
	Solution Lee;
}

#endif // P206_Test



#endif // P206_Reverse_linked_list_cpp