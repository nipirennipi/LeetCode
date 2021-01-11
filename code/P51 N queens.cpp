#define P51_N_queens_cpp
#ifdef P51_N_queens_cpp

//链接：https://leetcode-cn.com/problems/n-queens/

#include"stdafx.h"

#define P51_Solution_1		//回溯（使用unordered_set）
#ifdef P51_Solution_1

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> ans;
		vector<int> queens(n,-1);
		unordered_set<int> columns;
		unordered_set<int> diagonalsr;
		unordered_set<int> diagonalsl;
		backtrack(ans,queens,0,n,columns,diagonalsr,diagonalsl);
		return ans;
	}

	void backtrack(vector<vector<string>>& ans,vector<int>& queens,int row,int n,
					unordered_set<int>& columns,unordered_set<int>& diagonalsr,unordered_set<int>& diagonalsl){
		if(row==n){
			//开始构造一种情况并加入ans中。
			vector<string> solution;
			for(int i=0;i<=n-1;++i){
				string temp(n,'.');
				temp[queens[i]]='Q';
				solution.push_back(temp);
			}
			ans.push_back(solution);
		}
		else{
			for(int col=0;col<=n-1;++col){
				int diar=row-col;
				int dial=row+col;
				if(!columns.count(col)&&!diagonalsr.count(diar)&&!diagonalsl.count(dial)){
					queens[row]=col;
					columns.insert(col);
					diagonalsr.insert(diar);
					diagonalsl.insert(dial);
					backtrack(ans,queens,row+1,n,columns,diagonalsr,diagonalsl);
					queens[row]=-1;
					columns.erase(col);
					diagonalsr.erase(diar);
					diagonalsl.erase(dial);
				}
			}
		}
	}
};

#endif // P51_Solution_1



#define P51_Solution_2
#ifdef P51_Solution_2



#endif // P51_Solution_2



//#define P51_Test
#ifdef P51_Test

int main(){
	Solution Lee;
	int n=8;
	vector<vector<string>> ans;
	ans=Lee.solveNQueens(n);
	cout<<"the number of ans : "<<ans.size()<<"\n";
	for(int count=0;count<ans.size();++count){
		vector<string> tempV=ans[count];
		cout<<"\nans "<<count<<"\n";
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cout<<tempV[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
}

#endif // P51_Test



#endif // P51_N_queens_cpp