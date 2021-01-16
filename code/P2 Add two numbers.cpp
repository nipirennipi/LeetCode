#define P2_Add_two_numbers_cpp
#ifdef P2_Add_two_numbers_cpp

//链接：https://leetcode-cn.com/problems/add-two-numbers

#include"stdafx.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}

};

#define P2_Solution_1
#ifdef P2_Solution_1

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1,ListNode* l2) {
		ListNode* first=new ListNode(-1);		//存放结果的链表，头指针为first，第一个结点为无用结点
		ListNode* cur=first;

		ListNode* p1=l1;
		ListNode* p2=l2;

		int sum;			
		int carry=0;							//进位标志

		while(p1||p2){
			int x=p1?p1->val:0;
			int y=p2?p2->val:0;
			sum=x+y+carry;
			carry=sum/10;
			cur->next=new ListNode(sum%10);
			cur=cur->next;
			if(p1){
				p1=p1->next;
			}
			if(p2){
				p2=p2->next;
			}
		}
		if(carry){
			cur->next=new ListNode(1);
		}
		return first->next;
	}
};

#endif // P2_Solution_1



#define P2_Solution_2
#ifdef P2_Solution_2



#endif // P1_Solution_2



//#define P2_Test
#ifdef P2_Test

int main(){
	ListNode* p1=new ListNode(2);;
	ListNode* cur1=p1;
	cur1->next=new ListNode(4);
	cur1=cur1->next;
	cur1->next=new ListNode(3);


	ListNode* p2=new ListNode(5);;
	ListNode* cur2=p2;
	cur2->next=new ListNode(6);
	cur2=cur2->next;
	cur2->next=new ListNode(4);

	Solution Lee;
	ListNode* ans=Lee.addTwoNumbers(p1,p2);
	ListNode* cur=ans;
	while(cur){
		cout<<cur->val<<"——>";
		cur=cur->next;
	}
}

#endif // P2_Test



#endif // P2_Add_two_numbers_cpp