#include<stdio.h>
#include<string.h>
#define bool int
#define true 1
#define false 0
int match(char a, char b){
	if(a == b || b == '.') return 1;
	return 0;
}//匹配函数
bool isMatch(char * s, char * p){
	int slen = strlen(s);
	int plen = strlen(p);//求出各个字符串长度
	int f[21][31] = {false};//标记数据，f[i][j] == 1表示s中到第i个字符的子串和p中到j个字符的子串匹配
	int i = 0, j = 0;//循环变量
	f[0][0] = true;//空字符串默认匹配，这里数组下标和字符位序相同
	while(i < slen){
		while(j < plen){
			if(p[j] != '*'){
				if(match(s[i], p[j])){
					f[i+1][j+1] = f[i][j];
				}//如果匹配
			}//如果p中要配对的字符是字母或者'.'
			else if(p[j] == '*'){
				if(i == 0) f[i][j+1] = f[i][j-1];//形如aa和a*匹配的情况的一个边界条件
				if(match(s[i], p[j-1])){
					if(f[i][j+1] || f[i+1][j-1]) f[i+1][j+1] = true;//if条件是'*'匹配0个字符或已匹配多个字符的情况
				}//如果'*'前面一个字符和s中的字符匹配
				else{
					f[i+1][j+1] = f[i+1][j-1];
				}//如果'*'前面一个字符和s中的字符不匹配
			}//如果要匹配的字符是'*'
			j++;
		}
		j = 0;
		i++;
	}//匹配过程
	if(f[slen][plen]) return 1;//如果两个字符串匹配
	return 0;//如果不匹配
}

int main(){
	char s[] = "aab";
	char p[] = "c*a*b";
	int ret = isMatch(s, p);
	printf("%d", ret);
	return 0;
}