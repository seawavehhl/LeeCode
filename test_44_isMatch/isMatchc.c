#include<stdio.h>
#include<string.h>
#define bool int
#define true 1
#define false 0

bool isMatch(char * s, char * p){
	int length1 = strlen(s);
	int length2 = strlen(p);
	int i = 0;
	int j = 0;
	char dp[length1 + 1][length2 + 1];//��̬�滮������飬�������п����ñ����������飬����ʱ���ܳ�ʼ�����������ҵı������ﲻ�����ñ�������
    memset(dp, 0, sizeof(char) * (length1 + 1) * (length2 + 1));
	dp[0][0] = true;
	for(j = 0; j < length2; j++){
		if(p[j] == '*') dp[0][j + 1] = true;
		else break;
	}//�߽�����
	for(i = 0; i < length1; i++){
		for(j = 0; j < length2; j++){
			if(p[j] == '*'){//dp��i+1��Ӧs�е�i
				dp[i + 1][j + 1] = (dp[i][j + 1] == true || dp[i + 1][j] == true);
			}//����Ҫ����s[i]�����
			else if(p[j] == '?' || s[i] == p[j]){
				dp[i + 1][j + 1] = dp[i][j];
			}//��Ҫ����s[i]�����
		}
	}//���������ַ�
	return dp[length1][length2];
}
int main(){
	char s[] = "aa";
	char p[] = "*a*b";
	int ret = isMatch(s, p);
	printf("%d", ret);
	return 0;
}

