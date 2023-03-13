int trap(int* height, int heightSize){
	int i = 0;
	int j = heightSize - 1;//首位指针
	int sum = 0;//要返回的值
	int min = 0;//记录下首位的最小值
	while(i < j){
		if(height[i] < height[j]){
			min = height[i];
			while(i < j && height[i] <= min){
				sum += min - height[i];
				i++;
			}//不断累加
		}//找到首尾中的最低值，并从此处遍历
		else{
			min = height[j];
			while(i < j && height[j] <= min){
				sum += min - height[j];
				j--;
			}//不断累加
		}
	}//开始遍历
	return sum;
}