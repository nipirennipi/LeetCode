#define P102_Binary_tree_level_order_traversal_cpp
#ifdef P102_Binary_tree_level_order_traversal_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/binary-tree-level-order-traversal/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

#define P102_Solution_1
#ifdef P102_Solution_1

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if(!root){
			return ans;
		}
		queue<TreeNode*> nodeQ;
		nodeQ.push(root);
		while(!nodeQ.empty()){
			vector<int> level;
			TreeNode* tempNode;
			int curLevelSize=nodeQ.size();
			for(int i=0;i<curLevelSize;++i){
				tempNode=nodeQ.front();
				nodeQ.pop();
				level.push_back(tempNode->val);
				if(tempNode->left){
					nodeQ.push(tempNode->left);
				}
				if(tempNode->right){
					nodeQ.push(tempNode->right);
				}
			}
			ans.push_back(level);
		}
		return ans;
	}	
};

#endif // P102_Solution_1



#define P102_Solution_2
#ifdef P102_Solution_2



#endif // P102_Solution_2



//#define P102_Test
#ifdef P102_Test

int main(){
	Solution Lee;
}

#endif // P102_Test



#endif // P102_Binary_tree_level_order_traversal_cpp