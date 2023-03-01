#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
void nextPermutation(int* nums, int numsSize){
	int i = numsSize;//循环遍历数组变量
	int j = 0;//找到的第一个不为逆序的数
	int temp = 0;//用于交换使用
	for(i = numsSize - 1; i > 0; ){
		if(nums[i] <= nums[i-1]) i--;//满足，继续遍历
		else{
			j = i - 1;//记录下不满足的数字下标
			break;//跳出循环
		}//不满足
	}//逆序遍历数组，直到找到第一个不为递减的数
	for(i = numsSize - 1; i > 0; ){
		if(nums[i] <= nums[j]) i--;
		else break;
	}//再次遍历数组，找到第一个大于nums[j]的数
	if(i != 0){
		temp = nums[j];
		nums[j] = nums[i];
		nums[i] = temp;
		qsort(nums + j + 1, numsSize - 1 - j, sizeof(int), cmp);
	}//如果不为最大逆序数组，则将找到的两个数进行交换,并逆序后续数组
	else{
		for(i = 0, j = numsSize - 1; i < j; i++, j--){
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}//否则将整个数组逆序，得到最后的结果
}

int main(){
	int nums[] = {2,2,7,5,4,3,2,2,1};
	int numsSize = sizeof(nums)/sizeof(int);
	int i = 0;
	nextPermutation(nums, numsSize);
	while(i < numsSize){
		printf("%d\n", nums[i]);
		i++;
	}
	return 0;
}
