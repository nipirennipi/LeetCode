#define P107_Binary_tree_level_order_traversal_ii_cpp
#ifdef P107_Binary_tree_level_order_traversal_ii_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

#define P107_Solution_1
#ifdef P107_Solution_1

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
		ans=vector<vector<int>>(ans.rbegin(),ans.rend());
		return ans;
	}
};

#endif // P107_Solution_1



#define P107_Solution_2
#ifdef P107_Solution_2



#endif // P107_Solution_2



//#define P107_Test
#ifdef P107_Test

int main(){
	Solution Lee;
}

#endif // P107_Test



#endif // P107_Binary_tree_level_order_traversal_ii_cpp