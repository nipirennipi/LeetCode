#define P95_Unique_binary_search_trees_ii_cpp
#ifdef P95_Unique_binary_search_trees_ii_cpp

//链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};

//#define P95_Solution_1		//递归
#ifdef P95_Solution_1

class Solution {
public:
	vector<TreeNode*> generateTrees(int begin,int end){
		if(begin>end){
			return vector<TreeNode*>(1,nullptr);
		}
		vector<TreeNode*> allTrees;
		for(int rootVal=begin;rootVal<=end;++rootVal){
			vector<TreeNode*> leftSubTree=generateTrees(begin,rootVal-1);
			vector<TreeNode*> rightSubTree=generateTrees(rootVal+1,end);
			for(int left=0;left<leftSubTree.size();++left){
				for(int right=0;right<rightSubTree.size();++right){
					TreeNode* rootNode=new TreeNode(rootVal);
					rootNode->left=leftSubTree[left];
					rootNode->right=rightSubTree[right];
					allTrees.push_back(rootNode);
				}
			}
		}
		return allTrees;
	}

	vector<TreeNode*> generateTrees(int n) {
		if(!n){
			return vector<TreeNode*>();
		}
		return generateTrees(1,n);
	}
};

#endif // P95_Solution_1



//#define P95_Solution_2		//动态规划
#ifdef P95_Solution_2

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if(!n){
			return vector<TreeNode*>();
		}
		vector<vector<TreeNode*>> dp(n+1);
		dp[0].push_back(nullptr);
		for(int len=1;len<=n;++len){
			for(int rootVal=1;rootVal<=len;++rootVal){
				int leftLen=rootVal-1;
				int rightLen=len-rootVal;
				for(auto leftSubTree:dp[leftLen]){
					for(auto rightSubTree:dp[rightLen]){
						TreeNode* rootNode=new TreeNode(rootVal);
						rootNode->left=leftSubTree;
						rootNode->right=clone(rightSubTree,rootVal);
						dp[len].push_back(rootNode);
					}
				}
			}
		}
		return dp[n];
	}

	TreeNode* clone(TreeNode* root,int increment){
		if(!root){
			return nullptr;
		}
		TreeNode* rootClone=new TreeNode(root->val+increment);
		rootClone->left=clone(root->left,increment);
		rootClone->right=clone(root->right,increment);
		return rootClone;
	}
};



#endif // P95_Solution_2



//#define P95_Solution_3		//动态规划
#ifdef P95_Solution_3

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if(!n){
			return vector<TreeNode*>();
		}
		vector<TreeNode*> pre;
		pre.push_back(nullptr);
		for(int len=1;len<=n;++len){
			vector<TreeNode*> cur;
			for(auto rootNode:pre){
				TreeNode* newRootNode=new TreeNode(len);
				newRootNode->left=rootNode;
				cur.push_back(newRootNode);
				TreeNode* insertPos=rootNode;
				while(insertPos){
					pair<TreeNode*,TreeNode*> treeClone=clone(rootNode,insertPos);
					TreeNode* rootNodeClone=treeClone.first;
					TreeNode* insertPosClone=treeClone.second;
					TreeNode* newNode=new TreeNode(len);
					newNode->left=insertPosClone->right;
					insertPosClone->right=newNode;
					cur.push_back(rootNodeClone);
					insertPos=insertPos->right;
				}
			}
			pre=cur;
		}
		return pre;
	}

	pair<TreeNode*,TreeNode*> clone(TreeNode* root,TreeNode* flag){
		if(!root){
			return {nullptr,nullptr};
		}
		TreeNode* rootClone=new TreeNode(root->val);
		TreeNode* flagClone=nullptr;
		if(root==flag){
			flagClone=rootClone;
		}
		pair<TreeNode*,TreeNode*> leftSubTree=clone(root->left,flag);
		pair<TreeNode*,TreeNode*> rightSubTree=clone(root->right,flag);
		rootClone->left=leftSubTree.first;
		rootClone->right=rightSubTree.first;
		if(!flagClone){
			if(leftSubTree.second){
				flagClone=leftSubTree.second;
			}
			else{
				flagClone=rightSubTree.second;
			}
		}
		return {rootClone,flagClone};
	}
};

#endif // P95_Solution_3



//#define P95_Test
#ifdef P95_Test

int main(){
	Solution Lee;
}

#endif // P95_Test



#endif // P95_Unique_binary_search_trees_ii_cpp