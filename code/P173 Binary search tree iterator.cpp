#define P173_Binary_search_tree_iterator_cpp
#ifdef P173_Binary_search_tree_iterator_cpp

//链接：https://leetcode-cn.com/problems/binary-search-tree-iterator/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};

//#define P173_Solution_1			//扁平化二叉搜索树，S(n)=O(n)
#ifdef P173_Solution_1

class BSTIterator {
private:
	vector<TreeNode*> inorderV;
	int curPos;
public:
	BSTIterator(TreeNode* root) {
		curPos=0;
		inorderV=inorderTraversal(root);
	}

	int next() {
		return inorderV[curPos++]->val;
	}

	bool hasNext() {
		return curPos<inorderV.size();
	}

	vector<TreeNode*> inorderTraversal(TreeNode* root){
		stack<TreeNode*> nodeS;
		vector<TreeNode*> nodeV;
		TreeNode* cur=root;
		while(cur||!nodeS.empty()){
			if(cur){
				nodeS.push(cur);
				cur=cur->left;
			}
			else{
				cur=nodeS.top();
				nodeV.push_back(cur);
				nodeS.pop();
				cur=cur->right;
			}
		}
		return nodeV;
	}
};

#endif // P173_Solution_1



#define P173_Solution_2
#ifdef P173_Solution_2



#endif // P173_Solution_2

class BSTIterator {
private:
	stack<TreeNode*> nodeS;

	void updateNodeS(TreeNode* cur) {
		while(cur){
			nodeS.push(cur);
			cur=cur->left;
		}
	}

public:
	BSTIterator(TreeNode* root) {
		updateNodeS(root);
	}

	int next() {
		TreeNode* nextNode=nodeS.top();
		nodeS.pop();
		if(nextNode->right){
			updateNodeS(nextNode->right);
		}
		return nextNode->val;
	}

	bool hasNext() {
		return !nodeS.empty();
	}
};

//#define P173_Test
#ifdef P173_Test

int main(){
	Solution Lee;
}

#endif // P173_Test



#endif // P173_Binary_search_tree_iterator_cpp