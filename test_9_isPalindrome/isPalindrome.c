#include<stdio.h>
#include<limits.h>
#define bool int
#define true 1
#define false 0
bool isPalindrome(int x){
	int x1 = x;//��ʱ��������ֵΪx;
	int temp = 0;//��ʱ��������¼ÿ��ѭ����x1�����λ
	int final = 0;//����ת����Ľ���������x��ͬ�򷵻�true;
	if(x < 0) return false;//���xΪ���������ǻ�����
	while(x1){
		temp = x1 % 10;
		if(INT_MAX - temp >= final) final += temp;
		else return false;
		x1 /= 10;
		if(x1 > 0){
			if(INT_MAX / 10 >= final) final *= 10;
			else return false;
		}
	}//��λת��
	if(final == x) return true;
	else return false;
}
int main(){
	int x = 1001;
	bool y = isPalindrome(x);
	printf("%d", y);
	return 0;
}