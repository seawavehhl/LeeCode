#include<stdio.h>
#include<string.h>
#include<malloc.h>
char * longestPalindrome(char * s){
	int i = 0, j = 0;//ѭ������
	int k;//ѭ�������Ӵ����ȣ��Ӷ̵�������Ƿ��ǻ��Ĵ�
	int len = strlen(s);//�ַ�������
	char dp[1000][1000] = {0};//�������
	int maxlen = 0;//��¼��󳤶�
	char *ret = NULL;
	for(i = 0; i < len; i++){
		dp[i][i] = 1;//�����ַ��ǻ��Ĵ�
		if(i < len - 1 && s[i] == s[i+1]){
			dp[i][i+1] = 1;//������ͬ�ַ�Ҳ�ǻ��Ĵ�
		}
	}//��ʼ��dp����
	for(k = 3; k <= len; k++){
		for(i = 0, j = i + k - 1; i < len - 1 && j < len; i++,j++){
			if(dp[i+1][j-1] && s[i] == s[j]) dp[i][j] = 1;//���s[i]~s[j]�ǻ��Ĵ�����s[i-1] == s[j+1],�����dp
		}//�ж����г���Ϊk+1���Ӵ�
	}//������k����
	for(i = 0; i < len; i++){
		for(j = i; j < len; j++){
			if(dp[i][j] == 1 && maxlen < j - i + 1){
				maxlen = j - i + 1;
				k = i;//�����ظ�ʹ�������k,Ҳ�������¶���һ������
			}
		}
	}//����dp���ҵ������Ĵ�����
	ret = (char *)malloc(maxlen + 1);
	memcpy(ret, s + k, maxlen);
	ret[maxlen] = 0;
	return ret;
}
int main(){
	char s[] = "ccc";
	char *out = NULL;
	out = longestPalindrome(s);
	puts(out);
	return 0;
}