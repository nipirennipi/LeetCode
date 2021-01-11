# P5 最长回文子串
@[toc]

题目链接：[5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/).

## 题目描述
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

**示例：**
>输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

>输入: "cbbd"
输出: "bb"

## 题解
### 方法一：暴力算法
==**思路**==

枚举出所有长度大于 1 的子串，逐个检验它们是否为回文子串，并找到最长回文子串。

==**算法**==

```cpp
class Solution {
public:
	string longestPalindrome(string s) {
		int size=s.size();
		int target=0;				//标记最长回文子串的起始位置
		int maxLen=1;				//记录最长回文子串长度，单个字符为一个回文子串
		for(int begin=0;begin<=size-2;++begin){
			for(int end=begin+1;end<size;++end){
				if(end-begin+1>maxLen&&isPalindrome(s,begin,end)){
					maxLen=end-begin+1;
					target=begin;
				}
			}
		}
		return s.substr(target,maxLen);
	}

	bool isPalindrome(string s,int begin,int end){
		while(end>begin){
			if(s[begin]!=s[end]){
				return false;
			}
			++begin;
			--end;
		}
		return true;
	}
};
```

==**复杂度分析**==

假设 $n$ 表示字符串 $s$ 的长度 
- 时间复杂度：$O(n^3)$，因为枚举出所有长度大于 1 的子串的时间复杂度为 $O(n^2)$，而还要对每个子串进行检验是否为回文串，检验一个子串的时间复杂度为 $O(n)$。
- 空间复杂度：$O(1)$


### 方法二：中心扩散法
==**思路**==

回文子串的长度可以为奇数也可以为偶数，长度为奇数的回文子串的中心位置为 1 个字符，长度为偶数的回文子串的中心位置为 2 个字符。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200816143909556.png#pic_center)
中心扩散法，顾名思义，在字符串 $s$ 中，我们可以先以 1 个字符为回文串的中心位置，往两边扩散来寻找长度为奇数的回文子串；以连续的 2 个字符为回文串的中心位置，往两边扩散来寻找长度为偶数的回文子串。

==**算法**==

伪代码：
- **for(int i=0;i<=size-2;++i)**
	* 以 **i** 为中心位置，往两边扩散来寻找长度为奇数的回文子串
	* 以 **i** 、**i+1** 为中心位置，往两边扩散来寻找长度为偶数的回文子串
	* 记录最长回文子串长度 **maxLen**，以及最长回文子串的中心位置 **target**（若最长回文子串的长度为偶数，**target** 为靠左的中心字符的位置）
- 返回以第 **target-(maxLen-1)/2** （关于这个式子，下面有推导过程）个字符为开头，长度为 **maxLen** 的子串
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200816151407885.png#pic_center)
由于是整型运算，向下取整，长度为偶数的回文子串的起始位置的计算中，**maxLen** 为偶数，所以  **target-(maxLen-2)/2 = target-(maxLen-1)/2**，这样就与长度为奇数的回文子串的起始位置的计算合并为一种情况。

```cpp
class Solution {
public:
	string longestPalindrome(string s) {
		int size=s.size();
		int target=0;				//标记最长回文子串的中心位置
		int maxLen=1;				//记录最长回文子串长度，单个字符为一个回文子串
		for(int i=0;i<=size-2;++i){
			int oddLen=centerSpread(s,i,i);		//寻找长度为奇数的回文子串，中心字符为i
			int evenLen=centerSpread(s,i,i+1);	//寻找长度为偶数的回文子串，中心字符为i、i+1
			if(max(oddLen,evenLen)>maxLen){
				maxLen=max(oddLen,evenLen);
				target=i;
			}
		}
		return s.substr(target-(maxLen-1)/2,maxLen);
	}

	int centerSpread(string s,int begin,int end){
		int size=s.size();
		while(0<=begin&&end<size){
			if(s[begin]!=s[end]){
				break;
			}
			--begin;
			++end;
		}
		return end-begin-1;
	}
};
```

==**复杂度分析**==

假设 $n$ 表示字符串 $s$ 的长度 
- 时间复杂度：$O(n^2)$，只需要枚举出中心位置，共 $2(n-1)$ 次，在每次扩散中，时间复杂度为 $O(n)$。
- 空间复杂度：$O(1)$

### 方法三：动态规划
==**思路**==

==**算法**==

==**复杂度分析**==

