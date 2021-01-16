#define P4_Find_the_median_of_two_positive_arrays_cpp
#ifdef P4_Find_the_median_of_two_positive_arrays_cpp

//链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

#include"stdafx.h"

//#define P4_Solution_1
#ifdef P4_Solution_1

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

#endif // P4_Solution_1



#define P4_Solution_2
#ifdef P4_Solution_2



#endif // P4_Solution_2



//#define P4_Test
#ifdef P4_Test

int main(){
	Solution Lee;
	vector<int> nums1{1,4,8,9,11,12,14,17};
	vector<int> nums2{2,5};
	cout<<Lee.findMedianSortedArrays(nums1,nums2);
}

#endif // P4_Test



#endif // P4_Find_the_median_of_two_positive_arrays_cpp