#define P82_Remove_duplicates_from_sorted_list_ii_cpp
#ifdef P82_Remove_duplicates_from_sorted_list_ii_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}
};

#define P82_Solution_1
#ifdef P82_Solution_1

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* useless=new ListNode(0);
		useless->next=head;
		ListNode* front=useless;
		ListNode* back=useless->next;
		while(back){
			ListNode* temp=back;
			while(back->next&&back->val==back->next->val){
				ListNode* del=back;
				back=back->next;
				delete del;
			}
			if(temp!=back){
				ListNode* del=back;
				back=back->next;
				delete del;
				front->next=back;
			}
			else{
				front=back;
				back=back->next;
			}
		}
		ListNode* ans=useless->next;
		delete useless;
		return ans;
	}
};

#endif // P82_Solution_1



#define P82_Solution_2
#ifdef P82_Solution_2



#endif // P82_Solution_2



//#define P82_Test
#ifdef P82_Test

int main(){
	Solution Lee;
	ListNode* head=new ListNode(0);
	ListNode* cur=head;	
	for(int i=1;i<=4;++i){
		cur->next=new ListNode(0);
		cur=cur->next;
	}
	Lee.deleteDuplicates(head);
}

#endif // P82_Test



#endif // P82_Remove_duplicates_from_sorted_list_ii_cpp