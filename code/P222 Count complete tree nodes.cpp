#define P222_Count_complete_tree_nodes_cpp
#ifdef P222_Count_complete_tree_nodes_cpp

//���ӣ�

#include"stdafx.h"

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x),left(NULL),right(NULL) {}
};

//#define P222_Solution_1			//DFS	T(n)=O(n),S(n)=O(n)
#ifdef P222_Solution_1

class Solution {
public:
	int countNodes(TreeNode* root) {
		if(!root){
			return 0;
		}
		return countNodes(root->left)+countNodes(root->right)+1;
	}
};

#endif // P222_Solution_1



//#define P222_Solution_2			//BFS	T(n)=O(n),S(n)=O(n)
#ifdef P222_Solution_2				//���������������������ͨ��BFS����DFS����ڵ����

class Solution {
public:
	int countNodes(TreeNode* root) {
		if(!root){
			return 0;
		}
		int count=0;
		queue<TreeNode*> nodeQ;
		nodeQ.push(root);
		while(!nodeQ.empty()){
			TreeNode* node=nodeQ.front();
			if(node->left){
				nodeQ.push(node->left);
			}
			if(node->right){
				nodeQ.push(node->right);
			}
			nodeQ.pop();
			++count;
		}
		return count;
	}
};

#endif // P222_Solution_2



#define P222_Solution_3			//���ֲ��� + λ����
#ifdef P222_Solution_3

class Solution {
public:
	int getDepth(TreeNode* root){		//����ȫ������������(�����λ�ڵ�0��)	
		if(!root){
			return 0;
		}
		int depth=0;
		while(root->left){
			++depth;
			root=root->left;
		}
		return depth;
	}

	bool exist(TreeNode* root,int depth,int k){		//λ�����жϽ��k�Ƿ����
		int mode=1<<(depth-1);
		while(root&&mode){
			if(k&mode){
				root=root->right;
			}
			else{
				root=root->left;
			}
			mode>>=1;
		}
		return root;
	}

	int countNodes(TreeNode* root) {
		if(!root){
			return 0;
		}
		int depth=getDepth(root);
		int left=1<<depth;
		int right=(1<<(depth+1))-1;
		while(left<right){
			int mid=left+((right-left+1)>>1);		//ע����������ȼ�
			if(exist(root,depth,mid)){
				left=mid;
			}
			else{
				right=mid-1;
			}
		}
		return left;
	}
};

#endif // P222_Solution_3



//#define P222_Test
#ifdef P222_Test

int main(){
	Solution Lee;
	TreeNode* node1=new TreeNode(1);
	TreeNode* node2=new TreeNode(2);
	TreeNode* node3=new TreeNode(3);
	TreeNode* node4=new TreeNode(4);
	TreeNode* node5=new TreeNode(5);
	TreeNode* node6=new TreeNode(6);
	
	node1->left=node2;
	node1->right=node3;

	node2->left=node4;
	node2->right=node5;

	node3->left=node6;
	
	cout<<Lee.countNodes(node1);
}

#endif // P222_Test



#endif // P222_Count_complete_tree_nodes_cpp