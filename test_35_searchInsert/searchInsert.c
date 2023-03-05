int searchInsert(int* nums, int numsSize, int target){
	int left = 0;
	int right = numsSize - 1;
	int mid = 0;
	while(left <= right){
		mid = (left + right) / 2;
		if(target > nums[mid]){
			left = mid + 1;
		}
		else if(target < nums[mid]){
			right = mid - 1;
		}
		else{
			return mid;
		}
	}//二分查找
	return left;//查找失败，返回left的位置
}