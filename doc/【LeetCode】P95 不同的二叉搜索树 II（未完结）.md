# P95 不同的二叉搜索树 II
@[toc]

题目链接：[95. 不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/).

## 题目描述
给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树 。

**示例：**
>输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：
   ![1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3](https://img-blog.csdnimg.cn/20200922122240270.png#pic_center)

**二叉树结点的定义：**

```cpp
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};
```

## 题解
### 方法一：递归
==**思路**==

**二叉搜索树**或者是一颗空树，或者是具有下列性质的二叉树：
- 每个结点都有一个作为搜索依据的关键码（key），所有结点的关键码互不相同。
- 左子树（如果存在）上的所有结点的关键码都小于根结点的关键码。
- 右子树（如果存在）上的所有结点的关键码都大于根结点的关键码。
- 左子树和右子树也是二叉搜索树。

当我们在构建关键码序列为 $[begin,end]$ （为了方便，这里将 $[begin,end]$ 表示为序列 $begin、begin+1...end$，下同）的所有二叉搜索树时，先对根结点的值 $rootVal$ 进行枚举$（rootVal=begin、begin+1 ... end）$，由二叉搜索树的定义知，若根结点的值为 $rootVal$，那么其左子树为关键码序列为 $[begin,rootVal-1]$，其右子树的关键码序列为 $[rootVal+1,end]$，这样就将 **构建关键码序列为 $[begin,end]$ 的所有二叉搜索树问题** 转换为 **构建关键码序列为 $[begin,rootVal-1]$ 的所有二叉搜索树和构建关键码序列为 $[rootVal+1,end]$ 的所有二叉搜索树** 两个子问题，然后可以同样对上面的两个子问题再次重复上面的操作（即枚举根结点，使用左子树的关键码序列构建所有二叉搜索树，使用右子树的关键码序列构建所有二叉搜索树），这样我们就自然会想到使用递归来求解。

枚举根结点的值为 $rootVal$，当构建出关键码序列为 $[begin,rootVal-1]$ 的所有二叉搜索树（记为 $leftSubTree$ 集合）和关键码序列为 $[rootVal+1,end]$ 的所有二叉搜索树（记为 $rightSubTree$ 集合），然后在 $leftSubTree$ 与 $rightSubTree$ 集合中各取一个元素，这两个元素分别作为根结点的左子树与右子树。

**递归的终止条件**
当 $begin>end$ 时递归终止，返回一个集合，这个集合中的元素为一个空指针。

**递归的入口**
求解由 1 ... n 为节点所组成的所有二叉搜索树问题，就是构建关键码序列为 $[1,n]$ 的所有二叉搜索树。

==**算法**==

```cpp
class Solution {
public:
	vector<TreeNode*> generateTrees(int begin,int end){
		if(begin>end){
			return vector<TreeNode*>(1,nullptr);
		}
		vector<TreeNode*> allTrees;
		for(int rootVal=begin;rootVal<=end;++rootVal){
			vector<TreeNode*> leftSubTree=generateTrees(begin,rootVal-1);
			vector<TreeNode*> rightSubTree=generateTrees(rootVal+1,end);
			for(int left=0;left<leftSubTree.size();++left){
				for(int right=0;right<rightSubTree.size();++right){
					TreeNode* rootNode=new TreeNode(rootVal);
					rootNode->left=leftSubTree[left];
					rootNode->right=rightSubTree[right];
					allTrees.push_back(rootNode);
				}
			}
		}
		return allTrees;
	}

	vector<TreeNode*> generateTrees(int n) {
		if(!n){
			return vector<TreeNode*>();
		}
		return generateTrees(1,n);
	}
};
```

==**复杂度分析**==


