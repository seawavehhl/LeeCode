#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
int **ret = NULL;//要返回的变量
int *Column = NULL;//临时保存放入的数字
int max = 1000;//初始的最大组合数

int cmp(const void *x, const void *y){
	return *((int*)x) - *((int*)y);
}
void DFS(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes, int sum, int ColumnSize, int begin){
	int i = begin;//去重的时候需要用到
	if(sum == target){
		ret[*returnSize] = (int*)malloc(sizeof(int) * ColumnSize);//为需要返回的变量分配子空间
		memcpy(ret[*returnSize], Column, sizeof(int) * ColumnSize);//把临时空间的值赋值过来
		(*returnColumnSizes)[(*returnSize)++] = ColumnSize;//记录每个组合的长度
		return;
	}//找到组合
	for( ; i < candidatesSize; i++){
		if(sum + candidates[i] <= target){
			while(i > begin && i < candidatesSize && candidates[i] == candidates[i - 1]){
				i++;
			}//去重
			if(i == candidatesSize) return;//配合去重操作
			Column[ColumnSize++] = candidates[i];//记录当前的数字
			sum += candidates[i];//累加
			DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, sum, ColumnSize, i + 1);//1,1,2,5,6,7,10
			sum -= candidates[i];//还原
			ColumnSize--;
		}//如果大于，则之后也必定大于
	}

}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	ret = (int**)malloc(sizeof(int*) * max);//分配数组名空间
	Column = (int*)malloc(sizeof(int) * 1000);//分配临时变量的空间
	*returnSize = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * max);//分配最大的空间
	qsort(candidates, candidatesSize, sizeof(int), cmp);//先排序
	DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, 0, 0, 0);
	return ret;
}

int main(){
	int candidates[] = {1,1};
	int target = 1;
	int candidatesSize = sizeof(candidates) / sizeof(int);
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	int i = 0;
	int j = 0;
	int **ret = combinationSum2(candidates, candidatesSize, target, &returnSize, &returnColumnSizes);
	for( ; i < returnSize; i++){
		for( ; j < returnColumnSizes[i]; j++){
			printf("%d ", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}