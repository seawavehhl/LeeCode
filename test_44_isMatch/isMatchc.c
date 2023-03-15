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
	char dp[length1 + 1][length2 + 1];//动态规划标记数组，在力扣中可以用变量定义数组，但此时不能初始化，不过在我的编译器里不可以用变量定义
    memset(dp, 0, sizeof(char) * (length1 + 1) * (length2 + 1));
	dp[0][0] = true;
	for(j = 0; j < length2; j++){
		if(p[j] == '*') dp[0][j + 1] = true;
		else break;
	}//边界条件
	for(i = 0; i < length1; i++){
		for(j = 0; j < length2; j++){
			if(p[j] == '*'){//dp中i+1对应s中的i
				dp[i + 1][j + 1] = (dp[i][j + 1] == true || dp[i + 1][j] == true);
			}//不需要考虑s[i]的情况
			else if(p[j] == '?' || s[i] == p[j]){
				dp[i + 1][j + 1] = dp[i][j];
			}//需要考虑s[i]的情况
		}
	}//遍历所有字符
	return dp[length1][length2];
}
int main(){
	char s[] = "aa";
	char p[] = "*a*b";
	int ret = isMatch(s, p);
	printf("%d", ret);
	return 0;
}

