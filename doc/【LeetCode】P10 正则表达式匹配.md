# P10 正则表达式匹配
@[toc]

题目链接：[10. 正则表达式匹配](https://leetcode-cn.com/problems/regular-expression-matching/).

## 题目描述
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 ' . ' 和 ' * ' 的正则表达式匹配。

>' . ' 匹配任意单个字符
' * ' 匹配零个或多个前面的那一个元素

所谓匹配，是要涵盖整个字符串 s 的，而不是部分字符串。

**说明**
- s 可能为空，且只包含从 a-z 的小写字母。
- p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

**示例：**
>输入:
s = " aa "
p = " a "
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

>输入:
s = " aa "
p = " a* "
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 ' a '。因此，字符串 " aa " 可被视为 ' a ' 重复了一次。

>输入:
s = " ab "
p = " .\* "
输出: true
解释: " .\* " 表示可匹配零个或多个（ ' * ' ）任意字符（ ' . ' ）。

>输入:
s = " aab "
p = " c\*a\*b "
输出: true
解释: 因为 ' * ' 表示零个或多个，这里 ' c ' 为 0 个, ' a ' 被重复一次。因此可以匹配字符串 " aab "。

>输入:
s = " mississippi "
p = " mis\*is\*p\*. "
输出: false

## 题解
### 方法一：动态规划
>链接：[动态规划](https://blog.csdn.net/nipirennipi136/article/details/108169419).

==**思路**==

- ①将原问题分解为子问题

子问题：“字符串 $s$ 的前 $i$ 个字符形成的子串与字符规律 $p$ 的前 $j$ 个字符形成的子串是否能够匹配”。记 $s$、$p$ 的长度分别为 $m$、$n$，那么共有 $m\cdot n$ 个子问题，原问题的解即为最后一个子问题的解，即 $s$ 前 $m$ 个字符形成的子串与 $p$ 前 $n$ 个字符形成的子串是否能够匹配。

- ②确定状态

每个子问题中，与两个变量有关：$i$、$j$，所以变量 $i$、$j$ 共同组成状态，定义 $dp[i][j]$ 表示 $s$ 前 $i$ 个字符形成的子串与 $p$ 前 $j$ 个字符形成的子串是否能够匹配，$dp[i][j]$ 即为状态 $i$、$j$ 对应的值。

- ③确定一些边界状态（初始状态）的值

显然有，$s$ 前 $0$ 个字符形成的子串与 $p$ 前 $0$ 个字符形成的子串都是空串，所以它们是匹配的，$s$ 前 $i$ 个字符形成的非空串与 $p$ 前 $0$ 个字符形成的空串是一定不匹配的，**而需要注意的是 $s$ 前 $0$ 个字符形成的空串与 $p$ 前 $j$ 个字符形成的非空串是可能会匹配的，如$“”$与$“a*”$**，所以这些状态的值不能直接作为边界状态的值给出。
$$dp[i][j] = \begin{cases}
   true &i=0，j=0 \\
   false &j=0，0< i\leqslant m
\end{cases}$$

- ④确定状态转移方程
	
	* 若 $p[j-1]$ 为字母或者 $‘.’$ ，那么在 $s$ 中必须要匹配一个字符$$dp[i][j] = \begin{cases}
   dp[i-1][j-1] & match(s[i-1],p[j-1]) \\
   false & otherwise
\end{cases}$$
$match(x,y)$：判断字符 $x$ 与 字符 $y$ 是否匹配，只有字符 $x$ 与字符 $y$ 相同或者字符 $y$ 为 $‘.’$ 才会匹配。若 $s[i-1]$ 与 $p[j-1]$ 可以匹配，那么 $s$ 的前 $i$ 个字符与 $p$ 的前 $j$ 个字符的匹配结果取决于 $s$ 的前 $i-1$ 个字符与 $p$ 的前 $j-1$ 个字符的匹配结果，否则， $s$ 的前 $i$ 个字符与 $p$ 的前 $j$ 个字符必定不匹配。

	* 若 $p[j-1]$ 为 $‘*’$，$p[j-2]$ 与 $p[j-1]$ 组成 $x*$ 组合（$x$ 为字母或者 $‘.’$）
		- 若 $p[j-2]$ 与 $s[i-1]$ 不能匹配，那么就意味着组合 $x*$ 匹配 $s$ 中的 $0$ 个字符，该组合将被直接丢弃。
		- 若 $p[j-2]$ 与 $s[i-1]$ 能匹配，那么可能会有两种情况
			- 匹配字符 $s[i-1]$，组合 $x*$ 继续保留
			- 匹配 $s$ 中的 $0$ 个字符，该组合直接被丢弃

$$dp[i][j] = \begin{cases}
   dp[i-1][j]\ or\ dp[i][j-2] &match(s[i-1],p[j-2]) \\
   dp[i][j-2] &otherwise
\end{cases}$$

由以上的讨论，我们可以写出最终的状态转移方程：
$$dp[i][j] = \begin{cases}
   = \begin{cases}
   dp[i-1][j]\ or\ dp[i][j-2] &match(s[i-1],p[j-2]) \\
   dp[i][j-2] &otherwise
\end{cases} &p[j-1]=* \\
   = \begin{cases}
   dp[i-1][j-1] & match(s[i-1],p[j-1]) \\
   false & otherwise
\end{cases} &otherwise
\end{cases}$$

当 $S= “acbbb", P= “acbb*”$，我们按照状态转移方程，写出 $dp$ 中的值：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200828130728874.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25pcGlyZW5uaXBpMTM2,size_16,color_FFFFFF,t_70#pic_center)

==**算法**==

```cpp
class Solution {
public:
	bool isMatch(string s,string p) {
		int m=s.size();
		int n=p.size();
		bool** dp=new bool* [m+1];
		for(int i=0;i<m+1;++i){
			dp[i]=new bool[n+1];
			for(int j=0;j<n+1;++j){
				dp[i][j]=false;
			}
		}
		dp[0][0]=true;
		for(int i=0;i<m+1;++i){
			for(int j=1;j<n+1;++j){
				if(p[j-1]=='*'){
					dp[i][j]=dp[i][j-2];
					if(i!=0&&(p[j-2]=='.'||s[i-1]==p[j-2])){
						dp[i][j]|=dp[i-1][j];
					}
				}
				else{
					if(i!=0&&(p[j-1]=='.'||s[i-1]==p[j-1])){
						dp[i][j]=dp[i-1][j-1];
					}
				}
			}
		}
		return dp[m][n];
	}
};
```

==**复杂度分析**==

假设字符串 $s$ 的长度为 $m$，字符串 $p$ 的长度为 $n$
- 时间复杂度：$O(m\cdot n)$，因为动态规划中状态的数目为 $m\cdot n$，在计算每个状态时所需的时间为一个与 $m$、$n$ 均无关的常量，由动态规划解题的时间复杂度计算公式：
$$时间复杂度=状态的数目⋅计算每个状态所需时间$$所以得到时间复杂度 $O(m\cdot n)$ 。
- 空间复杂度：$O(m\cdot n)$，需要一个 $(m+1)\cdot (n+1)$ 的二维数组 $dp$ 来存储各个状态的值。

