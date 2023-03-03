#include<stdio.h>
int search(int* nums, int numsSize, int target){
	int left = 0;
	int right = numsSize - 1;
	int mid = 0;
	while(left <= right){
		mid = (left + right) / 2;
		if(nums[mid] >= nums[0]){
			if(target > nums[mid]){
				left = mid + 1;
			}
			else if(target < nums[mid]){
				if(target >= nums[0]){
					right = mid - 1;
				}//需要再次分类
				else{
					left = mid + 1;
				}
			}
			else return mid;
		}//分类讨论，先讨论nums[mid]的定位
		else{
			if(target > nums[mid]){
				if(target >= nums[0]){
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}//此时还要再分，有可能越过最后一个到第一个了
			else if(target < nums[mid]){
				right = mid - 1;
			}
			else return mid;
		}
	}//二分
	return -1;
}
int main(){
	int nums[] = {4,5,6,7,0,1,2};
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int target = 0;
	int k = search(nums, numsSize, target);
	printf("%d", k);
	return 0;
}