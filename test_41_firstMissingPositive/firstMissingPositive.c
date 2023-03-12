#include<math.h>
int firstMissingPositive(int* nums, int numsSize){
	int i = 0;
	for(i = 0; i < numsSize; i++){
		if(nums[i] <= 0){
			nums[i] = numsSize + 1;
		}
	}//第一次遍历数组，将非正数改为n+1
	for(i = 0; i < numsSize; i++){
		if(abs(nums[i]) <= numsSize && abs(nums[i]) >= 1){
			nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
		}//如果在1-n的范围内，在该索引位置标记为负数
	}//第二次遍历，建表
	for(i = 0; i < numsSize; i++){
		if(nums[i] > 0){
			return i + 1;
		}//返回第一个不为-1的下标
	}//第三次遍历，检查第一个不为-1的数所对应的下标+1
	return numsSize + 1;
}