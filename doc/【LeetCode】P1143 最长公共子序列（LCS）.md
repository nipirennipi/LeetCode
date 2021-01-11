# P1143 最长公共子序列（LCS）
@[toc]

题目链接：[1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence).

## 题目描述
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。
**示例：**
>输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。

>输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。

>输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。

**提示：**
- 1 <= text1.length <= 1000
- 1 <= text2.length <= 1000
- 输入的字符串只含有小写英文字符。

## 题解
### 方法一：动态规划
>链接：[动态规划](https://blog.csdn.net/nipirennipi136/article/details/108169419).

==**思路**==
- ①将原问题分解为子问题

子问题：“求 $text1$ 前 $i$ 个字符形成的子串与 $text2$ 前 $j$ 个字符形成的子串的最长公共子序列的长度”。记 $text1$、$text2$ 的长度分别为 $m$、$n$，那么共有 $m\cdot n$ 个子问题，原问题的解即为最后一个子问题的解，即求 $text1$ 前 $m$ 个字符形成的子串与 $text2$ 前 $n$ 个字符形成的子串的最长公共子序列的长度。

- ②确定状态

每个子问题中，与两个变量有关：$i$、$j$，所以变量 $i$、$j$ 共同组成状态，定义 $dp[i][j]$ 为 $text1$ 前 $i$ 个字符形成的子串与 $text2$ 前 $j$ 个字符形成的子串的最长公共子序列的长度，$dp[i][j]$ 即为状态 $i$、$j$ 对应的值。


- ③确定一些边界状态（初始状态）的值

显然有，$text1$ 前 $0$ 个字符形成的子串与 $text2$ 前 $j$ 个字符形成的子串的最长公共子序列的长度为 $0$，同样的，$text1$ 前 $i$ 个字符形成的子串与 $text2$ 前 $0$ 个字符形成的子串的最长公共子序列的长度为 $0$，所以
$$dp[i][j]=0\ \ \ \ \ \ \ (i=0，0\leqslant j\leqslant n) \ or \ (j=0，0\leqslant i\leqslant m)$$

- ④确定状态转移方程

$$dp[i][j] = \begin{cases}
   dp[i-1][j-1]+1 &text1[i-1]=text2[j-1] \\
   \max(dp[i-1][j]，dp[i][j-1]) &text1[i-1]\neq text2[j-1]
\end{cases}$$

显然，当 $text1[i-1]=text2[j-1]$ 时，最长公共子序列长度加 $1$。

但是，为什么当 $text1[i-1]\neq text2[j-1]$ 时，会得出 $dp[i][j]=\max(dp[i-1][j]，dp[i][j-1])$ 呢?
>证明：当 $text1[i-1]\neq text2[j-1]$ 时，$dp[i][j]=\max(dp[i-1][j]，dp[i][j-1])$ 。
>\
>证明：
>>由于 $dp[i][j]$ 所对应的 $text1$、$text2$ 的子串涵盖了 $dp[i][j-1]$、$dp[i-1][j]$ 所对应的 $text1$、$text2$ 的子串，所以 $dp[i][j]$ 所对应的公共子序列的长度不小于 $dp[i][j-1]$、$dp[i-1][j]$ 所对应的公共子序列的长度，==所以  $dp[i][j]$ 不小于  $dp[i][j-1]$、$dp[i-1][j]$== 。
>
>>假设：$dp[i][j]$ 比 $dp[i][j-1]$、$dp[i-1][j]$ 都大
>> - ① 比较 $dp[i][j]$ 所对应的 $text1$、$text2$ 的子串与 $dp[i][j-1]$ 所对应的 $text1$、$text2$ 的子串，前者只多了一个字符 $text2[j-1]$，由假设可知 $dp[i][j]$ 比 $dp[i][j-1]$ 大，所以字符 $text2[j-1]$ 一定位于 $dp[i][j]$ 所对应的公共子序列中。
>> - ② 比较 $dp[i][j]$ 所对应的 $text1$、$text2$ 的子串与 $dp[i-1][j]$ 所对应的 $text1$、$text2$ 的子串，前者只多了一个字符 $text1[i-1]$，由假设可知 $dp[i][j]$ 比 $dp[i-1][j]$ 大，所以字符 $text1[i-1]$ 一定位于 $dp[i][j]$ 所对应的公共子序列中。
>>
>>\
>>由①、②可知，$text1[i-1]$、$text2[j-1]$ 都位于 $dp[i][j]$ 所对应的公共子序列中，而 $text1[i-1]$ 是 $text1$ 前 $i$ 个字符形成的子串中的最后一个字符，$text[j-1]$ 是 $text2$ 前 $j$ 个字符形成的子串中的最后一个字符，所以$text1[i-1]=text2[j-1]$，与 $text1[i-1]\neq text2[j-1]$ 矛盾，假设不成立，所以 ==$dp[i][j]$ 不比 $dp[i][j-1]$、$dp[i-1][j]$ 都大== 。
>
>>由于 $dp[i][j-1]$、$dp[i-1][j]$ 所对应的 $text1$、$text2$ 的子串都只是比 $dp[i-1][j-1]$ 所对应的 $text1$、$text2$ 的子串多一个字符，所以 $dp[i][j-1]$、$dp[i-1][j]$ 所对应的最长公共子序列长度都只能等于 $dp[i-1][j-1]$ 所对应的最长公共子序列长度，或者加 $1$，则 $dp[i][j-1]$、$dp[i-1][j]$ 都只能等于 $dp[i-1][j-1]$ 或者 $dp[i-1][j-1]+1$，==所以 $dp[i][j-1]$ 与 $dp[i-1][j]$ 要么相等，要么相差 $1$== 。
>
>有了上面的==3个结论==，可知 $dp[i][j]$ 至少等于 $dp[i][j-1]$、$dp[i-1][j]$ 两者之一（$dp[i][j-1]=dp[i-1][j]$ 时，三者相等），又由于 $dp[i][j]$ 所对应的 $text1$、$text2$ 的子串涵盖了 $dp[i][j-1]$、$dp[i-1][j]$ 所对应的 $text1$、$text2$ 的子串，所以 $dp[i][j]$ 所对应的最长公共子序列的长度应该为 $dp[i][j-1]$、$dp[i-1][j]$ 所对应的最长公共子序列的长度中的较大值，则有：$$dp[i][j]=\max(dp[i-1][j]，dp[i][j-1])$$
>得证。

当 $text1 = “abcde", text2 = “ace”$，我们按照状态转移方程，写出 $dp$ 中的值：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200825221712793.png#pic_center)
==**算法**==

- 参考代码1
```cpp
class Solution {
public:
	int longestCommonSubsequence(string text1,string text2) {
		int len1=text1.size();
		int len2=text2.size();
		int** dp=new int*[len1+1];
		for(int i=0;i<len1+1;++i){
			dp[i]=new int[len2+1];
		}
		for(int i=0;i<len1+1;++i){
			dp[i][0]=0;
		}
		for(int i=0;i<len2+1;++i){
			dp[0][i]=0;
		}
		for(int i=1;i<len1+1;++i){
			for(int j=1;j<len2+1;++j){
				if(text1[i-1]==text2[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		return dp[len1][len2];
	}
};
```
上面的程序还可以使用**滚动数组**来对空间进行优化，我们可以知道计算出 $dp[i][j]$ 只需要知道 $dp[i][j-1]$、$dp[i-1][j]$、$dp[i-1][j-1]$，所以我们可以考虑使用一个长度为 $n+1$ 的一维数组 $newdp$ 来代替二维数组 $dp$，用 $newdp[j]$ 来存储 $dp[i][j]$，在计算 $dp[i][j]$ 时（即为 $newdp[j]$ 赋值时），$dp[i][j-1]$ 存储于 $newdp[j-1]$ 中，$dp[i-1][j]$ 存储于 $newdp[j]$ 中，而 $dp[i-1][j-1]$（原来也存储于 $newdp[j-1]$ 中）已经被更新为 $dp[i][j-1]$，所以我们需要一个变量 $temp$ 来记录 $dp[i-1][j-1]$。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200825231216350.png#pic_center)
其实还可以继续优化空间，将 $newdp$ 设置为一个长度为 $\min(m,n)+1$ 的一维数组。

- 参考代码2

```cpp
class Solution {
public:
	int longestCommonSubsequence(string text1,string text2) {
		int len1=text1.size();
		int len2=text2.size();
		if(len2>len1){
			return longestCommonSubsequence(text2,text1);
		}
		int* dp=new int[len2+1];
		int temp;
		for(int i=0;i<len2+1;++i){
			dp[i]=0;
		}
		for(int i=1;i<len1+1;++i){
			temp=dp[0];
			for(int j=1;j<len2+1;++j){
				if(text1[i-1]==text2[j-1]){
					int tp=temp;
					temp=dp[j];
					dp[j]=tp+1;
				}
				else{
					temp=dp[j];
					dp[j]=max(dp[j],dp[j-1]);
				}	
			}
		}
		return dp[len2];
	}
};
```




==**复杂度分析**==

假设字符串 $text1$ 的长度为 $m$，字符串 $text2$ 的长度为 $n$
- 时间复杂度：$O(m\cdot n)$，因为动态规划中状态的数目为 $m\cdot n$，在计算每个状态时所需的时间为一个与 $m$、$n$ 均无关的常量，由动态规划解题的时间复杂度计算公式：
$$时间复杂度=状态的数目⋅计算每个状态所需时间$$所以得到时间复杂度 $O(m\cdot n)$ 。
- 空间复杂度：
	* **参考代码1**的空间复杂度为 $O(m\cdot n)$，需要一个 $(m+1)\cdot (n+1)$ 的二维数组 $dp$ 来存储各个状态的值。
	* **参考代码2**的空间复杂度为 $O(\min(m,n))$，使用**滚动数组**，需要一个长度为 $\min(m,n)+1$ 的一维滚动数组。




