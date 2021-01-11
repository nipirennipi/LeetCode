# P222 完全二叉树的节点个数
@[toc]

题目链接：[[222. 完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/)](https://leetcode-cn.com/problems/count-complete-tree-nodes/).

## 题目描述
给出一个**完全二叉树**，求出该树的节点个数。

**说明：**

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 $h$ 层，则该层包含 $1\text{~}2^h$ 个节点。

**示例：**

```
输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6
```

## 题解
### 方法一：DFS
==**思路**==

对于任意二叉树，都可以通过BFS或者DFS计算节点个数

==**算法**==

```cpp
class Solution {
public:
	int countNodes(TreeNode* root) {
		if(!root){
			return 0;
		}
		return countNodes(root->left)+countNodes(root->right)+1;
	}
};
```

==**复杂度分析**==

假设二叉树的节点个数为 $n$

- 时间复杂度：$O(n)$
- 空间复杂度：$O(n)$

### 方法二：BFS
==**思路**==

对于任意二叉树，都可以通过BFS或者DFS计算节点个数

==**算法**==

```cpp
class Solution {
public:
	int countNodes(TreeNode* root) {
		if(!root){
			return 0;
		}
		int count=0;
		queue<TreeNode*> nodeQ;
		nodeQ.push(root);
		while(!nodeQ.empty()){
			TreeNode* node=nodeQ.front();
			if(node->left){
				nodeQ.push(node->left);
			}
			if(node->right){
				nodeQ.push(node->right);
			}
			nodeQ.pop();
			++count;
		}
		return count;
	}
};
```

==**复杂度分析**==

假设二叉树的节点个数为 $n$

- 时间复杂度：$O(n)$
- 空间复杂度：$O(n)$


### 方法三：二分查找 + 位运算
==**思路**==

BFS与DFS适用于任意二叉树中节点计数问题，既然要求完全二叉树的节点个数，那么我们应该结合完全二叉树的性质来求解。

完全二叉树的最下面一层的最左节点是叶节点，通过访问这个叶节点可以得出完全二叉树的深度，具体做法是，从根节点开始，迭代访问左子女节点，直到左子女节点为空，即得完全二叉树深度。

在完全二叉树中，若根节点位于第 $0$ 层，最大层数为 $h$（深度$-1$），那么
- 最少节点数为 $2^{h}$
- 最多节点数为 $2^{h+1}-1$

所以，若确定了完全二叉树的最大层数，那么节点个数在范围 $[2^{h},2^{h+1}-1]$ 内，可以使用二分查找来确定节点个数，由当前节点个数范围取中值 $k$，判断节点 $k$（从根节点为 $1$ 按层序为节点编号，节点 $k$ 即编号为 $k$）是否存在，然后继续二分查找。

现在需要做的就是如何判断节点 $k$ 是否存在，先说具体做法，位于第 $i$ 层的节点，其编号转为二进制后位数为 $i+1$ 位，最高位为 $1$，其它从高到低二进制位决定了从根节点到该节点的路径，即若为 $1$ 则访问右子女节点，若为 $0$ 则访问左子女节点。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210110211937986.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L25pcGlyZW5uaXBpMTM2,size_16,color_FFFFFF,t_70#pic_center)

$12$ 对应二进制 $1100$，最高位 $1$ 忽略，$0100\&1100$ 得第 $2$ 位为 $1$，从根节点出发，访问右子女结点；$0010\&1100$ 得第 $3$ 位为 $0$，再访问左子女结点；$0001\&1100$ 得第 $4$ 位为 $0$，再访问左子女结点，这样就得到了从根节点编号为 $12$ 的节点的路径。

既然我们知道了从根节点到节点 $k$ 的路径，那么就可以判断节点 $k$ 是否存在了。

==**算法**==

```cpp
class Solution {
public:
	int getDepth(TreeNode* root){		//求完全二叉树最大层数(根结点位于第0层)	
		if(!root){
			return 0;
		}
		int depth=0;
		while(root->left){
			++depth;
			root=root->left;
		}
		return depth;
	}

	bool exist(TreeNode* root,int depth,int k){		//位运算判断结点k是否存在
		int mode=1<<(depth-1);
		while(root&&mode){
			if(k&mode){
				root=root->right;
			}
			else{
				root=root->left;
			}
			mode>>=1;
		}
		return root;
	}

	int countNodes(TreeNode* root) {
		if(!root){
			return 0;
		}
		int depth=getDepth(root);
		int left=1<<depth;
		int right=(1<<(depth+1))-1;
		while(left<right){
			int mid=left+((right-left+1)>>1);		//注意运算符优先级
			if(exist(root,depth,mid)){
				left=mid;
			}
			else{
				right=mid-1;
			}
		}
		return left;
	}
};
```

在二分时取 $mid=left+((right-left+1)>>1)$
- 不直接用 $(left+right+1)>>1$ 是因为防止越界
- $+1$ 是为了防止当 $right=left+1$ 时出现死循环

==**复杂度分析**==

假设完全二叉树的节点个数为 $n$，最大层数为 $h=\lfloor\log{n}\rfloor$

- 时间复杂度：$O(\log^2{n})$，第 $h$ 层的最大结点数为 $2^h$，所以进行二分查找的次数为 $\log{2^h}=h$，在每次查找中，需要从根节点开始，访问 $h$ 个节点，所以时间复杂度为 $O(h^2)$，又由于$h=\lfloor\log{n}\rfloor$，所以时间复杂度为 $O(\log^2{n})$
- 空间复杂度：$O(1)$





