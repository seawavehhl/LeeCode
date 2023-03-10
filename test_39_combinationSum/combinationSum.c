#include<stdio.h>
#include<malloc.h>
#include<string.h>
int max = 1001;//ÿ����ϵ����Ԫ����
int *Column = NULL;//��ʱ����
int **ret = NULL;//Ҫ���ص�ָ��
void DFS(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes, int sum, int ColumnSize, int i){
	if(sum == target){
		ret[(*returnSize)++] = (int *)malloc(sizeof(int) * ColumnSize);
		memcpy(ret[*returnSize - 1], Column, ColumnSize * sizeof(int));
		(*returnColumnSizes)[*returnSize - 1] = ColumnSize;
		return;
	}//����ҵ����
	for(; i < candidatesSize; i++){
		if(sum + candidates[i] <= target){
			Column[ColumnSize++] = candidates[i];
			sum += candidates[i];
			DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, sum, ColumnSize, i);
			sum -= candidates[i];
			ColumnSize--;
		}//������Ѿ�����target������Ч
	}
}
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	int ColumnSize = 0;//�ѷ������ֵĸ���
	int sum = 0;//�ѷ������ֵĺ�
	ret = (int**)malloc(sizeof(int*) * 150);//��Ŀ����Ҫ�����������150��
	*returnSize = 0;//��ʼ��Ϊ0
	*returnColumnSizes = (int*)malloc(sizeof(int*) * 150);//��ĿҪ�����150�����
	max = 1001;//�ٴγ�ʼ��
	Column = (int*)malloc(sizeof(int) * max);//����ʼ��С
	DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, sum, ColumnSize, 0);//����,�����е�i��Ϊ��ȥ��
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