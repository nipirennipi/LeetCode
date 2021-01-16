#define P563_Binary_tree_tilt_cpp
#ifdef P563_Binary_tree_tilt_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/binary-tree-tilt/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right) {}
};

#define P563_Solution_1			//µÝ¹é
#ifdef P563_Solution_1

class Solution {
private:
	int tilt;

	int helper(TreeNode* root){
		if(!root){
			return 0;
		}
		int left=helper(root->left);
		int right=helper(root->right);
		tilt+=abs(left-right);
		return left+right+root->val;
	}

public:
	int findTilt(TreeNode* root) {
		helper(root);
		return tilt;
	}
};

#endif // P563_Solution_1



#define P563_Solution_2
#ifdef P563_Solution_2



#endif // P563_Solution_2



//#define P563_Test
#ifdef P563_Test

int main(){
	Solution Lee;
}

#endif // P563_Test



#endif // P563_Binary_tree_tilt_cpp