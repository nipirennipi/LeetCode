#define P83_Remove_duplicates_from_sorted_list_cpp
#ifdef P83_Remove_duplicates_from_sorted_list_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}
};

#define P83_Solution_1
#ifdef P83_Solution_1

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* cur=head;
		while(cur){
			if(cur->next&&cur->val==cur->next->val){
				ListNode* del=cur->next;
				cur->next=del->next;
				delete del;
			}
			else{
				cur=cur->next;
			}
		}
		return head;
	}
};

#endif // P83_Solution_1



#define P83_Solution_2
#ifdef P83_Solution_2



#endif // P83_Solution_2



//#define P83_Test
#ifdef P83_Test

int main(){
	Solution Lee;
}

#endif // P83_Test



#endif // P83_Remove_duplicates_from_sorted_list_cpp