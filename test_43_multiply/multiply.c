#include<stdio.h>
#include<string.h>

#include<stdio.h>
#include<string.h>
#include<malloc.h>
char * multiply(char * num1, char * num2){
	char *ret = (char*)malloc(sizeof(char) * 1000);//���巵������ĳ�ʼ��С
	int i = 0;//����ѭ������;
	int j = 0;
	int length3 = 0;//���巵�������е��±����
	int k = 0;//��¼��ÿһ�ִ��±�δ���ʼ��������
	int length1 = strlen(num1);//�������������ַ����ĳ���
	int length2 = strlen(num2);
	int next = 0;//������λ��Ϣ
	int num = 0;//������ǰλ�õ����ܺ͵���Ϣ
	for(i = length1 - 1; i >= 0; i--){
		next = 0;//��ʼ����λ��0
		for(j = length2 - 1; j >= 0; j--){
			if(k < length3){
				num = (num1[i] - '0') * (num2[j] - '0') + (ret[k] - '0') + next;
			}//��ȡ��ǰλ����Ҫ��������
			else{
				num = ((num1[i] - '0') * (num2[j] - '0') + next);
				length3++;//��������λ��������Ҫ����
			}
			ret[k++] = (num % 10) + '0';
			next = num / 10;
		}
		if(next != 0){
			ret[length3++] = next + '0';
		}//������н�λ����ֱ�Ӹ�ֵ
		k = length1 - i;	
	}

	for(i = 0; i < length3 / 2; i++){
		num = ret[i];
		ret[i] = ret[length3 - 1 - i];
		ret[length3 - 1 - i] = num;
	}//��β����
	ret[length3] = 0;//ĩβ��0
	if(ret[0] == '0') ret[1] = 0;//�ų�����Ϊ0������˶��0�����
	return ret;
}

int main(){
	char num1[] = "0";
	char num2[] = "33";
	char *ret = multiply(num1, num2);
	puts(ret);
	return 0;
}