#define P114_Flatten_binary_tree_to_linked_list_cpp
#ifdef P114_Flatten_binary_tree_to_linked_list_cpp

//链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right) : val(x),left(left),right(right) {}
};

//#define P114_Solution_1		//前序遍历（迭代）后展开
#ifdef P114_Solution_1

class Solution {
public:
	void flatten(TreeNode* root) {
		if(!root){
			return;
		}
		vector<TreeNode*> nodeV;
		stack<TreeNode*> nodeS;
		nodeS.push(root);
		while(!nodeS.empty()){
			TreeNode* nodeTemp=nodeS.top();
			nodeS.pop();
			nodeV.push_back(nodeTemp);
			if(nodeTemp->right){
				nodeS.push(nodeTemp->right);
			}
			if(nodeTemp->left){
				nodeS.push(nodeTemp->left);
			}
		}
		for(int i=1;i<nodeV.size();++i){
			TreeNode* pre=nodeV[i-1];
			TreeNode* cur=nodeV[i];
			pre->right=cur;
			pre->left=nullptr;
		}
	}
};

#endif // P114_Solution_1



//#define P114_Solution_2		//后序遍历RLV（递归）同时展开
#ifdef P114_Solution_2

class Solution {
public:
	TreeNode* pre=nullptr;

	void flatten(TreeNode* root) {
		if(!root){
			return;
		}
		flatten(root->right);
		flatten(root->left);
		root->right=pre;
		root->left=nullptr;
		pre=root;
	}
};

#endif // P114_Solution_2



//#define P114_Solution_3		//后序遍历RLV（迭代）同时展开
#ifdef P114_Solution_3

class Solution {
public:
	void flatten(TreeNode* root) {
		if(!root){
			return;
		}
		stack<TreeNode*> nodeS;
		nodeS.push(root);
		TreeNode* cur=root->right;
		TreeNode* pre=nullptr;
		while(!nodeS.empty()){
			if(cur){
				nodeS.push(cur);
				cur=cur->right;
			}
			else{
				cur=nodeS.top();
				if(!cur->left||cur->left==pre){
					cur->right=pre;
					cur->left=nullptr;
					nodeS.pop();
					pre=cur;
					cur=nullptr;
				}
				else{
					cur=cur->left;
				}
			}
		}
	}
};

#endif // P114_Solution_3



#define P114_Solution_4		//寻找前驱节点
#ifdef P114_Solution_4

class Solution {
public:
	void flatten(TreeNode* root){
		TreeNode* cur=root;
		while(cur){
			if(cur->left){
				TreeNode* leftSubPre=cur->left;
				while(leftSubPre->right){
					leftSubPre=leftSubPre->right;
				}
				leftSubPre->right=cur->right;
				cur->right=cur->left;
				cur->left=nullptr;
			}
			cur=cur->right;
		}
	}
};

#endif // P114_Solution_4



//#define P114_Test
#ifdef P114_Test

int main(){
	Solution Lee;
}

#endif // P114_Test



#endif // P114_Flatten_binary_tree_to_linked_list_cpp