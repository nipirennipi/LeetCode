#define P111_Minimum_depth_of_binary_tree_cpp
#ifdef P111_Minimum_depth_of_binary_tree_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

//#define P111_Solution_1		//DFS
#ifdef P111_Solution_1

class Solution {
public:
	int minDepth(TreeNode* root) {
		if(!root){
			return 0;
		}
		int leftminDepth=minDepth(root->left);
		int rightminDepth=minDepth(root->right);
		if(leftminDepth&&rightminDepth){
			return min(rightminDepth,leftminDepth)+1;
		}
		if(leftminDepth){
			return leftminDepth+1;
		}
		return rightminDepth+1;
	}
};

#endif // P111_Solution_1



#define P111_Solution_2		//BFS
#ifdef P111_Solution_2

class Solution {
public:
	int minDepth(TreeNode* root) {
		if(!root){
			return 0;
		}
		queue<pair<TreeNode*,int>> nodeQ;
		nodeQ.push(pair<TreeNode*,int>(root,1));
		while(!nodeQ.empty()){
			pair<TreeNode*,int> temp=nodeQ.front();
			TreeNode* nodeTemp=temp.first;
			int depthTemp=temp.second;
			nodeQ.pop();
			if(!nodeTemp->left&&!nodeTemp->right){
				return depthTemp;
			}
			if(nodeTemp->left){
				nodeQ.push(pair<TreeNode*,int>(nodeTemp->left,depthTemp+1));
			}
			if(nodeTemp->right){
				nodeQ.push(pair<TreeNode*,int>(nodeTemp->right,depthTemp+1));
			}
		}
		return 0;
	}
};

#endif // P111_Solution_2



//#define P111_Test
#ifdef P111_Test

int main(){
	Solution Lee;
}

#endif // P111_Test



#endif // P111_Minimum_depth_of_binary_tree_cpp