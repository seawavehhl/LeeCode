#include<stdio.h>
#include<stdlib.h>
int cmp(const void *x, const void * y){
	return *((int *)x) - *((int *)y);
}
int threeSumClosest(int* nums, int numsSize, int target){
	int once = 0;//��һ����
	int left = once + 1;//�ڶ�����
	int right = numsSize - 1;//��������
	int ret = nums[0] + nums[1] + nums[2];//����ֵ
	qsort(nums, numsSize, sizeof(int), cmp);//����
	for(once = 0; once < numsSize - 2; once++){
		while(once > 0 && once < numsSize - 2 && nums[once] == nums[once-1]){
			once++;//ȥ��
		}//������once-1������once+1����Ȼ�߼�����               -100,-98,-2,-1
		left = once + 1;
		right = numsSize - 1;
		while(left < right){
			if(abs(nums[once] + nums[left] + nums[right] - target) < abs(ret - target)){
				ret = nums[once] + nums[left] + nums[right];//���·���ֵ
			}
			if(nums[once] + nums[left] + nums[right] > target){
				right--;
			}//����ͱ�targetֵ����right����
			else if(nums[once] + nums[left] + nums[right] < target){
				left++;
			}//����ͱ�targetС����left����
			else return target;
		}
	}//����
	return ret;
}

int main(){
	int nums[] = {-100,-98,-2,-1};
	int target = -101;
	int ret = threeSumClosest(nums, sizeof(nums)/4, target);
	printf("%d", target);
	return 0;
}