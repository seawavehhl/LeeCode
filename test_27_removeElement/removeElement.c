int removeElement(int* nums, int numsSize, int val){
	int delsize = 0;//��ɾ����Ԫ�ظ���
	int i = 0;//ѭ������
	for(i = 0; i < numsSize; i++){
		nums[i-delsize] = nums[i];
		if(nums[i] == val) delsize++;
	}
	return numsSize - delsize;
}