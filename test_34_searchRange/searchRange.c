#include<stdio.h>
#include<malloc.h>
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *ret = (int*)malloc(sizeof(int) * 2);//要返回的数组
	int left = 0;
	int right = numsSize - 1;
	int mid = 0;
	ret[0] = ret[1] = -1;//赋初值
	*returnSize = 2;
	while(left <= right){
		mid = (left + right) / 2;
		if(target > nums[mid]){
			left = mid + 1;
		}//二分的分类讨论
		else if(target < nums[mid]){
			right = mid - 1;
		}
		else{
			if(mid > 0 && target == nums[mid - 1]){
				right = mid - 1;
			}//如果target和nums[mid]前面一个数也相等
			else{
				ret[0] = mid;
				break;
			}//如果找到，修改ret,并退出循环
		}//如果找打一个相等了，要继续找出边界
	}//最外层的循环
	left = 0;
	right = numsSize - 1;
	while(left <= right){
		mid = (left + right) / 2;
		if(target > nums[mid]){
			left = mid + 1;
		}//二分的分类讨论
		else if(target < nums[mid]){
			right = mid - 1;
		}
		else{
			if(mid < numsSize - 1 && target == nums[mid + 1]){
				left = mid + 1;
			}//如果target和nums[mid]前面一个数也相等
			else{
				ret[1] = mid;
				break;
			}//如果找到，修改ret,并退出循环
		}//如果找打一个相等了，要继续找出边界
	}//同上面一样，要找到最右边那个
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