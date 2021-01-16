#define P19_Remove_nth_node_from_end_of_list_cpp
#ifdef P19_Remove_nth_node_from_end_of_list_cpp

//链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}

};

//#define P19_Solution_1		//两次遍历
#ifdef P19_Solution_1

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head,int n) {
		ListNode* dummyNode=new ListNode(0);
		dummyNode->next=head;
		ListNode* cur=head;
		int len=0;
		while(cur){
			cur=cur->next;
			++len;
		}
		cur=dummyNode;
		for(int i=1;i<=len-n;++i){
			cur=cur->next;
		}
		ListNode* del=cur->next;
		cur->next=del->next;
		delete del;
		ListNode* ans=dummyNode->next;
		delete dummyNode;
		return ans;
	}
};

#endif // P19_Solution_1



#define P19_Solution_2		//一次遍历，双指针
#ifdef P19_Solution_2

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head,int n) {
		ListNode* dummyNode=new ListNode(0);
		dummyNode->next=head;
		ListNode* fast=dummyNode;
		ListNode* slow=dummyNode;
		for(int i=1;i<=n+1;++i){
			fast=fast->next;
		}
		while(fast){
			fast=fast->next;
			slow=slow->next;
		}
		ListNode* del=slow->next;
		slow->next=del->next;
		delete del;
		ListNode* ans=dummyNode->next;
		delete dummyNode;
		return ans;
	}
};

#endif // P19_Solution_2



//#define P19_Test
#ifdef P19_Test

int main(){
	Solution Lee;
	ListNode* head=new ListNode(1);
	Lee.removeNthFromEnd(head,1);
}

#endif // P19_Test



#endif // P19_Remove_nth_node_from_end_of_list_cpp