#define P230_Kth_smallest_element_in_a_bst_cpp
#ifdef P230_Kth_smallest_element_in_a_bst_cpp

//链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right) {}
};

//#define P230_Solution_1		//中序遍历（迭代）
#ifdef P230_Solution_1

class Solution {
public:
	int kthSmallest(TreeNode* root,int k) {
		stack<TreeNode*> nodeS;
		TreeNode* cur=root;
		while(cur||!nodeS.empty()){
			if(cur){
				nodeS.push(cur);
				cur=cur->left;
			}
			else{
				cur=nodeS.top();
				nodeS.pop();
				if(!--k){
					return cur->val;
				}
				cur=cur->right;
			}
		}
		return -1;
	}
};

#endif // P230_Solution_1



#define P230_Solution_2
#ifdef P230_Solution_2



#endif // P230_Solution_2



//#define P230_Test
#ifdef P230_Test

int main(){
	Solution Lee;
}

#endif // P230_Test



#endif // P230_Kth_smallest_element_in_a_bst_cpp