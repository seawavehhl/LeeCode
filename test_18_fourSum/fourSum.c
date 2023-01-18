#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int cmp(const void *x, const void *y){
	return *((int *)x) - *((int *)y);
}//�ȽϺ���

int** fourSum(int* nums, int numsSize, _int64 target, int* returnSize, int** returnColumnSizes){
	int once = 0;//��һ������ָ��
	int twice = 1;//�ڶ�������ָ��
	int left = 2;//����������ָ��
	int right = numsSize - 1;//���ĸ�����ָ��
	_int64 temp = 0;//����͵���ʱ����
	int length = 1000;//��ʼ��������
	int **ret = (int **)malloc(sizeof(int *) * length);
	*returnSize = 0;//����ֵ
	*returnColumnSizes = (int *)malloc(sizeof(int) * length);
	qsort(nums, numsSize, sizeof(int), cmp);//������
	for(once = 0; once < numsSize - 3; once++){
		while(once > 0 && once < numsSize - 3 && nums[once] == nums[once-1]) once++;//��һ��ѭ��ȥ��
		for(twice = once + 1; twice < numsSize - 2; twice++){
			while(twice > once + 1 && twice < numsSize - 2 && nums[twice] == nums[twice-1]) twice++;//�ڶ���ѭ��ȥ��
			left = twice + 1;
			right = numsSize - 1;
			while(left < right){
				temp = (_int64)nums[once] + (_int64)nums[twice] + (_int64)nums[left] + (_int64)nums[right];
				if(temp == (_int64)target){
					if(*returnSize < length){
						(*returnColumnSizes)[*returnSize] = 4;//����ÿ����ϰ��������ĸ���   -2,-1,0,0,1,2
						ret[*returnSize] = (int *)malloc(sizeof(int) * 4);
						ret[*returnSize][0] = nums[once];
						ret[*returnSize][1] = nums[twice];
						ret[*returnSize][2] = nums[left];
						ret[(*returnSize)++][3] = nums[right];
					}//���ret��û����������ӽ��
					else{
						length += 1000;
						ret = (int **)realloc(ret,sizeof(int *) * length);
						*returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * length);
						(*returnColumnSizes)[*returnSize] = 4;
						ret[*returnSize][0] = nums[once];
						ret[*returnSize][1] = nums[twice];
						ret[*returnSize][2] = nums[left];
						ret[(*returnSize)++][3] = nums[right];
					}//�����װ����������
					left++;
					right--;
					while(left  < right && nums[left] == nums[left-1]) left++;//����ȥ��    -2,-1,0,0,1,2
					while(right > left && nums[right] == nums[right+1]) right--;//����ȥ��
				}//�ĸ�������
				else if(temp < (_int64)target){
					left++;
					while(left < right && nums[left] == nums[left-1]) left++;//����ȥ��
				}//tempС��Ŀ�꣬��left����
				else{
					right--;
					while(right > left && nums[right] == nums[right+1]) right--;//����ȥ��     -2,-1,0,0,1,2
				}//temp����Ŀ�꣬right����
			}//left��right���м俿£
		}
	}//����
	return ret;
}//vc++������û��long long����_int64,�������в�����_int64

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
