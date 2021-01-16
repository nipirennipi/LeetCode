#define P226_Invert_binary_tree_cpp
#ifdef P226_Invert_binary_tree_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/invert-binary-tree/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
	
};

#define P226_Solution_1
#ifdef P226_Solution_1

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if(!root){
			return root;
		}
		TreeNode* temp=root->left;
		root->left=root->right;
		root->right=temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

#endif // P226_Solution_1



#define P226_Solution_2
#ifdef P226_Solution_2



#endif // P226_Solution_2



//#define P226_Test
#ifdef P226_Test

int main(){
	Solution Lee;
}

#endif // P226_Test



#endif // P226_Invert_binary_tree_cpp