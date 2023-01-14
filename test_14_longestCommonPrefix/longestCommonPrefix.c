#include<stdio.h>
#include<string.h>
#include<malloc.h>
char * longestCommonPrefix(char ** strs, int strsSize){
	int i = 0;//字符串数组的循环变量
	int j = 0;//每个字符串的指针
	char *ret = (char*)calloc(strlen(strs[0]) + 1, 1);//用来存储最大公共前缀的字符串,公共前缀肯定短于或等于最短字符串
	strcpy(ret, strs[i]);
	while(i < strsSize){
		j = 0;
		while(ret[j] != 0 && ret[j] == strs[i][j]){
			j++;
		}//缩短当前最长前缀
		ret[j] = 0;//缩短前缀
		i++;
	}//从前面开始两两比较字符串的前缀
	return ret;
}
int main(){
	char *strs[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
	char *ret = longestCommonPrefix(strs, sizeof(strs)/4);
	puts(ret);
	return 0;
}