#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring(char * s){
	int strlength = strlen(s);
	int max = 0;//��¼����Ӵ�����
	int length = 0;//��¼��ǰ�Ӵ�����
	int tag[128] = {0};//��¼ÿ���ַ��Ƿ����
	int i = 0, j = 0;//iָ���Ӵ���һ���ַ���jָ���Ӵ����һ���ַ�;
	while(j < strlength){
		if(tag[s[j]] == 0){
			tag[s[j]] = 1;//�ַ�δ���ֹ�������
			length++;
			j++;
			max = max > length ? max : length;//ȡ���ֵ
		}
		else{
			while(s[i] != s[j]){
				tag[s[i]] = 0;//�ַ����ֹ�����ǰ��ı��ȫ����0
				i++;
				length--;//��ǰ�Ӵ��������μ�1
			}
			i++;//���ظ����ַ���һ����ʼ����
			j++;
		}
	}
	return max;
}

int main(){
	char s[] = "abcdddefgg";
	int i = 0;
	printf("%d", lengthOfLongestSubstring(s));
	return 0;
}
