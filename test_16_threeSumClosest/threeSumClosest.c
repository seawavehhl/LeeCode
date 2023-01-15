#include<stdio.h>
#include<stdlib.h>
int cmp(const void *x, const void * y){
	return *((int *)x) - *((int *)y);
}
int threeSumClosest(int* nums, int numsSize, int target){
	int once = 0;//第一个数
	int left = once + 1;//第二个数
	int right = numsSize - 1;//第三个数
	int ret = nums[0] + nums[1] + nums[2];//返回值
	qsort(nums, numsSize, sizeof(int), cmp);//排序
	for(once = 0; once < numsSize - 2; once++){
		while(once > 0 && once < numsSize - 2 && nums[once] == nums[once-1]){
			once++;//去重
		}//这里检查once-1而不是once+1，不然逻辑不对               -100,-98,-2,-1
		left = once + 1;
		right = numsSize - 1;
		while(left < right){
			if(abs(nums[once] + nums[left] + nums[right] - target) < abs(ret - target)){
				ret = nums[once] + nums[left] + nums[right];//更新返回值
			}
			if(nums[once] + nums[left] + nums[right] > target){
				right--;
			}//如果和比target值大，则right左移
			else if(nums[once] + nums[left] + nums[right] < target){
				left++;
			}//如果和比target小，则left右移
			else return target;
		}
	}//找数
	return ret;
}

int main(){
	int nums[] = {-100,-98,-2,-1};
	int target = -101;
	int ret = threeSumClosest(nums, sizeof(nums)/4, target);
	printf("%d", target);
	return 0;
}