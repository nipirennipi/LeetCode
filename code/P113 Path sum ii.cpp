#define P113_Path_sum_ii_cpp
#ifdef P113_Path_sum_ii_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/path-sum-ii/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

#define P113_Solution_1		//DFS
#ifdef P113_Solution_1

class Solution {
public:
	vector<int> p;
	vector<vector<int>> paths;

	void subFun(TreeNode* root,int sum){	
		if(!root){
			return;
		}
		p.push_back(root->val);
		if(!root->left&&!root->right){
			if(sum==root->val){
				paths.push_back(p);
			}
		}
		subFun(root->left,sum-root->val);
		subFun(root->right,sum-root->val);
		p.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root,int sum) {
		subFun(root,sum);
		return paths;		
	}
};

#endif // P113_Solution_1



//#define P113_Solution_2		
#ifdef P113_Solution_2



#endif // P113_Solution_2



//#define P113_Test
#ifdef P113_Test

int main(){
	Solution Lee;
}

#endif // P113_Test



#endif // P113_Path_sum_ii_cpp