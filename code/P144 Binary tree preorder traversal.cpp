#define P144_Binary_tree_preorder_traversal_cpp
#ifdef P144_Binary_tree_preorder_traversal_cpp

//链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};

//#define P144_Solution_1		//递归
#ifdef P144_Solution_1

class Solution {
public:
	void traversal(TreeNode* root,vector<int>& path){
		if(!root){
			return;
		}
		path.push_back(root->val);
		traversal(root->left,path);
		traversal(root->right,path);
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> path;
		traversal(root,path);
		return path;
	}
};

#endif // P144_Solution_1



//#define P144_Solution_2		//迭代
#ifdef P144_Solution_2

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		if(!root){
			return vector<int>();
		}
		stack<TreeNode*> nodeS;
		vector<int> nodeV;
		nodeS.push(root);
		while(!nodeS.empty()){
			TreeNode* nodeTemp=nodeS.top();
			nodeS.pop();
			nodeV.push_back(nodeTemp->val);
			if(nodeTemp->right){
				nodeS.push(nodeTemp->right);
			}
			if(nodeTemp->left){
				nodeS.push(nodeTemp->left);
			}
		}
		return nodeV;
	}
};

#endif // P144_Solution_2



#define P144_Solution_3		//Moirrs前序遍历
#ifdef P144_Solution_3

class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> path;
		TreeNode* cur=root;
		TreeNode* pre=nullptr;
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
					cur=cur->right;
				}
				else{
					pre->right=cur;
					path.push_back(cur->val);
					cur=cur->left;
				}
			}
		}
		return path;
	}
};

#endif // P144_Solution_3



//#define P144_Test
#ifdef P144_Test

int main(){
	Solution Lee;

	TreeNode* node1=new TreeNode(5);
	TreeNode* node2=new TreeNode(1);
	TreeNode* node3=new TreeNode(4);
	TreeNode* node4=new TreeNode(3);
	TreeNode* node5=new TreeNode(6);
	node1->left=node2;
	node1->right=node3;
	node3->left=node4;
	node3->right=node5;

	vector<int> path=Lee.preorderTraversal(node1);
	for(auto it:path){
		cout<<it<<"\t";
	}
}

#endif // P144_Test



#endif // P144_Binary_tree_preorder_traversal_cpp