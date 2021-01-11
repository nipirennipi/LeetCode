# P2 两数相加
@[toc]

题目链接：[2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/).

## 题目描述
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

**示例：**
>输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

## 题解
==**思路**==

由题目描述可知，两个整数是按照逆序的方式存储在两个链表中的，以低位开始，那就可以从链表头开始同步遍历这两个链表，每移动一步，将两结点上的两个数（**x**，**y**）相加起来，由于是两个个位数之和（**sum**），所以**sum**的范围为：[0,18]，当**sum**≥10时，产生进位**carry**，所以我们在计算**sum**时，**sum**=**x**+**y**+**carry**。

若这两个链表的长度不一样，那么在短链表遍历完时，在之后的结点相加中，短链表的结点值均为0

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200812231747964.png#pic_center)

当两个链表均遍历完成时，还需要检验一次**carry**，若**carry**=1，则还需要在结果链表尾再添加一个值为1的结点。

==**算法**==

伪代码：
- ①创建结果链表，头指针为**first**，并先添加一个无用结点
- ②进位标志**carry**初始化为0
- ③**p1**，**p2**分别初始化为两个链表的头指针
- ④使用**p1**，**p2**遍历这两个链表，直到两个链表均遍历完
  * **x**设置为**p1**所指结点上的值，若**p1**为nullptr，**x**设置为0
  * **y**设置为**p2**所指结点上的值，若**p2**为nullptr，**y**设置为0
  * **sum=x+y+carry**
  * **carry=sum/10**
  * 将（**sum%10**）添加到结果链表尾端
  * 若**p1**不为nullptr，则**p1**指向下一个结点
  * 若**p2**不为nullptr，则**p2**指向下一个结点
- ⑤若**carry==1**，在结果链表尾再添加一个值为1的结点
- ⑥丢弃结果链表中的第一个无用结点，返回**first->next**

```cpp
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x),next(NULL) {}
};

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
```
==**复杂度分析**==

假设 $m$ 和 $n$ 分别表示 $l1$ 和 $l2$ 的长度
- 时间复杂度：$O(max(m, n))$，上面的算法最多重复 $max(m, n)$ 次。
- 空间复杂度：$O(max(m, n))$， 结果列表的长度最多为  $max(m, n)+1$ 。




