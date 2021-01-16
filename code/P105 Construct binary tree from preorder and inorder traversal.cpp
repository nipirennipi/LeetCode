#define P105_Construct_binary_tree_from_preorderand_inorder_traversal_cpp
#ifdef P105_Construct_binary_tree_from_preorderand_inorder_traversal_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

#define P105_Solution_1		//µÝ¹é
#ifdef P105_Solution_1

class Solution {
public:
	unordered_map<int,int> index;

	TreeNode* buildTree(vector<int>& preorder,vector<int>& inorder) {
		for(int i=0;i<inorder.size();++i){
			index[inorder[i]]=i;
		}
		return helper(preorder,0,preorder.size(),0,inorder.size());
	}

	TreeNode* helper(vector<int>& preorder,int preLeft,int preRight,int inLeft,int inRight){
		if(preLeft>=preRight&&preLeft>=inRight){
			return nullptr;
		}
		int inIndex=index[preorder[preLeft]];
		TreeNode* root=new TreeNode(preorder[preLeft]);
		root->left=helper(preorder,preLeft+1,inIndex-inLeft+preLeft+1,inLeft,inIndex);
		root->right=helper(preorder,inIndex-inLeft+preLeft+1,preRight,inIndex+1,inRight);
		return root;
	}
};

#endif // P105_Solution_1



#define P105_Solution_2
#ifdef P105_Solution_2



#endif // P105_Solution_2



//#define P105_Test
#ifdef P105_Test

int main(){
	Solution Lee;
	vector<int> preorder={3,9,20,15,7};
	vector<int> inorder={9,3,15,20,7};
	Lee.buildTree(preorder,inorder);
}

#endif // P105_Test



#endif // P105_Construct_binary_tree_from_preorderand_inorder_traversal_cpp