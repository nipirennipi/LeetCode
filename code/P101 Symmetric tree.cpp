#define P101_Symmetric_tree_cpp
#ifdef P101_Symmetric_tree_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/symmetric-tree/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

//#define P1_Solution_1		//µü´ú
#ifdef P1_Solution_1

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if(!root){
			return true;
		}
		return helper(root->left,root->right);
	}

	bool helper(TreeNode* leftSub,TreeNode* rightSub){
		if(!leftSub&&!rightSub){
			return true;
		}
		if(!leftSub||!rightSub){
			return false;
		}
		return (leftSub->val==rightSub->val&&helper(leftSub->left,rightSub->right)&&helper(leftSub->right,rightSub->left));
	}
};

#endif // P1_Solution_1



#define P1_Solution_2		//µü´ú
#ifdef P1_Solution_2

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if(!root){
			return true;
		}
		queue<TreeNode*> nodeQ;
		nodeQ.push(root->left);
		nodeQ.push(root->right);
		while(!nodeQ.empty()){
			TreeNode* temp1=nodeQ.front();
			nodeQ.pop();
			TreeNode* temp2=nodeQ.front();
			nodeQ.pop();
			if(!temp1&&!temp2){
				continue;	
			}
			if(!temp1||!temp2||(temp1->val!=temp2->val)){
				return false;
			}
			nodeQ.push(temp1->left);
			nodeQ.push(temp2->right);
			nodeQ.push(temp1->right);
			nodeQ.push(temp2->left);
		}
		return true;
	}
};

#endif // P1_Solution_2



//#define P1_Test
#ifdef P1_Test

int main(){
	Solution Lee;
}

#endif // P1_Test



#endif // P101_Symmetric_tree_cpp