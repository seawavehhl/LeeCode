#include<stdio.h>
int maxArea(int height[], int heightSize){
	int head = 0;
	int rear = heightSize - 1;//head和rear初始分别指向数组的头和尾
	int max = 0;//初始的最大容量为0;
	int height1 = head;
	int height2 = rear;//记录当前用来计算的height值
	int num = 0;
	while(rear > head){
		num = height[rear] < height[head] ? height[rear] : height[head];//[2,3,4,5,18,17,6]
		if(num * (rear - head) > max){
			max = num * (rear - head);//通过计算更新最大容量
			height1 = head;
			height2 = rear;//如果max更新，相应高度的记录也要更新
		}
		if(height[head] < height[rear]){
			while(rear > head && height[++head] <= height[height1]) ;//向右找到第一个大于原来记录的值
		}//取两条边较短的那个，找到下一个比它打的边进行计算
		else{
			while(rear > head && height[--rear] <= height[height2]) ;//向左寻找第一个大于原来记录的值
		}
	}//从两边向中间计算
	return max;
}
int main(){
	int height[] = {2,3,4,5,18,17,6};
	int max = maxArea(height, sizeof(height)/4);
	printf("%d", max);
	return 0;
}