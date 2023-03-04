#include<stdio.h>
#include<malloc.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *ret = (int*)malloc(sizeof(int) * 2);//Ҫ���ص�����
	int left = 0;
	int right = numsSize - 1;
	int mid = 0;
	ret[0] = ret[1] = -1;//����ֵ
	*returnSize = 2;
	while(left <= right){
		mid = (left + right) / 2;
		if(target > nums[mid]){
			left = mid + 1;
		}//���ֵķ�������
		else if(target < nums[mid]){
			right = mid - 1;
		}
		else{
			if(mid > 0 && target == nums[mid - 1]){
				right = mid - 1;
			}//���target��nums[mid]ǰ��һ����Ҳ���
			else{
				ret[0] = mid;
				break;
			}//����ҵ����޸�ret,���˳�ѭ��
		}//����Ҵ�һ������ˣ�Ҫ�����ҳ��߽�
	}//������ѭ��
	left = 0;
	right = numsSize - 1;
	while(left <= right){
		mid = (left + right) / 2;
		if(target > nums[mid]){
			left = mid + 1;
		}//���ֵķ�������
		else if(target < nums[mid]){
			right = mid - 1;
		}
		else{
			if(mid < numsSize - 1 && target == nums[mid + 1]){
				left = mid + 1;
			}//���target��nums[mid]ǰ��һ����Ҳ���
			else{
				ret[1] = mid;
				break;
			}//����ҵ����޸�ret,���˳�ѭ��
		}//����Ҵ�һ������ˣ�Ҫ�����ҳ��߽�
	}//ͬ����һ����Ҫ�ҵ����ұ��Ǹ�
	return ret;
}
int main(){
	int nums[] = {5,7,7,8,8,10};
	int target = 8;
	int returnSize = 0;
	int numsSize = sizeof(nums) / sizeof(int);
	int *ret = searchRange(nums, numsSize, target, &returnSize);
	printf("%d\n", ret[0]);
	printf("%d", ret[1]);
	return 0;
}