# P9 回文数
@[toc]

题目链接：[9. 回文数](https://leetcode-cn.com/problems/palindrome-number/).

## 题目描述
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

**示例：**
>输入: 121
输出: true

>输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。

>输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。

**进阶：** 你能不将整数转为字符串来解决这个问题吗？

## 题解
### 方法一：整数转化为字符串
==**思路**==

先将整数转化字符串，然后对字符串进行判断是否为回文串

==**算法**==

```cpp
class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0){
			return false;
		}
		string str;
		do{
			str+=(x%10+48);
			x/=10;
		}while(x);
		int size=str.size();
		for(int i=0;i<=size/2-1;++i){
			if(str[i]!=str[size-1-i]){
				return false;
			}
		}
		return true;
	}
};
```

==**复杂度分析**==

假设要判断是否为回文数的 32 位的有符号整数为 $x$
- 时间复杂度：$O(\log(x))$，因为整数 $x$ 的数位约为 $\log_{10}x$。
- 空间复杂度：$O(\log(x))$，要创建一个与 $x$ 数位一样的字符串来存储该数字。


### 方法二：反转一半数字
==**思路**==

你应该想过这种方式来解决问题，将 **x** 反转，然后判断反转后的数字是否与 **x** 相等，但是这可能会导致溢出问题，而且将 **x** 整个反转是否真的有必要？

>链接: [P7 整数反转](https://blog.csdn.net/nipirennipi136/article/details/108086489).

我们可以考虑只将 **x** 的后一半数字反转，然后与 **x** 的前一半数字进行比较。比如数字 **53**==35== ，将后一半数字 ==35== 反转后得 ==53==，再与前一半数字 **53** 进行比较，可以判断 5335为回文数。

设变量 **secondHalf** 来储存 **x**，按照上面的思路我们可以列出以下公式，用来迭代计算出 **x** 的前半段与反转后的后半段：
- **secondHalf=secondHalf*10+x%10**
- **x/=10**

什么时候应该终止上述迭代，即什么时候 **secondHalf** 中已经存入了反转后的后半段数字？
- 当 **x<=secondHalf** 时，终止迭代

对于 **x** 的数位为奇数与数位为偶数的两种情况，在比较前半段与反转后的后半段要稍加区分。

![!\[在这里插入图片描述\](https://img-blog.csdnimg.cn/20200820140913568.png?#pic_center](https://img-blog.csdnimg.cn/20200820141748695.png#pic_center)
我们在开始反转一半数字之前可以对 **x** 进行一个简单的初步判断，以剔除一些可以直接断定的非回文数。
- 若 **x**，则 **x** 为非回文数
- 若 **x** 不等于 0 且 **x** 的个位上的数字为 0，则 **x** 为非回文数。因为 **x** 的最高位数字不可能为 0

==**算法**==

```cpp
class Solution {
public:
	bool isPalindrome(int x) {
		if(x<0||(x!=0&&x%10==0)){
			return false;
		}
		int secondHalf=0;
		while(x>secondHalf){
			secondHalf=secondHalf*10+x%10;
			x/=10;
		}
		return x==secondHalf||x==secondHalf/10;
	}
};

```
==**复杂度分析**==

假设要判断是否为回文数的 32 位的有符号整数为 $x$
- 时间复杂度：$O(\log(x))$，因为整数 $x$ 的数位约为 $\log_{10}x$。
- 空间复杂度：$O(1)$


