#include<stdio.h>
#include<string.h>
/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
int romanToInt(char * s){
	int nums[] =   {1000, 900, 500,  400, 100,  90,  50,   40,  10,    9,   5,   4,    1};//��������
	char *chars[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};//�ַ�����
	int len = 0;//����ÿ�������ַ��ĳ���
	int num = 0;//���ر���
	int i = 0;//�ַ�����ѭ������
	int j = 0;//�ַ���s��ѭ������
	int key = 1;//1�������ѭ����⵱ǰ��������
	for(i = 0; i < 13; i++){
		key = 1;//key��ѭ������1
		while(key){
			j = 0;//ÿ��ʼһ�ֱȽ�,j����
			len = strlen(chars[i]);//���㵱ǰ��Ҫ�Ƚ������ַ��ĳ���
			while(len > 0 && s[j] == chars[i][j]){
				len--;
				j++;
			}//�Ƚ�ÿ�������ַ�
			if(len == 0){
			num += nums[i];//ƥ��ɹ�
			s = s + strlen(chars[i]);//ƥ��ɹ����ַ�����ʼλ������ƶ�
			key = 1;
			}//�����һ�������ַ�
			else{
				key = 0;
			}
		}//����ַ��Ƚϳɹ�������ͼ�Ƚ�s����һ���ַ�
	}//�Ӵ�������ַ���ʼת��
	return num;
}
int main(){
	char s[] = "III";
	int num = romanToInt(s);
	printf("%d", num);
	return 0;

}
