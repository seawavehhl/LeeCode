#include<stdio.h>
#include<malloc.h>
#include<string.h>
char * countAndSay(int n){
	int max1 = 100;//����last��ʼ���鳤��
	int max2 = 100;//���嵱ǰ�����ʼ����
	char *last = (char*)calloc(max1, sizeof(char));//����������һ������
	char *ret = (char*)calloc(max2, sizeof(char));//�������浱ǰ������
	int len = 1;//����ͳ��ÿһ����ÿ�����ֳ��ֵĴ���
	int length1 = 0;//��¼��һ���ַ�����ĳ���
	int length2 = 0;//��¼��ǰ�ַ�����ĳ���
	int i = 0;//ѭ������
	char num = 0;//ĿǰҪͳ�Ƹ���������
	int j = 0;//ÿһ��ͳ�Ƶ�ѭ������
	ret[0] = '1';
	ret[1] = 0;//����ʼֵ
	if(n == 1) return ret;
	for(i = 1; i < n; i++){
		length2 = strlen(ret);//����Ҫ����last�ַ������еĳ���
		if(length2 >= max1){
			while(length2 >= max1){
				max1 += 200;
			}
			last = (char*)realloc(last, max1);
		}//���̫��������Ҫ��last�������ݣ�����Ҫ�����ַ�����ĩβ0
		strcpy(last, ret);//�ѵ�ǰ�ַ������浽last������
		length1 = length2;
		length2 = 0;
		for(j = 0; j < length1; j++){
			len = 1;//��ÿһ�����ֶ�Ҫ��ʼ��
			num = last[j];
			while(j + 1 < length1 && last[j] == last[j + 1]){
				j++;//��ͬԪ��ȥ��
				len++;
			}
			if(length2 + 2 >= max2){
				while(length2 + 2 >= max2){
					max2 += 200;
				}
				ret = (char*)realloc(ret, max2);
			}//������������Ҫ���ݣ�ÿһ����ӵ����ֿ϶�ֻ����������Ҫ����ĩβ��0
			ret[length2++] = len + '0';
			ret[length2++] = num;
			ret[length2] = 0;
		}//���ͳ��
	}
	return ret;
}

int main(){
	int n = 16;
	char *x = countAndSay(n);
	puts(x);
	printf("%d",strlen(x));
	return 0;

}