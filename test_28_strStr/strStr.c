#include<stdio.h>
#include<string.h>
int strStr(char * haystack, char * needle){
	int i = 0;//����haystack���±�
	int j = 0;//����needle���±�
	int len1 = strlen(haystack);
	int len2 = strlen(needle);//�����������ĳ���
	for(i = 0; i < len1; i++){
		for(j = 0; j < len2; j++){
			if(haystack[i+j] == needle[j]){
				if(j == len2 - 1) return i;
			}//���ƥ��
			else break;
		}//ģʽ���ı���
	}//ѭ������Ѱ���Ӵ�
	return -1;
}