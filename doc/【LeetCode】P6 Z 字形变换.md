# P6 Z 字形变换
@[toc]

题目链接：[6. Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/).

## 题目描述
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200817230844332.png#pic_center)
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
请你实现这个将字符串进行指定行数变换的函数：
>string convert(string s, int numRows);

**示例：**
>输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"

>输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200817231056649.png#pic_center)



## 题解
### 方法一：逐行访问
==**思路**==

找出字符串按照 Z 字形排列的规律
- Z 字形排列的第 $0$ 行，第 $K$ 个字符对应字符串 $s$ 的第 $2K(numRows-1)$ 个字符 $(K=0、1、2...)$
- Z 字形排列的第 $i$ 行 $(0 < i < numRows-1)$，
	* 第 $0$ 个字符对应字符串 $s$ 的第 $i$ 个字符
	* 第 $2K-1、2K$ 个字符对应字符串 s 的第 $2K(numRows-1)-i$、$2K(numRows-1)+i$ 个字符 $(K = 1、2、3...)$
- Z 字形排列的第 $numRows-1$ 行，第 $K$ 个字符对应字符串 $s$ 的第 $K \cdot numRows+(numRows-1)$ 个字符 $(K = 0、1、2...)$

==**算法**==

- 参考代码1

```cpp
class Solution {
public:
	string convert(string s,int numRows) {
		if(numRows==1){
			return s;
		}
		int size=s.size();
		int con=2*(numRows-1);
		string ans;
		for(int i=0;i<numRows;++i){
			if(i!=numRows-1){
				ans+=s[i];
			}
			for(int j=con;j-i<size;j+=con){
				ans+=s[j-i];
				if(i!=0&&i!=numRows-1&&i+j<size){
					ans+=s[j+i];
				}
			}
		}
		return ans;
	}
};
```

- 参考代码2

```cpp
class Solution {
public:
	string convert(string s,int numRows) {
		if(numRows==1){
			return s;
		}
		int size=s.size();
		int con=2*(numRows-1);
		string ans;
		for(int i=0;i<numRows;++i){
			for(int j=0;i+j<size;j+=con){
				ans+=s[i+j];
				if(i!=0&&i!=numRows-1&&j+con-i<size){
					ans+=s[j+con-i];
				}
			}
		}
		return ans;
	}
};
```

==**复杂度分析**==

假设 $n$ 表示字符串 $s$ 的长度
- 时间复杂度：$O(n)$
- 空间复杂度：$O(1)$

### 方法二：逐行组合
==**思路**==

首先创建 numRows 个空串，一个字符串对应 Z 字形排列中的一行。从左到右遍历字符串 s，确定各字符在 Z 字形排列中所在的行数，并按照字符所在行数，将它们尾插入各行对应的字符串中，遍历完成后，Z 字形排列的各行均可得到一个由按该行字符从左到右组成的字符串，然后将这 numRows 个字符串按照对应行数从上到下的顺序拼接即得到结果。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200818000013962.png#pic_center)
==**算法**==

- 参考代码1

```cpp
class Solution {
public:
	string convert(string s,int numRows) {
		if(numRows==1){
			return s;
		}
		int size=s.size();
		vector<string> bucket(numRows);
		int temp;
		for(int i=0;i<s.size();++i){
			temp=i%(numRows-1);
			if(i/(numRows-1)%2){
				bucket[numRows-1-temp]+=s[i];
			}
			else{
				bucket[temp]+=s[i];
			}
		}
		string ans;
		for(int i=0;i<bucket.size();++i){
			ans+=bucket[i];
		}
		return ans;
	}
};
```

- 参考代码2

```cpp
class Solution {
public:
	string convert(string s,int numRows) {
		if(numRows==1){
			return s;
		}
		int size=s.size();
		int pos=0;
		bool turnTo=false;
		vector<string> bucket(numRows);

		for(int i=0;i<s.size();++i){
			bucket[pos]+=s[i];
			if(i%(numRows-1)==0){
				turnTo=!turnTo;
			}
			turnTo?++pos:--pos;
		}
		string ans;
		for(int i=0;i<bucket.size();++i){
			ans+=bucket[i];
		}
		return ans;
	}
};
```

==**复杂度分析**==

假设 $n$ 表示字符串 $s$ 的长度
- 时间复杂度：$O(n)$
- 空间复杂度：$O(n)$
