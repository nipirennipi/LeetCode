#define P124_Binary_tree_maximum_path_sum_cpp
#ifdef P124_Binary_tree_maximum_path_sum_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

#define P124_Solution_1		//DFS
#ifdef P124_Solution_1

class Solution {
public:
	int maxSum=INT_MIN;

	int DFS(TreeNode* root){
		if(!root){
			return 0;
		}
		int leftPathMax=max(DFS(root->left),0);
		int rightPathMax=max(DFS(root->right),0);
		int rootMax=leftPathMax+rightPathMax+root->val;
		maxSum=max(maxSum,rootMax);
		return max(leftPathMax,rightPathMax)+root->val;
	}

	int maxPathSum(TreeNode* root) {
		DFS(root);
		return maxSum;
	}
};

#endif // P124_Solution_1



#define P124_Solution_2
#ifdef P124_Solution_2



#endif // P124_Solution_2



//#define P124_Test
#ifdef P124_Test

int main(){
	Solution Lee;
}

#endif // P124_Test



#endif // P124_Binary_tree_maximum_path_sum_cpp