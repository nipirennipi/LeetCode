#define P559_Maximum_depth_of_n_ary_tree_cpp
#ifdef P559_Maximum_depth_of_n_ary_tree_cpp

//链接：https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/

#include"stdafx.h"

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val=_val;
	}

	Node(int _val,vector<Node*> _children) {
		val=_val;
		children=_children;
	}
};

//#define P559_Solution_1			//层序遍历(队列)	T(n)=O(n)	S(n)=O(n)
#ifdef P559_Solution_1

class Solution {
public:
	int maxDepth(Node* root) {
		if(!root){
			return 0;
		}
		queue<Node*> nodeQ;
		nodeQ.push(root);
		int depth=0;
		while(!nodeQ.empty()){
			int size=nodeQ.size();
			for(int i=0;i<size;++i){
				Node* tempNode=nodeQ.front();
				nodeQ.pop();
				for(auto child:tempNode->children){
					nodeQ.push(child);
				}
			}
			++depth;
		}
		return depth;
	}
};

#endif // P559_Solution_1



//#define P559_Solution_2			//递归	T(n)=O(n)	S(n)=O(logn)
#ifdef P559_Solution_2

class Solution {
public:
	int maxDepth(Node* root) {
		if(!root){
			return 0;
		}
		int depth=0;
		for(auto child:root->children){
			depth=max(maxDepth(child),depth);
		}
		return depth+1;
	}
};

#endif // P559_Solution_2



//#define P559_Test
#ifdef P559_Test

int main(){
	Solution Lee;
}

#endif // P559_Test



#endif // P559_Maximum_depth_of_n_ary_tree_cpp