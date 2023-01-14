#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int cmp(const void *x, const void *y){
	return *((int *)x) - *((int *)y);
}
void mysort(int *nums, int numsSize){
	int i = 0;
	int j = 0;
	int temp;
	for(i = 0; i < numsSize - 1; i++){
		for(j = 0; j < numsSize - 1 - i; j++){
			if(nums[j] > nums[j+1]){
				temp = nums[j];
				nums[j] = nums[j+1];
				nums[j+1] = temp;
			}
		}
	}//冒泡排序
}//排序
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i = 0;
	int j = 1;
	int k = 2;//数组的三个循环变量
	int **ret = (int **)calloc(numsSize * numsSize, 4);//返回指针
	*returnColumnSizes = (int *)calloc(numsSize * numsSize, 4);
	*returnSize = 0;
	qsort(nums, numsSize, sizeof(int), cmp);//先排序
	for(i = 0; i < numsSize - 2 && nums[i] <= 0; i++){
		while(i > 0  && i < numsSize && nums[i] == nums[i-1]){
			i++;
		}//去重操作
		j = i + 1;
		k = numsSize - 1;//后面两个数的初始指针
	
		while(j < k && nums[k] >=0){
			if(nums[i] + nums[j] + nums[k] == 0){
				ret[*returnSize] = (int *)calloc(3,4);
				ret[*returnSize][0] = nums[i];
				ret[*returnSize][1] = nums[j];
				ret[*returnSize][2] = nums[k];
				(*returnColumnSizes)[(*returnSize)++] = 3;
				j++;
				while(j < k && nums[j] == nums[j-1]) j++;//向右去重
				k--;
				while(k > j && nums[k] == nums[k+1] && nums[k] >=0) k--;//向左去重
			}
			else if(nums[i] + nums[j] + nums[k] > 0){
				k--;
				while(k >= 0 && nums[k] == nums[k+1] && nums[k] >=0) k--;//向左去重
			}
			else{
				j++;
				while(j < numsSize && nums[j] == nums[j-1]) j++;//向左去重
			}
		}
	}//找数
	return ret;
}

int main(){
	int nums[] = {82597,-9243,62390,83030,-97960,-26521,-61011,83390,-38677,12333,75987,46091,83794,19355,-71037,-6242,-28801,324,1202,-90885,-2989,-95597,-34333,35528,5680,89093,-90606,50360,-29393,-27012,53313,65213,99818,-82405,-41661,-3333,-51952,72135,-1523,26377,74685,96992,92263,15929,5467,-99555,-43348,-41689,-60383,-3990,
	32165,65265,-72973,-58372,12741,-48568,-46596,72419,-1859,34153,62937,81310,-61823,-96770,-54944,8845,-91184,24208,-29078,31495,65258,14198,85395,70506,-40908,56740,-12228,-40072,32429,93001,68445,-73927,25731,-91859,-24150,10093,-60271,-81683,-18126,51055,48189,-6468,25057,81194,-58628,74042,66158,-14452,
	-49851,-43667,11092,39189,-17025,-79173,13606,83172,92647,-59741,19343,-26644,-57607,82908,-20655,1637,80060,98994,39331,-31274,-61523,91225,-72953,13211,-75116,-98421,-41571,-69074,99587,39345,42151,-2460,98236,15690,-52507,-95803,-48935,-46492,-45606,-79254,-99851,52533,73486,39948,-7240,71815,-585,-96252};
	int numsSize = sizeof(nums)/4;
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	int **ret = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
	int i = 0;
	while(i < returnSize){
		printf("%d ", ret[i][0]);
		printf("%d ", ret[i][1]);
		printf("%d\n", ret[i][2]);
		i++;
	}
	return 0;
}
