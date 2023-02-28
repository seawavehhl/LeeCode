#include<stdio.h>
#include<malloc.h>
#include<string.h>
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
	int max = 100;//返回数组最大长度的初始值
	int *ret = (int*)malloc(sizeof(int) * max);//为返回数组开辟内存空间
	int i = 0;//s中的循环变量
	int j = 0;//每一轮中的循环变量
	int k = 0;//words的循环变量
	int length = strlen(words[0]);//words中每个单词的长度
	char *tag = (char*)calloc(wordsSize, sizeof(char));//用来标记每一轮查找中words中的子串是否用过
	*returnSize = 0;
	for(i = 0; i + wordsSize * length - 1 < (int)strlen(s); i++){
		memset(tag, 1, wordsSize);//将标记置1
		for(j = 0; j < wordsSize * length; j += length){
			k = 0;
			while(k < wordsSize){
				if(tag[k] == 1 && strncmp(s + i + j, words[k], length) == 0){
					tag[k] = 0;
					break;//成功在words中找到
				}
				else{
					k++;
				}
			}//遍历比较words中的子串
			if(k == wordsSize){
				break;
			}//此时说明在words中找不到对应的子串，跳出循环
		}//每次移动一个长度子串,每一次比较s中的子串时，都要遍历words中的单词，需要将k置为0
		if(j == wordsSize * length){
			if(*returnSize > max){
				max += 200;
				ret = (int*)realloc(ret, max);
			}
			ret[(*returnSize)++] = i;
		}//如果全部找到
	}//每次往后移动一个子串的长度
	return ret;
}

int main(){
	char s[] ="lingmindraboofooowingdingbarrwingmonkeypoundcake";
	char *words[] = {"fooo","barr","wing","ding","wing"};
	int returnSize = 0;
	int wordsSize = sizeof(words) / sizeof(words[0]);
	int *ret = NULL;
	int i = 0;
	ret = findSubstring(s, words, wordsSize, &returnSize);
	for(i = 0; i < returnSize; i++){
	 printf("%d\n", ret[i]);
	}
	return 0;
}