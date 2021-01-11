#define P112_Path_sum_cpp
#ifdef P112_Path_sum_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/path-sum/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//#define P112_Solution_1		//DFS
#ifdef P112_Solution_1

class Solution {
public:
	bool hasPathSum(TreeNode* root,int sum) {
		if(!root){
			return false;
		}
		if(!root->left&&!root->right){
			return root->val==sum;
		}
		return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
	}
};

#endif // P112_Solution_1



#define P112_Solution_2		//BFS
#ifdef P112_Solution_2

class Solution {
public:
	bool hasPathSum(TreeNode* root,int sum) {
		if(!root){
			return false;
		}
		queue<TreeNode*> nodeQ;
		queue<int> valQ;
		nodeQ.push(root);
		valQ.push(root->val);
		while(!nodeQ.empty()){
			TreeNode* node=nodeQ.front();
			int val=valQ.front();
			nodeQ.pop();
			valQ.pop();
			if(!node->left&&!node->right){
				if(val==sum){
					return true;
				}
			}
			else{
				if(node->left){
					nodeQ.push(node->left);
					valQ.push(val+node->left->val);
				}
				if(node->right){
					nodeQ.push(node->right);
					valQ.push(val+node->right->val);
				}
			}
		}
		return false;
	}
};

#endif // P112_Solution_2



//#define P112_Test
#ifdef P112_Test

int main(){
	Solution Lee;
}

#endif // P112_Test



#endif // P112_Path_sum_cpp