#include<stdio.h>
#include<string.h>
int longestValidParentheses(char * s){
	int length = strlen(s);
	int i = 0;//遍历s的循环变量
	int dp[30001] = {0};//动态规划的标记数组，初值为0,多一个是为了防止数组越界，此时数组下标和括号位序相同,但s的下标要减1
	int max = 0;//记录最大长度
	for(i = 2; i < length + 1; i++){
		if(s[i - 1] == ')' && s[i - 2] == '('){
			dp[i] = dp[i-2] + 2;
		}//如果末尾两个括号匹配
		else if(s[i - 1] == ')' && s[i - 2] == ')'){
			if(i - 2 - dp[i - 1] >=0 && s[i - 2 - dp[i - 1]] == '('){
				dp[i] = dp[i - 1] + dp[i - 2 - dp[i - 1]] + 2;
			}//如果追溯到前面的括号和最后一个括号匹配
		}//如果末尾两个都为)，则往更前寻找是否匹配
		max = dp[i] > max ? dp[i] : max;
	}//从头开始遍历
	return max;
}

int main(){
	char s[] = ")()())";
	int k = longestValidParentheses(s);
	printf("%d", k);
	return 0;
}