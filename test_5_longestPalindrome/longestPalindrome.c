#include<stdio.h>
#include<string.h>
#include<malloc.h>
char * longestPalindrome(char * s){
	int i = 0, j = 0;//循环变量
	int k;//循环检查的子串长度，从短到长检查是否是回文串
	int len = strlen(s);//字符串长度
	char dp[1000][1000] = {0};//标记数组
	int maxlen = 0;//记录最大长度
	char *ret = NULL;
	for(i = 0; i < len; i++){
		dp[i][i] = 1;//单个字符是回文串
		if(i < len - 1 && s[i] == s[i+1]){
			dp[i][i+1] = 1;//两个相同字符也是回文串
		}
	}//初始化dp数组
	for(k = 3; k <= len; k++){
		for(i = 0, j = i + k - 1; i < len - 1 && j < len; i++,j++){
			if(dp[i+1][j-1] && s[i] == s[j]) dp[i][j] = 1;//如果s[i]~s[j]是回文串并且s[i-1] == s[j+1],则更新dp
		}//判断所有长度为k+1的子串
	}//依步长k遍历
	for(i = 0; i < len; i++){
		for(j = i; j < len; j++){
			if(dp[i][j] == 1 && maxlen < j - i + 1){
				maxlen = j - i + 1;
				k = i;//这里重复使用上面的k,也可以重新定义一个变量
			}
		}
	}//遍历dp，找到最大回文串长度
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