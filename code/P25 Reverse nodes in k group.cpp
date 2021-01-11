#define P25_Reverse_nodes_in_k_group_cpp
#ifdef P25_Reverse_nodes_in_k_group_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/reverse-nodes-in-k-group/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}
};

#define P25_Solution_1
#ifdef P25_Solution_1

class Solution {
public:
	ListNode* reverseList(ListNode* begin,ListNode* end) {
		ListNode* front=nullptr;
		ListNode* cur=begin;
		while(front!=end){
			ListNode* back=cur->next;
			cur->next=front;
			front=cur;
			cur=back;
		}
		return front;
	}

	ListNode* reverseKGroup(ListNode* head,int k) {
		ListNode* useless=new ListNode(0);
		useless->next=head;
		ListNode* front=useless;
		ListNode* begin=front->next;
		while(begin){
			ListNode* end=begin;
			for(int i=1;i<k;++i){
				end=end->next;
				if(!end){
					ListNode* ans=useless->next;
					delete useless;
					return ans;
				}
			}
			ListNode* back=end->next;
			reverseList(begin,end);
			front->next=end;
			begin->next=back;
			front=begin;
			begin=back;
		}	
		ListNode* ans=useless->next;
		delete useless;
		return ans;
	}
};

#endif // P25_Solution_1



#define P25_Solution_2
#ifdef P25_Solution_2



#endif // P25_Solution_2



//#define P25_Test
#ifdef P25_Test

int main(){
	Solution Lee;
	ListNode* head=new ListNode(1);
	ListNode* cur=head;
	for(int i=2;i<=5;++i){
		ListNode* newNode=new ListNode(i);
		cur->next=newNode;
		cur=cur->next;
	}
	Lee.reverseKGroup(head,2);
}

#endif // P25_Test



#endif // P25_Reverse_nodes_in_k_group_cpp