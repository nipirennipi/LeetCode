#define P129_Sum_root_to_leaf_numbers_cpp
#ifdef P129_Sum_root_to_leaf_numbers_cpp

//链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

//#define P129_Solution_1		//DFS
#ifdef P129_Solution_1

class Solution {
public:
	vector<int> p;
	vector<vector<int>> paths;

	void recordPath(TreeNode* root){
		if(!root){
			return;
		}
		p.push_back(root->val);
		if(!root->left&&!root->right){
			paths.push_back(p);
		}
		recordPath(root->left);
		recordPath(root->right);
		p.pop_back();
	}

	int sumNumbers(TreeNode* root) {
		recordPath(root);
		int allSum=0;
		for(int i=0;i<paths.size();++i){
			int sum=0;
			for(int j=0;j<paths[i].size();++j){
				sum*=10;
				sum+=paths[i][j];
			}
			allSum+=sum;
		}
		return allSum;
	}
};

#endif // P129_Solution_1



//#define P129_Solution_2		//DFS + 空间优化		
#ifdef P129_Solution_2

class Solution {
public:
	int subFun(TreeNode* root,int num){
		if(!root){
			return 0;
		}
		int temp=num*10+root->val;
		if(!root->left&&!root->right){
			return temp;
		}
		return subFun(root->left,temp)+subFun(root->right,temp);
	}

	int sumNumbers(TreeNode* root) {
		return subFun(root,0);
	}
};

#endif // P129_Solution_2



#define P129_Solution_3			//BFS
#ifdef P129_Solution_3

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		queue<pair<TreeNode*,int>> nodeQ;
		if(root){
			nodeQ.push(pair<TreeNode*,int>(root,root->val));
		}
		int allSum=0;
		while(!nodeQ.empty()){
			pair<TreeNode*,int> temp=nodeQ.front();
			nodeQ.pop();
			TreeNode* tempNode=temp.first;
			int tempVal=temp.second;
			if(!tempNode->left&&!tempNode->right){
				allSum+=tempVal;
			}
			else{
				if(tempNode->left){
					nodeQ.push(pair<TreeNode*,int>(tempNode->left,tempVal*10+tempNode->left->val));
				}
				if(tempNode->right){
					nodeQ.push(pair<TreeNode*,int>(tempNode->right,tempVal*10+tempNode->right->val));
				}
			}
		}
		return allSum;
	}
};

#endif // P129_Solution_3



//#define P129_Test
#ifdef P129_Test

int main(){
	Solution Lee;
}

#endif // P129_Test



#endif // P129_Sum_root_to_leaf_numbers_cpp