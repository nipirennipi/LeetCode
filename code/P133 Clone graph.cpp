#define P133_Clone_graph_cpp
#ifdef P133_Clone_graph_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/clone-graph/

#include"stdafx.h"

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

#define P133_Solution_1
#ifdef P133_Solution_1

class Solution {
public:
	Node* cloneGraph(Node* node) {
		
	}
};

#endif // P133_Solution_1



#define P133_Solution_2
#ifdef P133_Solution_2



#endif // P133_Solution_2



//#define P133_Test
#ifdef P133_Test

int main(){
	Solution Lee;
}

#endif // P133_Test



#endif // P133_Clone_graph_cpp