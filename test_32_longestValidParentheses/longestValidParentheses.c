#include<stdio.h>
#include<string.h>
int longestValidParentheses(char * s){
	int length = strlen(s);
	int i = 0;//����s��ѭ������
	int dp[30001] = {0};//��̬�滮�ı�����飬��ֵΪ0,��һ����Ϊ�˷�ֹ����Խ�磬��ʱ�����±������λ����ͬ,��s���±�Ҫ��1
	int max = 0;//��¼��󳤶�
	for(i = 2; i < length + 1; i++){
		if(s[i - 1] == ')' && s[i - 2] == '('){
			dp[i] = dp[i-2] + 2;
		}//���ĩβ��������ƥ��
		else if(s[i - 1] == ')' && s[i - 2] == ')'){
			if(i - 2 - dp[i - 1] >=0 && s[i - 2 - dp[i - 1]] == '('){
				dp[i] = dp[i - 1] + dp[i - 2 - dp[i - 1]] + 2;
			}//���׷�ݵ�ǰ������ź����һ������ƥ��
		}//���ĩβ������Ϊ)��������ǰѰ���Ƿ�ƥ��
		max = dp[i] > max ? dp[i] : max;
	}//��ͷ��ʼ����
	return max;
}

int main(){
	char s[] = ")()())";
	int k = longestValidParentheses(s);
	printf("%d", k);
	return 0;
}