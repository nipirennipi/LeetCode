#define P85_Maximal_rectangle_cpp
#ifdef P85_Maximal_rectangle_cpp

//链接：https://leetcode-cn.com/problems/maximal-rectangle/

#include"stdafx.h"

//#define P85_Solution_1		//逐行分解为柱状图 + 单调栈（一次遍历）
#ifdef P85_Solution_1

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if(!matrix.size()||!matrix[0].size()){
			return 0;
		}
		int rows=matrix.size();
		int columns=matrix[0].size();
		vector<vector<int>> heights(rows,vector<int>(columns,0));
		for(int j=0;j<columns;++j){
			if(matrix[0][j]=='1'){
				heights[0][j]=1;
			}
		}
		for(int i=1;i<rows;++i){
			for(int j=0;j<columns;++j){
				if(matrix[i][j]=='1'){
					heights[i][j]=heights[i-1][j]+1;
				}
			}
		}
		int maxArea=0;
		for(int i=0;i<rows;++i){
			stack<int> monoStack;
			vector<int> leftBound(columns);
			vector<int> rightBound(columns,columns);
			for(int j=0;j<columns;++j){
				while(!monoStack.empty()&&heights[i][monoStack.top()]>=heights[i][j]){
					rightBound[monoStack.top()]=j;
					monoStack.pop();
				}
				leftBound[j]=monoStack.empty()?-1:monoStack.top();
				monoStack.push(j);
			}
			for(int k=0;k<columns;++k){
				maxArea=max(maxArea,(rightBound[k]-leftBound[k]-1)*heights[i][k]);
			}
		}
		return maxArea;
	}
};

#endif // P85_Solution_1



//#define P85_Solution_2		//逐行分解为柱状图 + 单调栈（一次遍历）+ 滚动数组
#ifdef P85_Solution_2

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if(!matrix.size()||!matrix[0].size()){
			return 0;
		}
		int rows=matrix.size();
		int columns=matrix[0].size();
		vector<int> heights(columns,0);
		int maxArea=0;
		for(int i=0;i<rows;++i){
			for(int j=0;j<columns;++j){
				heights[j]=matrix[i][j]=='1'?heights[j]+1:0;
			}
			stack<int> monoStack;
			vector<int> leftBound(columns);
			vector<int> rightBound(columns,columns);
			for(int j=0;j<columns;++j){
				while(!monoStack.empty()&&heights[monoStack.top()]>=heights[j]){
					rightBound[monoStack.top()]=j;
					monoStack.pop();
				}
				leftBound[j]=monoStack.empty()?-1:monoStack.top();
				monoStack.push(j);
			}
			for(int k=0;k<columns;++k){
				maxArea=max(maxArea,(rightBound[k]-leftBound[k]-1)*heights[k]);
			}
		}
		return maxArea;
	}
};

#endif // P85_Solution_2



//#define P85_Solution_3		//动态规划（柱状图的暴力算法优化版）
#ifdef P85_Solution_3

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if(!matrix.size()||!matrix[0].size()){
			return 0;
		}
		int rows=matrix.size();
		int columns=matrix[0].size();
		int maxArea=0;
		vector<vector<int>> dp(rows,vector<int>(columns,0));
		for(int i=0;i<rows;++i){
			for(int j=0;j<columns;++j){
				if(matrix[i][j]=='1'){
					dp[i][j]=j!=0?dp[i][j-1]+1:1;
					int minWidth=dp[i][j];
					for(int k=i;k>=0;--k){
						minWidth=min(minWidth,dp[k][j]);
						maxArea=max(maxArea,(i-k+1)*minWidth);
					}
				}
			}
		}
		return maxArea;
	}
};

#endif // P85_Solution_3



#define P85_Solution_4		//动态规划
#ifdef P85_Solution_4

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if(!matrix.size()||!matrix[0].size()){
			return 0;
		}
		int rows=matrix.size();
		int columns=matrix[0].size();
		int maxArea=0;
		vector<int> heights(columns);
		vector<int> leftBound(columns,-1);
		vector<int> rightBound(columns,columns);
		for(int i=0;i<rows;++i){
			int leftNearest=-1;
			int rightNearest=columns;
			for(int j=0;j<columns;++j){
				if(matrix[i][j]=='1'){
					++heights[j];
					leftBound[j]=max(leftBound[j],leftNearest);
				}
				else{
					heights[j]=0;
					leftNearest=j;
					leftBound[j]=-1;	
				}
				if(matrix[i][columns-j-1]=='1'){
					rightBound[columns-j-1]=min(rightBound[columns-j-1],rightNearest);
				}
				else{
					rightNearest=columns-j-1;
					rightBound[columns-j-1]=columns;
				}
			}
			for(int j=0;j<columns;++j){
				maxArea=max(maxArea,(rightBound[j]-leftBound[j]-1)*heights[j]);
			}
		}
		return maxArea;
	}
};

#endif // P85_Solution_4



//#define P85_Test
#ifdef P85_Test

int main(){
	Solution Lee;
	//vector<vector<char>> matrix={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	vector<vector<char>> matrix={{'1','0'}};
	cout<<Lee.maximalRectangle(matrix);
}

#endif // P85_Test



#endif // P85_Maximal_rectangle_cpp