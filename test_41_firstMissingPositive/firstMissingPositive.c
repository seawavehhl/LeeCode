#include<math.h>
int firstMissingPositive(int* nums, int numsSize){
	int i = 0;
	for(i = 0; i < numsSize; i++){
		if(nums[i] <= 0){
			nums[i] = numsSize + 1;
		}
	}//��һ�α������飬����������Ϊn+1
	for(i = 0; i < numsSize; i++){
		if(abs(nums[i]) <= numsSize && abs(nums[i]) >= 1){
			nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
		}//�����1-n�ķ�Χ�ڣ��ڸ�����λ�ñ��Ϊ����
	}//�ڶ��α���������
	for(i = 0; i < numsSize; i++){
		if(nums[i] > 0){
			return i + 1;
		}//���ص�һ����Ϊ-1���±�
	}//�����α���������һ����Ϊ-1��������Ӧ���±�+1
	return numsSize + 1;
}