#include<stdio.h>
#include<malloc.h>
#include<string.h>
int max = 1001;//每个组合的最大单元个数
int *Column = NULL;//临时变量
int **ret = NULL;//要返回的指针
void DFS(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes, int sum, int ColumnSize, int i){
	if(sum == target){
		ret[(*returnSize)++] = (int *)malloc(sizeof(int) * ColumnSize);
		memcpy(ret[*returnSize - 1], Column, ColumnSize * sizeof(int));
		(*returnColumnSizes)[*returnSize - 1] = ColumnSize;
		return;
	}//如果找到组合
	for(; i < candidatesSize; i++){
		if(sum + candidates[i] <= target){
			Column[ColumnSize++] = candidates[i];
			sum += candidates[i];
			DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, sum, ColumnSize, i);
			sum -= candidates[i];
			ColumnSize--;
		}//如果和已经大于target，则无效
	}
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	int ColumnSize = 0;//已放入数字的个数
	int sum = 0;//已放入数字的和
	ret = (int**)malloc(sizeof(int*) * 150);//题目给出要求组合数少于150个
	*returnSize = 0;//初始化为0
	*returnColumnSizes = (int*)malloc(sizeof(int*) * 150);//题目要求最多150个组合
	max = 1001;//再次初始化
	Column = (int*)malloc(sizeof(int) * max);//赋初始大小
	DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, sum, ColumnSize, 0);//回溯,变量中的i是为了去重
	return ret;
}

int main(){
	int candidates[] = {2, 3, 6, 7};
	int candidatesSize = sizeof(candidates) / sizeof(int);
	int target = 7;
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	int **ret = combinationSum(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);
	return 0;
}