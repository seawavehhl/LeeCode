#include<limits.h>
int myAtoi(char * s){
	int i = 0;//ѭ������
	int x = 0;//ת���������
	int op = 0;//�������
	int temp = 0;//�����ݴ�ÿһ��Ҫ����ȥ����
	int label = 0;//�����־
	while(s[i] == ' ') i++;
	if(s[i] == '-'){
		op = 1;
		i++;
	}
	else if(s[i] == '+') i++;//�ж�����
	while(s[i] >= '0' && s[i] <= '9'){
		temp = (0 - (s[i] - '0'));
		if((op && INT_MIN - temp <= x) || (!op && -INT_MAX - temp <= x)){
		x += temp;//���û���������ķ�Χ�������
		i++;
		}
		else{
			label = 1;//���
			break;
		}
		if(s[i] >= '0' && s[i] <= '9'){
			if((op && INT_MIN / 10 <= x) || (!op && -INT_MAX /10 <= x )) x *= 10;
			else{
				label = 1;//���
				break;
			}
		}
	}//��������֣������ת��
	if(op){
		if(!label) return x;
		else return INT_MIN;
	}
	else{
		if(!label) return -x;
		else return INT_MAX;
	}
}