#include<stdio.h>
int maxArea(int height[], int heightSize){
	int head = 0;
	int rear = heightSize - 1;//head��rear��ʼ�ֱ�ָ�������ͷ��β
	int max = 0;//��ʼ���������Ϊ0;
	int height1 = head;
	int height2 = rear;//��¼��ǰ���������heightֵ
	int num = 0;
	while(rear > head){
		num = height[rear] < height[head] ? height[rear] : height[head];//[2,3,4,5,18,17,6]
		if(num * (rear - head) > max){
			max = num * (rear - head);//ͨ����������������
			height1 = head;
			height2 = rear;//���max���£���Ӧ�߶ȵļ�¼ҲҪ����
		}
		if(height[head] < height[rear]){
			while(rear > head && height[++head] <= height[height1]) ;//�����ҵ���һ������ԭ����¼��ֵ
		}//ȡ�����߽϶̵��Ǹ����ҵ���һ��������ı߽��м���
		else{
			while(rear > head && height[--rear] <= height[height2]) ;//����Ѱ�ҵ�һ������ԭ����¼��ֵ
		}
	}//���������м����
	return max;
}
int main(){
	int height[] = {2,3,4,5,18,17,6};
	int max = maxArea(height, sizeof(height)/4);
	printf("%d", max);
	return 0;
}