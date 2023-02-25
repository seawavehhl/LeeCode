int removeElement(int* nums, int numsSize, int val){
	int delsize = 0;//被删除的元素个数
	int i = 0;//循环变量
	for(i = 0; i < numsSize; i++){
		nums[i-delsize] = nums[i];
		if(nums[i] == val) delsize++;
	}
	return numsSize - delsize;
}