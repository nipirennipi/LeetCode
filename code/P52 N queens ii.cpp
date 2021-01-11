#define P52_N_queens_ii_cpp
#ifdef P52_N_queens_ii_cpp

//Á´½Ó£ºhttps://leetcode-cn.com/problems/n-queens-ii/

#include"stdafx.h"

#define P52_Solution_1		//»ØËÝ
#ifdef P52_Solution_1

class Solution {
public:
	int totalNQueens(int n) {
		unordered_set<int> columns;
		unordered_set<int> diagonalsr;
		unordered_set<int> diagonalsl;
		int ansNum=0;
		backtrack(ansNum,n,0,columns,diagonalsr,diagonalsl);
		return  ansNum;
	}

	void backtrack(int& ansNum,int n,int row,unordered_set<int>& columns,
					unordered_set<int>& diagonalsr,unordered_set<int>& diagonalsl){
		if(row==n){
			++ansNum;
		}
		else{
			for(int col=0;col<n;++col){
				int diagr=row-col;
				int diagl=row+col;
				if(!columns.count(col)&&!diagonalsr.count(diagr)&&!diagonalsl.count(diagl)){
					columns.insert(col);
					diagonalsr.insert(diagr);
					diagonalsl.insert(diagl);
					backtrack(ansNum,n,row+1,columns,diagonalsr,diagonalsl);
					columns.erase(col);
					diagonalsr.erase(diagr);
					diagonalsl.erase(diagl);
				}
			}
		}
	}
};

#endif // P52_Solution_1



#define P52_Solution_2
#ifdef P52_Solution_2



#endif // P52_Solution_2



//#define P52_Test
#ifdef P52_Test

int main(){
	Solution Lee;
}

#endif // P52_Test



#endif // P52_N_queens_ii_cpp