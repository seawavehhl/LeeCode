#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b){
	return *(int*)a - *(int*)b;
}
void nextPermutation(int* nums, int numsSize){
	int i = numsSize;//ѭ�������������
	int j = 0;//�ҵ��ĵ�һ����Ϊ�������
	int temp = 0;//���ڽ���ʹ��
	for(i = numsSize - 1; i > 0; ){
		if(nums[i] <= nums[i-1]) i--;//���㣬��������
		else{
			j = i - 1;//��¼�²�����������±�
			break;//����ѭ��
		}//������
	}//����������飬ֱ���ҵ���һ����Ϊ�ݼ�����
	for(i = numsSize - 1; i > 0; ){
		if(nums[i] <= nums[j]) i--;
		else break;
	}//�ٴα������飬�ҵ���һ������nums[j]����
	if(i != 0){
		temp = nums[j];
		nums[j] = nums[i];
		nums[i] = temp;
		qsort(nums + j + 1, numsSize - 1 - j, sizeof(int), cmp);
	}//�����Ϊ����������飬���ҵ������������н���,�������������
	else{
		for(i = 0, j = numsSize - 1; i < j; i++, j--){
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}//���������������򣬵õ����Ľ��
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
