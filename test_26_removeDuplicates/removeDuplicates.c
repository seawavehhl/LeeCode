int removeDuplicates(int* nums, int numsSize){
	int delsize = 0;//ɾ����Ԫ�ظ���
	int i = 0;//����ѭ������
	for(i = 1; i < numsSize; i++){
		if(nums[i] == nums[i-1]){
			delsize++;
		}//������ظ�Ԫ�أ����ƶ�������1
		nums[i - delsize] = nums[i];
	}
	return numsSize - delsize;
}