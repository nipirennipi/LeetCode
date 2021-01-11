#define P92_Reverse_linked_list_ii_cpp
#ifdef P92_Reverse_linked_list_ii_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/reverse-linked-list-ii/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}

};

#define P92_Solution_1
#ifdef P92_Solution_1

class Solution {
public:
	ListNode* reverseBetween(ListNode* head,int m,int n) {
		ListNode* useless=new ListNode(0);
		useless->next=head;
		ListNode* front=useless;
		for(int i=1;i<m&&front;++i){
			front=front->next;
		}
		ListNode* p1=front->next;
		ListNode* p2=p1->next;
		ListNode* p3=nullptr;
		for(int i=m;i<n;++i){
			p3=p2->next;
			p2->next=p1;
			p1=p2;
			p2=p3;
		}
		front->next->next=p2;
		front->next=p1;
		return useless->next;
	}
};

#endif // P92_Solution_1



#define P92_Solution_2
#ifdef P92_Solution_2



#endif // P92_Solution_2



//#define P92_Test
#ifdef P92_Test

int main(){
	Solution Lee;
	ListNode* head=new ListNode(1);			//[1,2,3,4,5],2,4
	ListNode* cur=head;
	for(int i=2;i<=5;++i){
		cur->next=new ListNode(i);
		cur=cur->next;
	}
	Lee.reverseBetween(head,2,4);

}

#endif // P92_Test



#endif // P92_Reverse_linked_list_ii_cpp