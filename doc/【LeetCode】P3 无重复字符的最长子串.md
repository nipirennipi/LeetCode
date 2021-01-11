# P3 无重复字符的最长子串
@[toc]

题目链接：[3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/).

## 题目描述
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

**示例：**
>输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3

>输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

>输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

## 题解
### 方法一：暴力算法
==**思路**==

找到从每一个字符为开头的无重复字符的最长子串，那么其中最长的子串就是要寻找的无重复字符的最长子串。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200812231722370.png#pic_center)
还需要解决的一个问题是，如何判断字串中仅含有唯一字符，在寻找以一字符为开头的无重复字符的最长子串时，每次对子串的延长，都要判断即将要加入子串的字符是否已经被现有子串所包含，有两种做法：
- 遍历：遍历子串中有无与之重复的字符
- hashset：将子串先存入hashset中，再检查有无与之重复的字符

==**算法**==

这里采用hashset来判断字串中是否仅含有唯一字符
```cpp
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans=0;
		unordered_set<char> hashset;
		for(int begin=0;begin<s.size();++begin){
			hashset.clear();
			int end=begin;	//导致时间复杂度为O(n^2)
			while(!hashset.count(s[end])&&end<s.size()){
				hashset.insert(s[end]);
				++end;
			}
			ans=(end-begin>ans)?(end-begin):ans;
			if(end==s.size()){
				break;
			}
		}
		return ans;
	}
};
```

==**复杂度分析**==

假设 $n$ 表示字符串 $s$ 的长度
- 时间复杂度：$O(n^2)$

- 空间复杂度：$O(|\Sigma|)$，其中 $\Sigma$ 表示字符集（即字符串中可以出现的字符），$|\Sigma|$ 表示字符集的大小。在本题中没有明确说明字符集，因此可以默认为所有 ASCII 码在 $[0, 128)$ 内的字符，即 $|\Sigma|=128$。我们需要用到哈希集合来存储出现过的字符，而字符最多有 $|\Sigma|$ 个，因此空间复杂度为 $O(|\Sigma|)$。

### 方法二：滑动窗口（双指针）
==**思路**==

由暴力算法，我们可以得到启发，在寻找以每个字符为开头的无重复字符的最长子串时，子串的起始位置呈递增，同时子串的终止位置也是呈递增的，这就像一个大小会变化、但是一直在字符串上向前滑动的窗口。当我们选择第 $begin$ 个字符作为开头来寻找子串，得到无重复字符的最长子串的结束为第 $end-1$ 个字符，那么在以第 $begin+1$ 个字符作为开头时，$[begin+1,end)$ 范围内的字符是不重复的，此时，我们可以继续尝试扩大子串的结束位置，检验第 $end$ 个字符是否与$[begin+1,end)$ 范围内的字符重复……一直向后检验，直到出现重复字符时，就得到以第 $begin+1$ 个字符作为开头的无重复字符的最长子串，其长度为 $end-begin$。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200813141701308.png#pic_center)
我们先使用双指针来判断有无重复字符

==**算法**==

伪代码：
- ①创建双指针**begin=0**，**end=0**
- ②开始滑动窗口，直到**end**到达字符串结尾（这里的结尾是指**超尾**位置）
	* 遍历检查[**begin,end-1**)范围内有无字符与第**end**个字符重复
		+ 若有字符与之重复（记为第**i**个字符，**i**∈[**begin,end-1**) ），那么**begin=i+1**，结束遍历检查
	* ++**end**
	* 记录无重复字符子串的最长长度**ans**
- ③返回**ans**
```cpp
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int begin=0;
		int end=0;
		int ans=0;

		while(end<s.size()){
			for(int i=begin;i<end;++i){
				if(s[i]==s[end]){
					begin=i+1;
					break;
				}
			}
			++end;
			ans=(end-begin)>ans?(end-begin):ans;
		}
		return ans;
	}
};
```

==**复杂度分析**==

假设 $n$ 表示字符串 $s$ 的长度
- 时间复杂度：$O(n^2)$
- 空间复杂度：$O(1)$，因为只设置了两指针

### 方法三：滑动窗口（hashset）
==**思路**==

还是使用滑动窗口的思想，只是使用hashset来判断有无重复字符以减少时间复杂度。

==**算法**==

伪代码：
- ①创建双指针**begin=0**，**end=0**，**hashset**
- ②开始滑动窗口，直到**end**到达字符串结尾（这里的结尾是指**超尾**位置）
	* 若**begin!=0**，从**hashset**中擦除第(**begin-1**)个字符
	* **hashset**中无第**end**个字符 且 **end**未到达超尾位置
		+ true：将第**end**个字符加入**hashset**中，++**end**
		+ false：结束循环
	* 记录无重复字符子串的最长长度**ans**
- ③返回**ans**
```cpp
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_set<char> hashset;
		int begin=0;
		int end=0;
		int ans=0;

		for(begin=0;begin<s.size();++begin){
			if(begin!=0){
				hashset.erase(s[begin-1]);
			}
			while(!hashset.count(s[end])&&end<s.size()){
				hashset.insert(s[end]);
				++end;
			}
			ans=(end-begin>ans)?(end-begin):ans;
			if(end==s.size()){
				break;
			}
		}
		return ans;
	}
};
```
==**复杂度分析**==

假设 $n$ 表示字符串 $s$ 的长度
- 时间复杂度：$O(n)$
- 空间复杂度：$O(|\Sigma|)$，其中 $\Sigma$ 表示字符集（即字符串中可以出现的字符），$|\Sigma|$ 表示字符集的大小。
