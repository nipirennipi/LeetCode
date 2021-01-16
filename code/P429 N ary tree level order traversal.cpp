#define P429_N_ary_tree_level_order_traversal_cpp
#ifdef P429_N_ary_tree_level_order_traversal_cpp

//¡¥Ω”£∫https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/

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

//#define P429_Solution_1			//∂”¡–	T(n)=O(n) S(n)=O(n)
#ifdef P429_Solution_1

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		if(!root){
			return vector<vector<int>>();
		}
		vector<vector<int>> res;
		queue<Node*> nodeQ;
		nodeQ.push(root);
		while(!nodeQ.empty()){
			int size=nodeQ.size();
			vector<int> tempV;
			while(size--){
				Node* tempNode=nodeQ.front();
				tempV.push_back(tempNode->val);
				for(int i=0;i<tempNode->children.size();++i){
					nodeQ.push(tempNode->children[i]);
				}
				nodeQ.pop();
			}
			res.push_back(tempV);
		}
		return res;
	}
};

#endif // P429_Solution_1



//#define P429_Solution_2			//µ›πÈ	T(n)=O(n) S(n)=O(logn)
#ifdef P429_Solution_2

class Solution {
private:
	vector<vector<int>> res;

	void levelOrderHelper(Node* root,int depth){
		if(res.size()<=depth){
			res.push_back(vector<int>());
		}
		res[depth].push_back(root->val);
		for(int i=0;i<root->children.size();++i){
			levelOrderHelper(root->children[i],depth+1);
		}
	}
public:
	vector<vector<int>> levelOrder(Node* root) {
		if(root){
			levelOrderHelper(root,0);
		}
		return res;
	}
};

#endif // P429_Solution_2



#define P429_Solution_3
#ifdef P429_Solution_3



#endif // P429_Solution_3



//#define P429_Test
#ifdef P429_Test

int main(){
	Solution Lee;
}

#endif // P429_Test



#endif // P429_N_ary_tree_level_order_traversal_cpp