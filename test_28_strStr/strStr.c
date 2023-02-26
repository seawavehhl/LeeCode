#include<stdio.h>
#include<string.h>
int strStr(char * haystack, char * needle){
	int i = 0;//定义haystack的下标
	int j = 0;//定义needle的下标
	int len1 = strlen(haystack);
	int len2 = strlen(needle);//定义两个串的长度
	for(i = 0; i < len1; i++){
		for(j = 0; j < len2; j++){
			if(haystack[i+j] == needle[j]){
				if(j == len2 - 1) return i;
			}//如果匹配
			else break;
		}//模式串的遍历
	}//循环遍历寻找子串
	return -1;
}