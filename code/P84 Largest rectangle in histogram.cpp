#define P84_Largest_rectangle_in_histogram_cpp
#ifdef P84_Largest_rectangle_in_histogram_cpp

//链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

#include"stdafx.h"

//#define P84_Solution_1		//暴力算法（Time Limit Exceeded）
#ifdef P84_Solution_1

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int maxArea=0;
		int size=heights.size();
		for(int i=0;i<size;++i){
			int left=i;
			int right=i;
			while(left-1>=0&&heights[left-1]>=heights[i]){
				--left;
			}
			while(right+1<size&&heights[right+1]>=heights[i]){
				++right;
			}
			maxArea=max(maxArea,(right-left+1)*heights[i]);
		}
		return maxArea;
	}
};

#endif // P84_Solution_1



#define P84_Solution_2		//暴力算法优化版（Time Limit Exceeded）
#ifdef P84_Solution_2

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int size=heights.size();
		int maxArea=0;
		for(int i=0;i<size;++i){
			int minHeight=heights[i];
			for(int j=i;j<size;++j){
				minHeight=min(minHeight,heights[j]);
				maxArea=max(maxArea,(j-i+1)*minHeight);
			}
		}
		return maxArea;
	}
};

#endif // P84_Solution_2



//#define P84_Solution_3		//单调栈（两次遍历）
#ifdef P84_Solution_3

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int size=heights.size();
		int maxArea=0;
		stack<int> monoStack;
		vector<int> leftBound(size);
		vector<int> rightBound(size);
		for(int i=0;i<size;++i){
			while(!monoStack.empty()&&heights[monoStack.top()]>=heights[i]){
				monoStack.pop();
			}
			leftBound[i]=monoStack.empty()?-1:monoStack.top();
			monoStack.push(i);
		}
		monoStack=stack<int>();
		for(int i=size-1;i>=0;--i){
			while(!monoStack.empty()&&heights[monoStack.top()]>=heights[i]){
				monoStack.pop();
			}
			rightBound[i]=monoStack.empty()?size:monoStack.top();
			monoStack.push(i);
		}
		for(int i=0;i<size;++i){
			maxArea=max(maxArea,(rightBound[i]-leftBound[i]-1)*heights[i]);
		}
		return maxArea;
	}
};

#endif // P84_Solution_3



//#define P84_Solution_4		//单调栈（一次遍历）
#ifdef P84_Solution_4

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int size=heights.size();
		int maxArea=0;
		stack<int> monoStack;
		vector<int> leftBound(size);
		vector<int> rightBound(size,size);
		for(int i=0;i<size;++i){
			while(!monoStack.empty()&&heights[monoStack.top()]>=heights[i]){
				rightBound[monoStack.top()]=i;
				monoStack.pop();
			}
			leftBound[i]=monoStack.empty()?-1:monoStack.top();
			monoStack.push(i);
		}
		for(int i=0;i<size;++i){
			maxArea=max(maxArea,(rightBound[i]-leftBound[i]-1)*heights[i]);
		}
		return maxArea;
	}
};

#endif // P84_Solution_4



//#define P84_Test
#ifdef P84_Test

int main(){
	Solution Lee;
}

#endif // P84_Test



#endif // P84_Largest_rectangle_in_histogram_cpp