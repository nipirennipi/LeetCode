#define P947_Most_stones_removed_with_same_row_or_column_cpp
#ifdef P947_Most_stones_removed_with_same_row_or_column_cpp

//链接：https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/

#include"stdafx.h"

#define P947_Solution_1			//并查集
#ifdef P947_Solution_1

class UFS{
private:
	unordered_map<int,int> fa;
	unordered_map<int,int> rank;
public:
	int find(int x){
		if(!fa.count(x)){
			fa[x]=x;
			rank[x]=1;
		}
		if(fa[x]==x){
			return x;
		}
		return find(fa[x]);
	}

	void unionPro(int x,int y){
		x=find(x);
		y=find(y);
		if(rank[x]<=rank[y]){
			fa[x]=y;
		}
		else{
			fa[y]=x;
		}
		if(rank[x]==rank[y]&&x!=y){
			++rank[y];
		}
	}

	int connectedComponentCount(){
		int count=0;
		for(auto m:fa){
			if(m.first==m.second){
				++count;
			}
		}
		return count;
	}
};

class Solution {
public:
	int removeStones(vector<vector<int>>& stones) {
		UFS s;
		for(int i=0;i<stones.size();++i){
			s.unionPro(stones[i][0],~stones[i][1]);
		}
		return stones.size()-s.connectedComponentCount();
	}
};

#endif // P947_Solution_1



#define P947_Solution_2
#ifdef P947_Solution_2	



#endif // P947_Solution_2



//#define P947_Test
#ifdef P947_Test

int main(){
	Solution Lee;
}

#endif // P947_Test



#endif // P947_Most_stones_removed_with_same_row_or_column_cpp