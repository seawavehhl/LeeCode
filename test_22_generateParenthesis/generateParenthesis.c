#include<stdio.h>
#include<malloc.h>
#include<string.h>
int left = 0;//标记左括号数量
char **ret;//返回变量
char *temp;//临时保存每一次括号匹配的结果
int size;//要生成的括号对数
int max = 20;//ret容量初始化
int sizes;//已有的括号对数下标

void backtrack(int num){
	if(num == size * 2){
		if(sizes < max){
			ret[sizes] = (char *)malloc(sizeof(char) * size * 2 + 1);
			strcpy(ret[sizes],temp);
			sizes++;
		}//如果容量还够
		else{
			max += 20;
			ret = (char **)realloc(ret, sizeof(char *) * max);
			ret[sizes] = (char *)malloc(sizeof(char) * size * 2 + 1);
			strcpy(ret[sizes],temp);
			sizes++;
		}//扩容并添加
	}//凑成一组
	else{
		if(left < size){
			temp[num] = '(';
			temp[++num] = 0;
			left++;
			backtrack(num);//回溯
			num--;
			left--;
		}//如果左括号数目没超过最大限制
		if(num - left < left){
			temp[num] = ')';
			temp[++num] = 0;
			backtrack(num);
			num--;
		}//如果右括号数小于左扩号数，可添加右括号
	}//如果还未凑成一组
}
char ** generateParenthesis(int n, int* returnSize){
	size = n;
	ret = (char **)malloc(sizeof(char *) * max);
	sizes = *returnSize = 0;
	temp = (char *)malloc(sizeof(char) * size * 2 + 1);
	backtrack(0);//回溯
	*returnSize = sizes;
	return ret;
}

int main(){
	int n = 14;
	int returnSize = 0;
	char **ret = NULL;
	int i = 0;
	ret = generateParenthesis(n, &returnSize);
	/*while(i < returnSize){
		puts(ret[i]);
		i++;
	}*/
	printf("%d\n", returnSize);
	return 0;
}