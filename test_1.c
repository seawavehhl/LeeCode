#include<stdio.h>
#include<malloc.h>
#include<math.h>
//������
typedef struct hashNode{
	int value;
	int seq;
	int valid;//��Ч���
}hashNode;
//����hash��
typedef struct hashTable{
	hashNode *hash;
	int length;
	int max;
	int p;//����
}hashTable;

int odd(int i){
	int j, k;
	while(i > 0){
		j = i;
		k = i / 2;
		while(k > 1 && j % k != 0 ){
			k--;
		}
		if(k == 1 )
			return j;
		i--;
	}
	return -1;
}//���������
hashTable creatHash(int* nums, int numsSize){
	int i;//����
	int j,k;//��������
	hashTable hash1;//����һ��hash��
	hash1.hash = (hashNode*)malloc(sizeof(hashNode)* 2 * numsSize);
	for(i = 0; i < 2 * numsSize; i++){
		hash1.hash[i].valid = 0;//��Чλ����
	}
	i = odd(2 * numsSize);//�������
	hash1.max = 2 * numsSize;
	hash1.p = i;
	hash1.length = 0;
	for(j = 0; j < numsSize; j++){
		k = abs(nums[j]) % hash1.p;
		while(hash1.hash[k].valid != 0) k = (k + 1) % hash1.max;//����̽�ⷨ
		hash1.hash[k].value = nums[j];
		hash1.hash[k].seq = j;
		hash1.hash[k].valid = 1;
		hash1.length++;
	}
	return hash1;
}//����hash��

int findHash(hashTable hash1, int key){
	int i;
	i = abs(key) % hash1.p;
	while(hash1.hash[i].valid != 0){
		if(hash1.hash[i].value == key) return hash1.hash[i].seq;
		else i = (i + 1) % hash1.max;
	}
	return -1;
}//���ұ�

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int key;//��������Ŀ��ֵ
	int i,j;
	int *output = NULL;
	hashTable hash1 = creatHash(nums,numsSize);
	for(i = 0; i < numsSize; i++){
		key = target - nums[i];
		j = findHash(hash1,key);
		if(j != -1 && j != i){
			*returnSize = 2;
			output = (int *)malloc(sizeof(int) * 2);
			output[0] = i;
			output[1] = j;
			return output;
		}
	}
	return NULL;
}
int main(){
	int nums[] = {-1000,1000,-999,999,1001,
		-1001,-1000,1000,-999,999,1001,-1001,
		2,-1000,1000,-999,999,1001,-1001,-1000,
		1000,-999,999,1001,-1001,5,-1000,1000,-999,999,1001,-1001,-1000,1000,-999,999,1001,-1001};
	int length = sizeof(nums);
	int returnSize;
	int *outPut = twoSum(nums,length,7,&returnSize);
	printf("%d%d",outPut[0],outPut[1]);
	return 0;
}
