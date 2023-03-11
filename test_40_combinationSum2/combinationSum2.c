#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
int **ret = NULL;//Ҫ���صı���
int *Column = NULL;//��ʱ������������
int max = 1000;//��ʼ����������

int cmp(const void *x, const void *y){
	return *((int*)x) - *((int*)y);
}
void DFS(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes, int sum, int ColumnSize, int begin){
	int i = begin;//ȥ�ص�ʱ����Ҫ�õ�
	if(sum == target){
		ret[*returnSize] = (int*)malloc(sizeof(int) * ColumnSize);//Ϊ��Ҫ���صı��������ӿռ�
		memcpy(ret[*returnSize], Column, sizeof(int) * ColumnSize);//����ʱ�ռ��ֵ��ֵ����
		(*returnColumnSizes)[(*returnSize)++] = ColumnSize;//��¼ÿ����ϵĳ���
		return;
	}//�ҵ����
	for( ; i < candidatesSize; i++){
		if(sum + candidates[i] <= target){
			while(i > begin && i < candidatesSize && candidates[i] == candidates[i - 1]){
				i++;
			}//ȥ��
			if(i == candidatesSize) return;//���ȥ�ز���
			Column[ColumnSize++] = candidates[i];//��¼��ǰ������
			sum += candidates[i];//�ۼ�
			DFS(candidates, candidatesSize, target, returnSize, returnColumnSizes, sum, ColumnSize, i + 1);//1,1,2,5,6,7,10
			sum -= candidates[i];//��ԭ
			ColumnSize--;
		}//������ڣ���֮��Ҳ�ض�����
	}

}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
	ret = (int**)malloc(sizeof(int*) * max);//�����������ռ�
	Column = (int*)malloc(sizeof(int) * 1000);//������ʱ�����Ŀռ�
	*returnSize = 0;
	*returnColumnSizes = (int*)malloc(sizeof(int) * max);//�������Ŀռ�
	qsort(candidates, candidatesSize, sizeof(int), cmp);//������
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