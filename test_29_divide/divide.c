#include<stdio.h>
#include<math.h>

int divide(int dividend, int divisor){
	int ret = 0;//���صĽ��
	int temp1 = dividend;//��������ʱ����
	int temp2 = divisor;//������ʱ����
	if(dividend == -pow(2,31) && divisor == -1){
		return pow(2,31) - 1;
	}//������Χ
	if(divisor == 1){
		return dividend;
	}
	if(divisor == -1){
		return -dividend;
	}
	if(dividend != -pow(2,31)){
		temp1 = -abs(dividend);	
	}//������ת��ʱabs������Խ�磬��pow��������Խ��
	if(divisor != -pow(2,31)){
		temp2 = -abs(divisor);		
	}
	while(temp1 <= temp2){
		temp1 -= temp2;
		ret--;
	}//�������
	if(dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0){
		return -ret;
	}//����Ϊ��
	else{
		return ret;
	}//����Ϊ��
}
int main(){
	int dividend = -pow(2,31);
	int divisor = 2;
	int ret = divide(dividend, divisor);
	printf("%d", ret);
	return 0;
}
