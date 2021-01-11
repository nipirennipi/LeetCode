#define P94_Binary_tree_inorder_traversal_cpp
#ifdef P94_Binary_tree_inorder_traversal_cpp

//链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};

//#define P94_Solution_1		//递归
#ifdef P94_Solution_1

class Solution {
public:
	void traversal(TreeNode* root,vector<int>& path){
		if(!root){
			return;
		}
		traversal(root->left,path);
		path.push_back(root->val);
		traversal(root->right,path);
	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> path;
		traversal(root,path);
		return path;
	}
};

#endif // P94_Solution_1



//#define P94_Solution_2		//迭代
#ifdef P94_Solution_2

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> nodeS;
		vector<int> nodeV;
		TreeNode* cur=root;
		while(!nodeS.empty()||cur){
			if(cur){
				nodeS.push(cur);
				cur=cur->left;
			}
			else{
				cur=nodeS.top();
				nodeV.push_back(cur->val);
				nodeS.pop();
				cur=cur->right;
			}
		}
		return nodeV;	
	}
};

#endif // P94_Solution_2



#define P94_Solution_3		//Moirrs中序遍历
#ifdef P94_Solution_3

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> path;
		TreeNode* cur=root;
		TreeNode* pre;
		while(cur){
			if(!cur->left){
				path.push_back(cur->val);
				cur=cur->right;
			}
			else{
				pre=cur->left;
				while(pre->right&&pre->right!=cur){
					pre=pre->right;
				}
				if(pre->right==cur){
					pre->right=nullptr;
					path.push_back(cur->val);
					cur=cur->right;
				}
				else{
					pre->right=cur;
					cur=cur->left;
				}
			}
		}
		return path;
	}
};

#endif // P94_Solution_3



//#define P94_Test
#ifdef P94_Test

int main(){
	Solution Lee;
}

#endif // P94_Test



#endif // P94_Binary_tree_inorder_traversal_cpp