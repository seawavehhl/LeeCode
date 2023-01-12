#include<stdio.h>
#include<string.h>
#include<malloc.h>
/*����ת��
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
char * intToRoman(int num){
	int nums[] =  {1000, 900, 500,  400,  100,  90,  50,   40,  10,    9,   5,   4,    1};//��������ַ�һһ��Ӧ
	char *chars[] = {"M", "CM", "D", "CD",  "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};//��������������ֵ;
	char *ret = (char *)calloc(40, 1);//�����ַ���ָ��
	int i = 0;//ѭ������
	for(i = 0; i < 13; i++){
		while(num - nums[i] >= 0){
			num = num - nums[i];
			strncat(ret, chars[i], 2);
		}//�Ӹ�λ���λת��
	}//�Ը����ַ����ν���ת��
	return ret;
}
int main(){
	int num = 900;
	char *ret = intToRoman(num);
	puts(ret);
	return 0;
}