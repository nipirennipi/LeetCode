# P4 寻找两个正序数组的中位数
@[toc]

题目链接：[4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/).

## 题目描述
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

**示例：**
>nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0

>nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5

## 题解
### 方法一：二分查找（中位数分割线）
==**思路**==

首先，对于一个正序数组，我们可以定义这么一条中位数分割线（图中红色的线）来将数组划分
对于长度为偶数的数组，中位数有两个，分别位于中位线的两边
对于长度为奇数的数组，中位数有一个，我们可以作人为规定，规定将其放置在中位数分割线的左边（当然你也可以将其放置到分割线的右边，但是一旦约定了，就不能改变，会影响到算法与代码的实现）

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200814151723448.png#pic_center)
我们可以发现中位数分割线的划分特点：
- 分割线左边的元素个数与分割线右边的元素个数相等或者比分割线右边的元素个数多一个
- 分割线左边的所有元素的值 ≤ 分割线右边的所有元素的值

将上面的两点中位数分割线的划分特点同样应用于对两个正序数组的划分

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020081415413134.png#pic_center)
**我们需要这条中位数分割线有什么用呢？**
可以观察到，在中位数分割线之后，有四个元素与我们所寻找的中位数密切相关，这四个元素就是在两个数组中，与分割线所相邻的四个元素，我们将分别其记为nums1LeftMax、nums1RightMin、nums2LeftMax、nums2RightMin。
>当两个正序数组中元素个数之和为奇数时，分割线左边元素的最大值就是中位数，又因为数组是正序的，所以nums1LeftMax、nums2LeftMax中的较大者就是中位数。
当两个正序数组中元素个数之和为偶数时，分割线左边元素的最大值就是其中一个中位数，分割线右边元素的最小值就是另一个中位数。
- 当两个正序数组中元素个数之和为奇数时，中位数 = max{nums1LeftMax,nums2LeftMax}
- 当两个正序数组中元素个数之和为偶数时，中位数 = (max{nums1LeftMax,nums2LeftMax} + min{nums1RightMin,nums2RightMin}) / 2

**寻找这条中位数分割线：**
我们先要考虑一个问题，是否需要在这两个数组中将分割线的位置都找出来？
其实是不用的，因为我们规定了分割线左边的元素个数与分割线右边的元素个数相等或者比分割线右边的元素个数多一个，这样我们只用在其中一个数组中找到分割线的位置，另一个数组中分割线的位置是可以计算出来的。

记第一个数组（**nums1**）的长度为**m**，第二个数组（**nums1**）的长度为**n**，中位数分割线左端的元素个数为**tatolLeft**；在第一个数组中，中位数分割线左端的元素个数为 **i** ；在第二个数组，中位数分割线左端的元素个数为 **j** 。
- 当两个正序数组中元素个数之和为奇数时，**tatolLeft=(m+n+1)/2**
- 当两个正序数组中元素个数之和为偶数时，**tatolLeft=(m+n)/2**

又由于对整型数据的计算中，向下取整，所以在代码中我们可以将上面两种情况合并来计算：**tatolLeft=(m+n+1)/2**，又由于**i+j=tatolLeft**，所以我们只用在其中一个数组中找到分割线的位置，另一个数组中分割线的位置是可以计算出来的，计算公式为 **j=tatolLeft-i**。

为了使时间复杂度到达$O(\log(m + n))$，自然会想到二分查找，在**一个数组**中使用二分查找来寻找其中位数分割线的位置，二分查找的条件应该为：分割线左边的所有元素的值 ≤ 分割线右边的所有元素的值，这个条件在代码中可以这么来表达
- **nums1[i-1] <= nums2[j] && nums2[j-1] <= nums1[i]**


**上面所述的在一个数组中使用二分查找，到底选择在哪个数组中使用二分查找？**
答案是应该选择在长度较短的数组上做二分查找（若长度一样，二者均可）
下面叙述原因：因为我们在对数组A使用二分查找时，需要访问在数组B中与当前分割线相邻的元素，以检验当前分割线是否满足条件（即分割线左边的所有元素的值 ≤ 分割线右边的所有元素的值）从而判断二分查找的方向，而数组B中的当前分割线的位置是通过公式： **j=tatolLeft-i** 计算得到的，若数组A较长，在二分查找时会导致 **i** 的值很大，从而计算得到的 **j** 可能会大于数组B的长度或者为负数，从而导致数组访问越界。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200814204112313.png#pic_center)
而我们选择在长度较短的数组上做二分查找，则在另一个长度较长的数组上不会发生越界访问的情况，下面是证明：
>证明：
>记长度较短的数组为nums1，长度为 $m$ ；记另一个数组为nums2，长度为 $n$，则有 $m\leqslant n$，$i$ 为数组nums1上当前分割线的位置，$j$ 为数组nums2上当前分割线的位置，$0\leqslant i\leqslant m$。
>\
>证明nums2数组上不会发生越界情况，即证$0\leqslant j\leqslant n$
>\
>由 $i+j=\lfloor (\frac{(m+n+1)}{2})\rfloor$ 、$0\leqslant i\leqslant m$
>\
>得 $\lfloor (\frac{(m+n+1)}{2})\rfloor-m\leqslant j\leqslant\lfloor (\frac{(m+n+1)}{2})\rfloor$
>\
>由 $m\leqslant n$
>\
>得 $\lfloor (\frac{(m+n+1)}{2})\rfloor-m=\lfloor (\frac{(n-m+1)}{2})\rfloor\geqslant0$
>\
>$\lfloor (\frac{(m+n+1)}{2})\rfloor\leqslant\lfloor (\frac{(2n+1)}{2})\rfloor=n$
>\
>故 $0\leqslant j\leqslant n$
>
>得证

==**算法**==

>说明：
>①代码有两个while循环，一个被注释掉了，其实这两个while循环都可以用，只是在二分查找时使用检验条件不一样。
>②代码中如 totalLeft=m+(n-m+1)/2 的写法其实就是 totalLeft=(m+n+1)/2 ，这样写是为了防止溢出。

```cpp
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {
		int m=nums1.size();
		int n=nums2.size();
		//使nums1的长度 <= nums2的长度
		if(m>n){
			return findMedianSortedArrays(nums2,nums1);
		}
		int totalLeft=m+(n-m+1)/2;
		int left=0;
		int right=m;
		int i;
		int j;
		//最终分割线需要满足nums1[i-1]<=nums2[j]&&nums2[j-1]<=nums1[i]
		//而我们二分查找时，只选择其中一个条件取反来检验分割线是否满足就够了
		
		//使用条件nums1[i-1]>nums2[j]来检验
		while(left<right){
			//二分查找nums1的最终分割线
			i=left+(right-left+1)/2;
			/*i=left+(right-left+1)/2中+1的原因：
			1.当left与right相差为1时，若不＋1，就会出现i=left，区间为[left(i),right],而此时nums1的最终分割线(i)只会在left或者right处，
				即nums1的最终分割线只可能为当前分割线(i)或者其右边,导致进入else分支，left=i，如此反复，进入死循环。
			2.+1后，i!=0	，从而nums1[i-1]不会导致数组越界访问。
				由0<i<=m、i+j=[(m+n+1)/2],利用反证法可得j!=n，从而nums2[j]不会导致数组越界访问。(证明在代码后)
			*/
			j=totalLeft-i;
			//若nums1的分割线左边的元素 >= nums2的分割线右边的元素，则说明nums1的最终分割线在当前分割线的左边，左缩区间为[left,i-1]
			if(nums1[i-1]>nums2[j]){
				right=i-1;
			}
			//否则，说明nums1的最终分割线可能为当前分割线或者其右边，右缩区间为[i,right]
			else{
				left=i;
			}
		}
		
		////使用条件nums2[j-1]>nums1[i]来检验
		//while(left<right){
		//	//二分查找nums1的最终分割线
		//	i=left+(right-left)/2;
		//	/*i=left+(right-left)/2中不+1的原因：
		//	1.当left与right相差为1时，若＋1，就会出现i=left+1=right，区间为[left,right(i)],而此时nums1的最终分割线(i)只会在left或者right处，
		//		即nums1的最终分割线只可能为当前分割线(i)或者其左边，导致进入else分支，right=i，如此反复，进入死循环。
		//	2.不+1后，i!=m，从而nums1[i]不会导致数组越界访问。
		//		由0<=i<m、i+j=[(m+n+1)/2],利用反证法可得j!=0，从而nums2[j-1]不会导致数组越界访问。(证明在代码后)
		//	*/
		//	j=totalLeft-i;
		//	//若nums2的分割线左边的元素 >= nums1的分割线右边的元素，则说明nums1的最终分割线在当前分割线的右边，右缩区间为[i+1,right]
		//	if(nums2[j-1]>nums1[i]){
		//		left=i+1;
		//	}
		//	//否则，说明nums1的最终分割线可能为当前分割线或者其左边，左缩区间为[left,i]
		//	else{
		//		right=i;
		//	}
		//}
		i=left;
		j=totalLeft-i;
		//i==0时，第一个数组中的分割线左边无元素，为了使max(nums1LeftMax,nums2LeftMax)=nums2LeftMax，令nums1LeftMax为整型下限
		int nums1LeftMax=(i==0?INT_MIN:nums1[i-1]);
		//i==m时，第一个数组中的分割线右边无元素，为了使min(nums1RightMin,nums2RightMin)=nums2RightMin，令nums1RightMin为整形上限
		int nums1RightMin=(i==m?INT_MAX:nums1[i]);
		//j==0时，第二个数组中的分割线左边无元素，为了使max(nums1LeftMax,nums2LeftMax)=nums1LeftMax，令nums2LeftMax为整形下限
		int nums2LeftMax=(j==0?INT_MIN:nums2[j-1]);
		//j==n时，第二个数组中的分割线右边无元素，为了使min(nums1RightMin,nums2RightMin)=nums1RightMin，令nums2RightMin为整形上限
		int nums2RightMin=(j==n?INT_MAX:nums2[j]);
		//两数组总长度为奇数
		if((m+n)%2){
			return max(nums1LeftMax,nums2LeftMax);
		}
		//两数组总长度为偶数
		else{
			return (max(nums1LeftMax,nums2LeftMax)+min(nums1RightMin,nums2RightMin))/2.0;
		}
	}
};
```

>已知 $i+j=\lfloor\frac{m+n+1}{2}\rfloor$ 、$m\leqslant n$ 、$0<i\leqslant m$，证明：$j\neq n$
> \
>证明：假设 $j=n$
>\
>由 $i+j=\lfloor\frac{m+n+1}{2}\rfloor$ 、$m\leqslant n$
>\
>得 $i=\lfloor\frac{m+n+1}{2}\rfloor-n=\lfloor\frac{m-n+1}{2}\rfloor\leqslant 0$
>\
>与 $0<i\leqslant m$ 相矛盾，故假设不成立，$j\neq n$

>已知 $i+j=\lfloor\frac{m+n+1}{2}\rfloor$ 、$m\leqslant n$ 、$0\leqslant i< m$，证明：$j\neq 0$
> \
>证明：假设 $j=0$
>\
>由 $i+j=\lfloor\frac{m+n+1}{2}\rfloor$ 、$m\leqslant n$
>\
>得 $i=\lfloor\frac{m+n+1}{2}\rfloor\geqslant\lfloor\frac{2m+1}{2}\rfloor=m$
>\
>与 $0\leqslant i< m$ 相矛盾，故假设不成立，$j\neq 0$

==**复杂度分析**==

假设 $m$ 、$n$ 分别表示正序数组 $nums1$、$nums2$ 的长度
- 时间复杂度：$O(\log \min(m,n))$
- 空间复杂度：$O(1)$
