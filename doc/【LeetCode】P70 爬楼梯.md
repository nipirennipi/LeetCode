# P70 爬楼梯
@[toc]

题目链接：[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/).

## 题目描述
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

**注意：** 给定 n 是一个正整数。


**示例：**
>输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
>1 阶 + 1 阶
>2 阶

>输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1 阶 + 1 阶 + 1 阶
1 阶 + 2 阶
2 阶 + 1 阶

## 题解
### 方法一：递归
==**思路**==

首先，我们知道若有 $1$ 阶楼梯，我们有 $1$ 种方法到达楼顶，若有 $2$ 阶楼梯，我们有 $2$ 种方法到达楼顶，有 $n（n>2）$ 阶楼梯时，我们只用考虑爬楼梯的最后一步，若到达 $n$ 阶楼梯的最后一步是爬 $1$ 阶，那么最后一步的起点就是从第 $n-1$ 阶楼梯；若到达 $n$ 阶楼梯的最后一步是爬 $2$ 阶，那么最后一步的起点就是从第 $n-2$ 阶楼梯，所以我们可以知道到达 $n$ 阶楼梯方法数是到达 $n-1$ 阶楼梯的方法数与到达 $n-2$ 阶楼梯的方法数之和。

记 $F(n)$ 为到达 $n$ 阶楼梯的方法数
$$F(n) = \begin{cases}
   1 &n=1 \\
   2 &n=2 \\
   F(n-1)+F(n-2) &n>2,n\in \mathbb{Z}
\end{cases}$$

==**算法**==

```cpp
class Solution {
public:
	int climbStairs(int n) {
		if(n==1){
			return 1;
		}
		if(n==2){
			return 2;
		}
		return climbStairs(n-1)+climbStairs(n-2);
	}
};
```

==**复杂度分析**==

假设楼梯的阶数为 $n$

当 $n=6$ 时，画出递归树
![在这里插入图片描述](https://img-blog.csdnimg.cn/2020090111204935.png?#pic_center)
可以看出，树的深度为 $n-1$，树近似于完全二叉树，结点可以使用 $2^n$ 来近似计算，那么就会进行 $2^n$ 次计算，所以：

- 时间复杂度：$O(2^n)$，这显然会 $Time\ Limit\ Exceeded$
- 空间复杂度：$O(n)$

### 方法二：记忆型递归
==**思路**==

在方法一中，我们从递归树中可以看出，有大量重复的计算，如当 $n=5$ 与 $n=4$ 时，会重复计算 $n=3$ 的情况，我们可以开一片空间出来，将已经计算过的值存储起来，调用时直接返回。

==**算法**==

```cpp
class Solution {
public:
	int climbStairs(int n) {
		vector<int> memory(n+1,0);
		return climbStairsMemory(memory,n);
	}

	int climbStairsMemory(vector<int> memory,int n){
		if(memory[n]>0){
			return memory[n];
		}
		if(n==1){
			memory[n]=1;
		}
		else if(n==2){
			memory[n]=2;
		}
		else{
			memory[n]=climbStairsMemory(memory,n-1)+climbStairsMemory(memory,n-2);
		}
		return memory[n];
	}
};
```

==**复杂度分析**==

假设楼梯的阶数为 $n$

- 时间复杂度：$O(n)$，有了记忆数组，只用进行 $n$ 次计算。
- 空间复杂度：$O(n)$


### 方法三：动态规划
>链接：[动态规划](https://blog.csdn.net/nipirennipi136/article/details/108169419).

==**思路**==
- ①将原问题分解为子问题

子问题：“求到达 $i$ 阶楼梯的方法数”。定义 $dp[i]$ 为到达 $i$ 阶楼梯的方法数，共有 $n$ 个子问题，将这 $n$ 个子问题都解决了，那最大解就是原问题的解了，这就满足了问题具有**最优子结构性质**。

- ②确定状态

子问题只与一个变量有关：楼梯的阶数 $i$，所以每个子问题中楼梯的阶数 $i$，就是状态，而状态 $i$ 对应的值就是到达 $i$ 阶楼梯的方法数，所以我们只用一个一维数组就可以存储各个状态的值。共有 $n$ 个状态，它们构成状态空间。

- ③确定一些边界状态（初始状态）的值

若有 $1$ 阶楼梯，我们有 $1$ 种方法到达楼顶，$dp[1]=1$，若有 $2$ 阶楼梯，我们有 $2$ 种方法到达楼顶，$dp[2]=2$

- ④确定状态转移方程

状态转移方程：
$$dp[i] = \begin{cases}
   1 &i=1 \\
   2 &i=2 \\
   dp[i-1]+dp[i-2] &i>2,i\in \mathbb{Z}
\end{cases}$$


- 原问题的解

到达 $n$ 阶楼梯的方法数 $=dp[n]$

==**算法**==

- 参考代码1

```cpp
class Solution {
public:
	int climbStairs(int n) {
		if(n==1){
			return 1;
		}
		if(n==2){
			return 2;
		}
		vector<int> dp(n+1);
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=n;++i){
			dp[i]=dp[i-1]+dp[i-2];
		}
		return dp[n];
	}
};
```
由于计算 $dp[i]$ 只用了 $dp[i-1]$ 与 $dp[i-2]$，所以我们考虑使用变量来储存

- 参考代码2

```cpp
class Solution {
public:
	int climbStairs(int n) {
		if(n==1){
			return 1;
		}
		if(n==2){
			return 2;
		}
		int left=1;
		int right=2;
		int temp;
		for(int i=3;i<=n;++i){
			temp=left+right;
			left=right;
			right=temp;
		}
		return right;
	}
};
```

==**复杂度分析**==

假设楼梯的阶数为 $n$

- 时间复杂度：$O(n)$
- 空间复杂度：
	* **参考代码1**的空间复杂度为 $O(n)$
	* **参考代码2**的空间复杂度为 $O(1)$

### 方法四：通项公式的矩阵形式 + 矩阵快速幂
>链接：[矩阵快速幂](https://blog.csdn.net/nipirennipi136/article/details/108338001).

==**思路**==

记 $F(n)$ 为到达 $n$ 阶楼梯的方法数
$$F(n) = \begin{cases}
   1 &n=1 \\
   2 &n=2 \\
   F(n-1)+F(n-2) &n>2,n\in \mathbb{Z}
\end{cases}$$
将上面的递推式写成矩阵形式：
$$\begin{bmatrix}
   F(n+1) \\
   F(n)
\end{bmatrix}=
\begin{bmatrix}
   1 & 1 \\
   1 & 0
\end{bmatrix} 
\begin{bmatrix}
   F(n) \\
   F(n-1)
\end{bmatrix}
$$
由 $F(n)=F(n-1)+F(n-2)$
$$\begin{bmatrix}
   F(n+1) \\
   F(n)
\end{bmatrix}=
\begin{bmatrix}
   1 & 1 \\
   1 & 0
\end{bmatrix} 
\begin{bmatrix}
   F(n) \\
   F(n-1)
\end{bmatrix}=
\begin{bmatrix}
   1 & 1 \\
   1 & 0
\end{bmatrix}^2
\begin{bmatrix}
   F(n-1) \\
   F(n-2)
\end{bmatrix}=
...=
\begin{bmatrix}
   1 & 1 \\
   1 & 0
\end{bmatrix}^n
\begin{bmatrix}
   F(1) \\
   F(0)
\end{bmatrix}
$$
由递推的规律，应该有 $F(2)=F(1)+F(0)$，所以 令 $F(0)=1$，所以
$$\begin{bmatrix}
   F(n+1) \\
   F(n)
\end{bmatrix}=
\begin{bmatrix}
   1 & 1 \\
   1 & 0
\end{bmatrix}^n
\begin{bmatrix}
   F(1) \\
   F(0)
\end{bmatrix}=
\begin{bmatrix}
   1 & 1 \\
   1 & 0
\end{bmatrix}^n
\begin{bmatrix}
   1 \\
   1
\end{bmatrix}
$$
记 $M=\begin{bmatrix}
   1 & 1 \\
   1 & 0
\end{bmatrix}$

所以我们下面需要做的就是计算出 $M^n$，显然我们可以运用**矩阵快速幂**来加速 $M^n$ 的求解。

- 对于 $F(n)$ 的求解

记 $M^n=
\begin{bmatrix}
   1 & 1 \\
   1 & 0
\end{bmatrix}^n=
\begin{bmatrix}
   m_{00} & m_{01} \\
   m_{10} & m_{11}
\end{bmatrix}$

则有：
$$\begin{bmatrix}
   F(n+1) \\
   F(n)
\end{bmatrix}=
\begin{bmatrix}
   m_{00} & m_{01} \\
   m_{10} & m_{11}
\end{bmatrix}
\begin{bmatrix}
   1 \\
   1
\end{bmatrix}
$$$$F(n)=m_{10}+m_{11}$$

==**算法**==

```cpp
class Solution {
public:
	vector<vector<int>> matrixMultiple(vector<vector<int>> left,vector<vector<int>> right){
		int leftRows=left.size();
		int count=left[0].size();
		int rightColumns=right[0].size();
		vector<vector<int>> result(leftRows,vector<int>(rightColumns));
		for(int i=0;i<leftRows;++i){
			for(int j=0;j<rightColumns;++j){
				for(int k=0;k<count;++k){
					result[i][j]+=(left[i][k]*right[k][j]);
				}
			}
		}
		return result;
	};

	vector<vector<int>> matrixQuickPow(vector<vector<int>> m,int n){		//求方阵m的n次幂
		int rows=m.size();
		vector<vector<int>> result(rows,vector<int>(rows));
		for(int i=0;i<rows;++i){
			result[i][i]=1;
		}
		while(n>1){		//防止m*m导致整数溢出，提前结束循环
			if(n&1){
				result=matrixMultiple(result,m);
			}
			n>>=1;
			m=matrixMultiple(m,m);
		}
		if(n&1){
			result=matrixMultiple(result,m);
		}
		return result;
	}

	int climbStairs(int n) {
		vector<vector<int>> m{{1,1},{1,0}};
		vector<vector<int>> result=matrixQuickPow(m,n);
		return result[1][0]+result[1][1];
	}
};
```

==**复杂度分析**==

假设楼梯的阶数为 $n$

- 时间复杂度：$O(\log n)$
- 空间复杂度：$O(1)$


### 方法五：直接返回结果
==**思路**==

由于整型上限的限制，$n$ 最大为 $45$，所以我们可以将这 $45$ 种情况枚举出来，直接返回结果。

==**算法**==

```cpp
class Solution {
public:
	int climbStairs(int n) {
		int a[47]={0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,
					987,1597,2584,4181,6765,10946,17711,28657,
					46368,75025,121393,196418,317811,514229,
					832040,1346269,2178309,3524578,5702887,
					9227465,14930352,24157817,39088169,63245986,
					102334155,165580141,267914296,433494437,
					701408733,1134903170,1836311903};
		return a[n];
};
```

==**复杂度分析**==

假设楼梯的阶数为 $n$

- 时间复杂度：$O(1)$
- 空间复杂度：$O(1)$



