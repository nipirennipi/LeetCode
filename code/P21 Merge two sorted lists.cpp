#define P21_Merge_two_sorted_lists_cpp
#ifdef P21_Merge_two_sorted_lists_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/merge-two-sorted-lists/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0),next(nullptr) {}
	ListNode(int x) : val(x),next(nullptr) {}
	ListNode(int x,ListNode* next) : val(x),next(next) {}
};

//#define P21_Solution_1		//µü´ú
#ifdef P21_Solution_1

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1,ListNode* l2) {
		ListNode* head=new ListNode(0);
		ListNode* tail=head;
		while(l1&&l2){
			if(l1->val<=l2->val){
				tail->next=l1;
				l1=l1->next;
			}
			else{
				tail->next=l2;
				l2=l2->next;
			}
			tail=tail->next;
		}
		if(!l1){
			tail->next=l2;
		}
		else{
			tail->next=l1;
		}
		ListNode* ans=head->next;
		delete head;
		return ans;
	}
};

#endif // P21_Solution_1



#define P21_Solution_2		//µÝ¹é
#ifdef P21_Solution_2

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1,ListNode* l2) {
		if(!l1){
			return l2;
		}
		if(!l2){
			return l1;
		}
		ListNode* head=nullptr;
		if(l1->val<=l2->val){
			head=mergeTwoLists(l1->next,l2);
			l1->next=head;
			return l1;
		}
		else{
			head=mergeTwoLists(l1,l2->next);
			l2->next=head;
			return l2;
		}
	}
};

#endif // P21_Solution_2



//#define P21_Test
#ifdef P21_Test

int main(){
	Solution Lee;
}

#endif // P21_Test



#endif // P21_Merge_two_sorted_lists_cpp