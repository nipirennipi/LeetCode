#ifndef STDAFX_H
#define STDAFX_H

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<cmath>
#include<conio.h>
#include<windows.h>
#include<numeric>		//iota函数，递增赋值
#include<random>
#include<ctime>

#include<cstdarg>		//可变参数

#include<algorithm>		//STL算法库
#include<iterator>
#include<functional>	//函数对象

//顺序容器
#include<array>			//随机
#include<vector>
#include<deque> 
#include<list>			//双向
#include<forward_list>	//前向

//由顺序容器适通过容器适配器转化得到（没有iterator）
#include<stack>			
#include<queue>			//priority_queue也在这个里面


//关联容器
#include<set>
#include<map>

//无序容器
#include<unordered_set>
#include<unordered_map>

using namespace std;


#endif // !STDAFX_H