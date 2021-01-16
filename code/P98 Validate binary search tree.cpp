#define P98_Validate_binary_search_tree_cpp
#ifdef P98_Validate_binary_search_tree_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/validate-binary-search-tree/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

#define P98_Solution_1		//DFS
#ifdef P98_Solution_1

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if(!root){
			return true;
		}
		TreeNode* pre=nullptr;
		TreeNode* post=nullptr;
		if(root->left){
			pre=root->left;
			while(pre->right){
				pre=pre->right;
			}
		}
		if(root->right){
			post=root->right;
			while(post->left){
				post=post->left;
			}
		}
		if((pre&&pre->val>=root->val)||(post&&root->val>=post->val)){
			return false;
		}
		bool leftSubTree=isValidBST(root->left);
		bool rightSubTree=isValidBST(root->right);
		return leftSubTree&&rightSubTree;
	}
};

#endif // P98_Solution_1



//#define P98_Solution_2		//MorrisÖÐÐò±éÀú£¨stack overflow ?£©
#ifdef P98_Solution_2

class Solution {
public:
	bool isValidBST(TreeNode* root) {
		TreeNode* cur=root;
		TreeNode* pre=nullptr;
		int curVal;
		int preVal=INT_MIN;
		while(cur){
			if(!cur->left){
				curVal=cur->val;
				if(preVal>=curVal){
					return false;
				}
				preVal=curVal;
				cur=cur->right;
			}
			else{
				pre=cur->left;
				while(pre->right&&pre->right!=cur){
					pre=pre->right;
				}
				if(pre->right==cur){
					pre->right=nullptr;
					curVal=cur->val;
					if(preVal>=curVal){
						return false;
					}
					preVal=curVal;
					cur=cur->right;
				}
				else{
					pre->right=cur;
					cur=cur->left;
				}
			}
		}
		return true;
	}	
};

#endif // P98_Solution_2



//#define P98_Test
#ifdef P98_Test

int main(){
	Solution Lee;
	/*TreeNode* node1=new TreeNode(10);
	TreeNode* node2=new TreeNode(5);
	TreeNode* node3=new TreeNode(15);
	TreeNode* node4=new TreeNode(6);
	TreeNode* node5=new TreeNode(20);
	node1->left=node2;
	node1->right=node3;
	node3->left=node4;
	node3->right=node5;*/

	TreeNode* node1=new TreeNode(2);
	TreeNode* node2=new TreeNode(1);
	TreeNode* node3=new TreeNode(3);
	node1->left=node2;
	node1->right=node3;

	/*TreeNode* node1=new TreeNode(5);
	TreeNode* node2=new TreeNode(1);
	TreeNode* node3=new TreeNode(4);
	TreeNode* node4=new TreeNode(3);
	TreeNode* node5=new TreeNode(6);
	node1->left=node2;
	node1->right=node3;
	node3->left=node4;
	node3->right=node5;*/


	cout<<Lee.isValidBST(node1);
}

#endif // P98_Test



#endif // P98_Validate_binary_search_tree_cpp