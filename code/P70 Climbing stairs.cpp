#define P70_Climbing_stairs_cpp
#ifdef P70_Climbing_stairs_cpp

//链接：https://leetcode-cn.com/problems/climbing-stairs/

#include"stdafx.h"

//#define P70_Solution_1		//递归（T(n)=O(2^n),S(n)=O(n)）（TIME LIMIT EXCEEDED）
#ifdef P70_Solution_1

class Solution {
public:
	int climbStairs(int n) {
		if(n==1){
			return 1;
		}
		if(n==2){
			return 2;
		}
		return climbStairs(n-1)+climbStairs(n-2);
	}
};

#endif // P70_Solution_1



//#define P70_Solution_2		//记忆型递归（T(n)=O(n),S(n)=O(n)）（Time Limit Exceeded）
#ifdef P70_Solution_2

class Solution {
public:
	int climbStairs(int n) {
		vector<int> memory(n+1,0);
		return climbStairsMemory(memory,n);
	}

	int climbStairsMemory(vector<int> memory,int n){
		if(memory[n]>0){
			return memory[n];
		}
		if(n==1){
			memory[n]=1;
		}
		else if(n==2){
			memory[n]=2;
		}
		else{
			memory[n]=climbStairsMemory(memory,n-1)+climbStairsMemory(memory,n-2);
		}
		return memory[n];
	}
};

#endif // P70_Solution_2



//#define P70_Solution_3		//动态规划（T(n)=O(n),S(n)=O(n)）
#ifdef P70_Solution_3

class Solution {
public:
	int climbStairs(int n) {
		if(n==1){
			return 1;
		}
		if(n==2){
			return 2;
		}
		vector<int> dp(n+1);
		dp[1]=1;
		dp[2]=2;
		for(int i=3;i<=n;++i){
			dp[i]=dp[i-1]+dp[i-2];
		}
		return dp[n];
	}
};

#endif // P70_Solution_3



//#define P70_Solution_4		//动态规划+滚动数组（T(n)=O(n),S(n)=O(1)）（斐波那契数列）
#ifdef P70_Solution_4

class Solution {
public:
	int climbStairs(int n) {
		if(n==1){
			return 1;
		}
		if(n==2){
			return 2;
		}
		int left=1;
		int right=2;
		int temp;
		for(int i=3;i<=n;++i){
			temp=left+right;
			left=right;
			right=temp;
		}
		return right;
	}
};

#endif // P70_Solution_4



//#define P70_Solution_5		//矩阵快速幂	
#ifdef P70_Solution_5

class Solution {
public:
	vector<vector<int>> matrixMultiple(vector<vector<int>> left,vector<vector<int>> right){
		int leftRows=left.size();
		int count=left[0].size();
		int rightColumns=right[0].size();
		vector<vector<int>> result(leftRows,vector<int>(rightColumns));
		for(int i=0;i<leftRows;++i){
			for(int j=0;j<rightColumns;++j){
				for(int k=0;k<count;++k){
					result[i][j]+=(left[i][k]*right[k][j]);
				}
			}
		}
		return result;
	};

	vector<vector<int>> matrixQuickPow(vector<vector<int>> m,int n){		//求方阵m的n次幂
		int rows=m.size();
		vector<vector<int>> result(rows,vector<int>(rows));
		for(int i=0;i<rows;++i){
			result[i][i]=1;
		}
		while(n>1){		//防止m*m导致整数溢出，提前结束循环
			if(n&1){
				result=matrixMultiple(result,m);
			}
			n>>=1;
			m=matrixMultiple(m,m);
		}
		if(n&1){
			result=matrixMultiple(result,m);
		}
		return result;
	}

	int climbStairs(int n) {
		vector<vector<int>> m{{1,1},{1,0}};
		vector<vector<int>> result=matrixQuickPow(m,n);
		return result[1][0]+result[1][1];
	}
};

#endif // P70_Solution_5



#define P70_Solution_6		//直接返回结果
#ifdef P70_Solution_6

class Solution {
public:
	int climbStairs(int n) {
		int a[47]={0,1,2,3,5,8,13,21,34,55,89,144,233,377,610,
					987,1597,2584,4181,6765,10946,17711,28657,
					46368,75025,121393,196418,317811,514229,
					832040,1346269,2178309,3524578,5702887,
					9227465,14930352,24157817,39088169,63245986,
					102334155,165580141,267914296,433494437,
					701408733,1134903170,1836311903};
		return a[n];
	}
};

#endif // P70_Solution_6



//#define P70_Test
#ifdef P70_Test

int main(){
	Solution Lee;
	for(int i=1;i<=45;++i){
		cout<<"case "<<i<<":\n"<<"\treturn "<<Lee.climbStairs(i)<<";\n";
	}
}

#endif // P70_Test



#endif // P70_Climbing_stairs_cpp