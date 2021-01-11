#define P501_Find_mode_in_binary_search_tree_cpp
#ifdef P501_Find_mode_in_binary_search_tree_cpp

//链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

#define P501_Solution_1		//Morris Traversal（时间复杂度：O(n)，空间复杂度：O(1)）
#ifdef P501_Solution_1

class Solution {
public:
	void update(int curValue,int &count,int &value,int &maxCount,vector<int>& modes){
		if(curValue==value){
			++count;
		}
		else{
			count=1;
			value=curValue;
		}
		if(count==maxCount){
			modes.push_back(curValue);
		}
		if(count>maxCount){
			maxCount=count;
			modes.clear();
			modes.push_back(curValue);
		}
	}

	vector<int> findMode(TreeNode* root) {
		TreeNode* cur=root;
		TreeNode* pre=nullptr;
		int count=0;
		int value=0;
		int maxCount=0;
		vector<int> modes;
		while(cur){
			if(!cur->left){
				update(cur->val,count,value,maxCount,modes);
				cur=cur->right;
			}
			else{
				pre=cur->left;
				while(pre->right&&pre->right!=cur){
					pre=pre->right;
				}
				if(pre->right==cur){
					pre->right=nullptr;
					update(cur->val,count,value,maxCount,modes);
					cur=cur->right;
				}
				else{
					pre->right=cur;
					cur=cur->left;
				}
			}
		}
		return modes;
	}
};

#endif // P501_Solution_1



#define P501_Solution_2
#ifdef P501_Solution_2



#endif // P501_Solution_2



//#define P501_Test
#ifdef P501_Test

int main(){
	Solution Lee;
	TreeNode* node1=new TreeNode(1);
	TreeNode* node2=new TreeNode(2);
	TreeNode* node3=new TreeNode(2);
	node1->right=node2;
	node2->left=node3;
	vector<int> modes=Lee.findMode(node1);
	for(auto it:modes){
		printf("%d\t",it);
	}
}

#endif // P501_Test



#endif // P501_Find_mode_in_binary_search_tree_cpp