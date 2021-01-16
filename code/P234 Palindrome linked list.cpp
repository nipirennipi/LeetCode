#define P234_Palindrome_linked_list_cpp
#ifdef P234_Palindrome_linked_list_cpp

//链接：https://leetcode-cn.com/problems/palindrome-linked-list/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}
};

#define P234_Solution_1			//反转链表 + 双指针
#ifdef P234_Solution_1

class Solution {
private:
	ListNode* reverse(ListNode* head){
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
public:
	bool isPalindrome(ListNode* head) {
		if(!head){
			return true;
		}
		ListNode* fast=head;
		ListNode* slow=head;
		while(fast->next&&fast->next->next){
			fast=fast->next->next;
			slow=slow->next;
		}
		slow->next=reverse(slow->next);
		ListNode* mid=slow;
		fast=head;
		bool ispalin=true;
		while(slow->next){
			slow=slow->next;
			if(fast->val!=slow->val){
				ispalin=false;
				break;
			}
			fast=fast->next;
		}
		mid->next=reverse(mid->next);
		return ispalin;
	}
};

#endif // P234_Solution_1



#define P234_Solution_2
#ifdef P234_Solution_2



#endif // P234_Solution_2



//#define P234_Test
#ifdef P234_Test

int main(){
	Solution Lee;
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	Lee.isPalindrome(head);
}

#endif // P234_Test



#endif // P234_Palindrome_linked_list_cpp