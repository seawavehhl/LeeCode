#include<stdio.h>
#include<limits.h>
#include<math.h>
int reverse(int x){
	int i = 0;//����ѭ������
	int temp = 0;//��ʱ����;
	int ret = 0;//���
	int op = 0;//��ʾ���������Ǹ���
	if(x < 0) op = 1;//���Ϊ����
	else x = -x;//ͳһ��Ϊ������������Ϊ������Χ����
	while(x < 0){
		temp = x % 10;//ȡ�����λ������ȡģ��������Ϊ������
		x /= 10;//��x����һλ
		if(INT_MIN - temp <= ret) ret += temp;//���ret����temp������С�����������,���򷵻�0
		else return 0;
		if(INT_MIN / 10 <= ret && x < 0) ret *= 10;//���x����ʣ���λ������ret��2����ڳ�����С��������ret��10��������һ��ѭ��
		else if(INT_MIN / 10 > ret && x < 0) return 0;//���x����ʣ��λ������ret��2��������������򷵻�0;
		//���Զ�����ȡ������Ϊ����ֵ��С�ķ���
	}//����ȡ����λ������
	if(op) return ret;
	else{
		if(ret < -INT_MAX) 
			return 0;
		else return 
			-ret;
	}
}
int main(){
	int x = -123;
	int y = reverse(x);
	printf("%d",y);
	return 0;
}