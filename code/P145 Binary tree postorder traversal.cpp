#define P145_Binary_tree_postorder_traversal_cpp
#ifdef P145_Binary_tree_postorder_traversal_cpp

//链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x): val(x),left(nullptr),right(nullptr) {}
	TreeNode(int x,TreeNode* left,TreeNode* right): val(x),left(left),right(right) {}
};

//#define P145_Solution_1		//递归
#ifdef P145_Solution_1

class Solution {
public:
	void traversal(TreeNode* root,vector<int>& path){
		if(!root){
			return;
		}
		traversal(root->left,path);
		traversal(root->right,path);
		path.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> path;
		traversal(root,path);
		return path;
	}
};

#endif // P145_Solution_1



#define P145_Solution_2		//迭代1
#ifdef P145_Solution_2

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if(!root){
			return vector<int>();
		}
		stack<TreeNode*> nodeS;
		vector<int> nodeV;
		TreeNode* cur=root->left;
		TreeNode* pre=nullptr;
		nodeS.push(root);
		while(!nodeS.empty()){
			if(cur){
				nodeS.push(cur);
				cur=cur->left;
			}
			else{
				cur=nodeS.top();
				if(!cur->right||cur->right==pre){
					nodeV.push_back(cur->val);
					nodeS.pop();
					pre=cur;
					cur=nullptr;
				}
				else{
					cur=cur->right;
				}
			}
		}
		return nodeV;
	}
};

#endif // P145_Solution_2



//#define P145_Solution_3		//迭代2（VRL的翻转）
#ifdef P145_Solution_3

class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		if(!root){
			return vector<int>();
		}
		stack<TreeNode*> nodeS;
		deque<int> nodeQ;
		nodeS.push(root);
		while(!nodeS.empty()){
			TreeNode* nodeTemp=nodeS.top();
			nodeS.pop();
			nodeQ.push_front(nodeTemp->val);
			if(nodeTemp->left){
				nodeS.push(nodeTemp->left);
			}
			if(nodeTemp->right){
				nodeS.push(nodeTemp->right);
			}
		}
		vector<int> nodeV(nodeQ.begin(),nodeQ.end());
		return nodeV;
	}
};

#endif // P145_Solution_3



//#define P145_Solution_4		//Moirrs后序遍历
#ifdef P145_Solution_4

class Solution {
public:
	TreeNode* reversePath(TreeNode* head){
		TreeNode* front=nullptr;
		TreeNode* cur=head;
		while(cur){
			TreeNode* back=cur->right;
			cur->right=front;
			front=cur;
			cur=back;
		}
		return front;
	}

	void reversePrint(TreeNode* head,vector<int>& path){
		TreeNode* tail=reversePath(head);
		while(tail){
			path.push_back(tail->val);
			tail=tail->right;
		}
		reversePath(tail);
	}

	vector<int> postorderTraversal(TreeNode* root){
		vector<int> path;
		TreeNode* dump=new TreeNode(0);
		dump->left=root;
		TreeNode* cur=dump;
		TreeNode* pre=nullptr;
		while(cur){
			if(!cur->left){
				cur=cur->right;
			}
			else{
				pre=cur->left;
				while(pre->right&&pre->right!=cur){
					pre=pre->right;
				}
				if(pre->right==cur){
					pre->right=nullptr;
					reversePrint(cur->left,path);
					cur=cur->right;
				}
				else{
					pre->right=cur;
					cur=cur->left;
				}
			}
		}
		return path;
	}
};

#endif // P145_Solution_4



//#define P145_Test
#ifdef P145_Test

int main(){
	Solution Lee;
	TreeNode* node1=new TreeNode(1);
	TreeNode* node2=new TreeNode(2);
	TreeNode* node3=new TreeNode(3);

	node1->right=node2;
	node2->left=node3;

	vector<int> path=Lee.postorderTraversal(node1);
	for(auto it:path){
		cout<<it<<"\t";
	}
}

#endif // P145_Test



#endif // P145_Binary_tree_postorder_traversal_cpp