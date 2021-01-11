#define P4_Find_the_median_of_two_positive_arrays_cpp
#ifdef P4_Find_the_median_of_two_positive_arrays_cpp

//���ӣ�https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

#include"stdafx.h"

//#define P4_Solution_1
#ifdef P4_Solution_1

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {
		int m=nums1.size();
		int n=nums2.size();
		//ʹnums1�ĳ��� <= nums2�ĳ���
		if(m>n){
			return findMedianSortedArrays(nums2,nums1);
		}
		int totalLeft=m+(n-m+1)/2;
		int left=0;
		int right=m;
		int i;
		int j;
		//���շָ�����Ҫ����nums1[i-1]<=nums2[j]&&nums2[j-1]<=nums1[i]
		//�����Ƕ��ֲ���ʱ��ֻѡ������һ������ȡ��������ָ����Ƿ�����͹���
		
		//ʹ������nums1[i-1]>nums2[j]������
		while(left<right){
			//���ֲ���nums1�����շָ���
			i=left+(right-left+1)/2;
			/*i=left+(right-left+1)/2��+1��ԭ��
			1.��left��right���Ϊ1ʱ��������1���ͻ����i=left������Ϊ[left(i),right],����ʱnums1�����շָ���(i)ֻ����left����right����
				��nums1�����շָ���ֻ����Ϊ��ǰ�ָ���(i)�������ұ�,���½���else��֧��left=i����˷�����������ѭ����
			2.+1��i!=0	���Ӷ�nums1[i-1]���ᵼ������Խ����ʡ�
				��0<i<=m��i+j=[(m+n+1)/2],���÷�֤���ɵ�j!=n���Ӷ�nums2[j]���ᵼ������Խ����ʡ�(֤���ڴ����)
			*/
			j=totalLeft-i;
			//��nums1�ķָ�����ߵ�Ԫ�� >= nums2�ķָ����ұߵ�Ԫ�أ���˵��nums1�����շָ����ڵ�ǰ�ָ��ߵ���ߣ���������Ϊ[left,i-1]
			if(nums1[i-1]>nums2[j]){
				right=i-1;
			}
			//����˵��nums1�����շָ��߿���Ϊ��ǰ�ָ��߻������ұߣ���������Ϊ[i,right]
			else{
				left=i;
			}
		}
		
		////ʹ������nums2[j-1]>nums1[i]������
		//while(left<right){
		//	//���ֲ���nums1�����շָ���
		//	i=left+(right-left)/2;
		//	/*i=left+(right-left)/2�в�+1��ԭ��
		//	1.��left��right���Ϊ1ʱ������1���ͻ����i=left+1=right������Ϊ[left,right(i)],����ʱnums1�����շָ���(i)ֻ����left����right����
		//		��nums1�����շָ���ֻ����Ϊ��ǰ�ָ���(i)��������ߣ����½���else��֧��right=i����˷�����������ѭ����
		//	2.��+1��i!=m���Ӷ�nums1[i]���ᵼ������Խ����ʡ�
		//		��0<=i<m��i+j=[(m+n+1)/2],���÷�֤���ɵ�j!=0���Ӷ�nums2[j-1]���ᵼ������Խ����ʡ�(֤���ڴ����)
		//	*/
		//	j=totalLeft-i;
		//	//��nums2�ķָ�����ߵ�Ԫ�� >= nums1�ķָ����ұߵ�Ԫ�أ���˵��nums1�����շָ����ڵ�ǰ�ָ��ߵ��ұߣ���������Ϊ[i+1,right]
		//	if(nums2[j-1]>nums1[i]){
		//		left=i+1;
		//	}
		//	//����˵��nums1�����շָ��߿���Ϊ��ǰ�ָ��߻�������ߣ���������Ϊ[left,i]
		//	else{
		//		right=i;
		//	}
		//}
		i=left;
		j=totalLeft-i;
		//i==0ʱ����һ�������еķָ��������Ԫ�أ�Ϊ��ʹmax(nums1LeftMax,nums2LeftMax)=nums2LeftMax����nums1LeftMaxΪ��������
		int nums1LeftMax=(i==0?INT_MIN:nums1[i-1]);
		//i==mʱ����һ�������еķָ����ұ���Ԫ�أ�Ϊ��ʹmin(nums1RightMin,nums2RightMin)=nums2RightMin����nums1RightMinΪ��������
		int nums1RightMin=(i==m?INT_MAX:nums1[i]);
		//j==0ʱ���ڶ��������еķָ��������Ԫ�أ�Ϊ��ʹmax(nums1LeftMax,nums2LeftMax)=nums1LeftMax����nums2LeftMaxΪ��������
		int nums2LeftMax=(j==0?INT_MIN:nums2[j-1]);
		//j==nʱ���ڶ��������еķָ����ұ���Ԫ�أ�Ϊ��ʹmin(nums1RightMin,nums2RightMin)=nums1RightMin����nums2RightMinΪ��������
		int nums2RightMin=(j==n?INT_MAX:nums2[j]);
		//�������ܳ���Ϊ����
		if((m+n)%2){
			return max(nums1LeftMax,nums2LeftMax);
		}
		//�������ܳ���Ϊż��
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