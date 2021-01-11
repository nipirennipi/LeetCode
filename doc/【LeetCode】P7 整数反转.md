# P7 整数反转
@[toc]

题目链接：[7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/).

## 题目描述
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

**示例：**
>输入: 123
输出: 321

>输入: -123
输出: -321

>输入: 120
输出: 21

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 $[−2^{31},  2^{31}−1]$。请根据这个假设，如果反转后整数溢出那么就返回 0。

## 题解
==**思路**==

将 32 位的有符号整数 **x** 反转为 **ans**

关键代码：

```cpp
ans=ans*10+x%10;
x/=10;
```

但是 **ans=ans*10+x%10** 很危险，这样写可能会导致溢出。
所以我们要在计算之前对进行检查是否会导致溢出
- 检查方式1（对应参考代码1）
若 **ans*10/10!=ans** 则说明 **ans*10** 会导致溢出

- 检查方式2（对应参考代码2）
使用整型上、下限 **INT_MAX**、**INT_MIN** 来辅助检验
	* 若 **ans*10+x%10 > INT_MAX** 发生正溢，此时 **x** 的取值只能为 1 或 2，所以 **ans > INT_MAX/10**
	* 若 **ans*10+x%10 < INT_MIN** 发生负溢，此时 **x** 的取值只能为 -1 或 -2，所以 **ans < INT_MIN/10**

==**算法**==

- 参考代码1

```cpp
class Solution {
public:
	int reverse(int x) {
		int ans=0;
		int temp;
		while(x){
			temp=(unsigned)(ans)*10;
			if(temp/10!=ans){
				return 0;
			}
			ans=temp+x%10;
			x/=10;
		}
		return ans;
	}
};
```

- 参考代码2

```cpp
class Solution {
public:
	int reverse(int x) {
		int ans=0;
		while(x){
			if(ans>INT_MAX/10||ans<INT_MIN/10){
				return 0;
			}
			ans=ans*10+x%10;
			x/=10;
		}
		return ans;
	}
};
```

==**复杂度分析**==

假设要反转的 32 位的有符号整数为 $x$
- 时间复杂度：$O(\log(x))$，因为整数 $x$ 的数位约为 $\log_{10}x$。
- 空间复杂度：$O(1)$
