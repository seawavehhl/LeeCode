#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int cmp(const void *x, const void *y){
	return *((int *)x) - *((int *)y);
}//比较函数

int** fourSum(int* nums, int numsSize, _int64 target, int* returnSize, int** returnColumnSizes){
	int once = 0;//第一个数的指针
	int twice = 1;//第二个数的指针
	int left = 2;//第三个数的指针
	int right = numsSize - 1;//第四个数的指针
	_int64 temp = 0;//保存和的临时变量
	int length = 1000;//初始数组数量
	int **ret = (int **)malloc(sizeof(int *) * length);
	*returnSize = 0;//赋初值
	*returnColumnSizes = (int *)malloc(sizeof(int) * length);
	qsort(nums, numsSize, sizeof(int), cmp);//先排序
	for(once = 0; once < numsSize - 3; once++){
		while(once > 0 && once < numsSize - 3 && nums[once] == nums[once-1]) once++;//第一层循环去重
		for(twice = once + 1; twice < numsSize - 2; twice++){
			while(twice > once + 1 && twice < numsSize - 2 && nums[twice] == nums[twice-1]) twice++;//第二层循环去重
			left = twice + 1;
			right = numsSize - 1;
			while(left < right){
				temp = (_int64)nums[once] + (_int64)nums[twice] + (_int64)nums[left] + (_int64)nums[right];
				if(temp == (_int64)target){
					if(*returnSize < length){
						(*returnColumnSizes)[*returnSize] = 4;//更新每个组合包含的数的个数   -2,-1,0,0,1,2
						ret[*returnSize] = (int *)malloc(sizeof(int) * 4);
						ret[*returnSize][0] = nums[once];
						ret[*returnSize][1] = nums[twice];
						ret[*returnSize][2] = nums[left];
						ret[(*returnSize)++][3] = nums[right];
					}//如果ret还没满，继续添加结果
					else{
						length += 1000;
						ret = (int **)realloc(ret,sizeof(int *) * length);
						*returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * length);
						(*returnColumnSizes)[*returnSize] = 4;
						ret[*returnSize][0] = nums[once];
						ret[*returnSize][1] = nums[twice];
						ret[*returnSize][2] = nums[left];
						ret[(*returnSize)++][3] = nums[right];
					}//如果已装满，则扩容
					left++;
					right--;
					while(left  < right && nums[left] == nums[left-1]) left++;//右移去重    -2,-1,0,0,1,2
					while(right > left && nums[right] == nums[right+1]) right--;//左移去重
				}//四个数符合
				else if(temp < (_int64)target){
					left++;
					while(left < right && nums[left] == nums[left-1]) left++;//右移去重
				}//temp小于目标，将left右移
				else{
					right--;
					while(right > left && nums[right] == nums[right+1]) right--;//左移去重     -2,-1,0,0,1,2
				}//temp大于目标，right左移
			}//left和right向中间靠拢
		}
	}//找数
	return ret;
}//vc++编译器没有long long，用_int64,而力扣中不能用_int64

int main(){
	int nums[] = {1000000000,1000000000,1000000000,1000000000};
	int numsSize = sizeof(nums) / 4;
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	_int64 target = 4000000000;
	int **ret = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);
	int i = 0;
	for(i = 0; i < returnSize; i++){
		printf("%d  ", ret[i][0]);
		printf("%d  ", ret[i][1]);
		printf("%d  ", ret[i][2]);
		printf("%d\n", ret[i][3]);
	}
	printf("%d", sizeof(_int64));
	return 0;
}
