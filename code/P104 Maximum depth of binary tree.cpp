#define P104_Maximum_depth_of_binary_tree_cpp
#ifdef P104_Maximum_depth_of_binary_tree_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

#define P104_Solution_1		//BFS
#ifdef P104_Solution_1

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if(!root){
			return 0;
		}
		int rightSubTree=maxDepth(root->right);
		int leftSubTree=maxDepth(root->left);
		return max(rightSubTree,leftSubTree)+1;
	}
};

#endif // P104_Solution_1



//#define P104_Solution_2		//DFS
#ifdef P104_Solution_2

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if(!root){
			return 0;
		}
		queue<pair<TreeNode*,int>> nodeQ;
		nodeQ.push(pair<TreeNode*,int>(root,1));
		int maxDepth=0;
		while(!nodeQ.empty()){
			pair<TreeNode*,int> temp=nodeQ.front();
			nodeQ.pop();
			TreeNode* nodeTemp=temp.first;
			int depthTemp=temp.second;
			if(nodeTemp->left){
				nodeQ.push(pair<TreeNode*,int>(nodeTemp->left,depthTemp+1));
			}
			if(nodeTemp->right){
				nodeQ.push(pair<TreeNode*,int>(nodeTemp->right,depthTemp+1));
			}
			maxDepth=max(maxDepth,depthTemp);
		}
		return maxDepth;
	}
};

#endif // P104_Solution_2



//#define P104_Test
#ifdef P104_Test

int main(){
	Solution Lee;
}

#endif // P104_Test



#endif // P104_Maximum_depth_of_binary_tree_cpp