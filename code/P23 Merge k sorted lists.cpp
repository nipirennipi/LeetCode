#define P23_Merge_k_sorted_lists_cpp
#ifdef P23_Merge_k_sorted_lists_cpp

//链接：https://leetcode-cn.com/problems/merge-k-sorted-lists/

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}

};

//#define P23_Solution_1		//两两合并
#ifdef P23_Solution_1

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

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(!lists.size()){
			return nullptr;
		}
		int size=lists.size();
		ListNode* ans=lists[0];
		for(int i=1;i<size;++i){
			ans=mergeTwoLists(ans,lists[i]);
		}
		return ans;
	}
};

#endif // P23_Solution_1



#define P23_Solution_2		//分治
#ifdef P23_Solution_2

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

	ListNode* merge(vector<ListNode*>& lists,int left,int right){
		if(left==right){
			return nullptr;
		}
		if(left+1==right){
			return lists[left];
		}
		int mid=(left+right)>>1;
		return mergeTwoLists(merge(lists,left,mid),merge(lists,mid,right));
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		return merge(lists,0,lists.size());
	}
};

#endif // P23_Solution_2



//#define P23_Test
#ifdef P23_Test

int main(){	
	Solution Lee;
	ListNode* cur=nullptr;
	ListNode* l1=new ListNode(1);
	cur=l1;
	cur->next=new ListNode(4);
	cur=cur->next;
	cur->next=new ListNode(5);

	ListNode* l2=new ListNode(1);
	cur=l2;
	cur->next=new ListNode(3);
	cur=cur->next;
	cur->next=new ListNode(4);

	ListNode* l3=new ListNode(2);
	cur=l3;
	cur->next=new ListNode(6);

	vector<ListNode*> lists(3);		//[[1,4,5],[1,3,4],[2,6]]
	lists[0]=l1;
	lists[1]=l2;
	lists[2]=l3;
	
	Lee.mergeKLists(lists);
}

#endif // P23_Test



#endif // P23_Merge_k_sorted_lists_cpp