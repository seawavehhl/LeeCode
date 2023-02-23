int removeDuplicates(int* nums, int numsSize){
	int delsize = 0;//删除的元素个数
	int i = 0;//数组循环变量
	for(i = 1; i < numsSize; i++){
		if(nums[i] == nums[i-1]){
			delsize++;
		}//如果有重复元素，则移动步数加1
		nums[i - delsize] = nums[i];
	}
	return numsSize - delsize;
}