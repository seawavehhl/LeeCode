#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *chars[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int digits_size;//数字长度
int *return_size;//返回的字符串数量
char *combination;//暂存一个组合的数组
char **combinations;//最后保存所有返回字符的变量
char *temp_digits;//用来保存输入的全局变量

void backtrack(int combination_size){
	int i = 0;//每个数字对应字符的指针变量
	int len;//每个数字对应字符串的长度
	int num;//每个数字对应字符串字符指针
	if(combination_size == digits_size){
		combinations[*return_size] = (char *)malloc(digits_size + 1);//为其中一个字符串指针开辟空间
		strcpy(combinations[(*return_size)++], combination);//将得到的临时字符组合复制到目的空间中
	}//所有数字都已添加了一个字符，得到一个字符串
	else{
		len = strlen(chars[temp_digits[combination_size] - '0' - 1]);
		for(i = 0; i < len; i++){
			num = temp_digits[combination_size] - '0' - 1;
			combination[combination_size++] = chars[num][i];
			combination[combination_size] = 0;//添加字符后下一个添加0
			backtrack(combination_size);//回溯
			--combination_size;//变量回到该层
		}//每个字符进行组合
	}//如果还有字符没有添加，则继续添加
}
char ** letterCombinations(char * digits, int* returnSize){
	int combinations_size = 1;
	int i = 0;//循环变量
	temp_digits = digits;//赋值给全局变量
	digits_size = strlen(digits);
	*returnSize = 0;
	return_size = returnSize;
	if(digits_size == 0){
		return NULL;
	}//如果数字为空，直接返回空指针
	for(i = 0; i < digits_size; i++){
		combinations_size *= 4;
	}//最后有多少个组合
	combination = (char *)malloc(sizeof(char) * digits_size + 1);//开辟临时字符串的空间
	combinations = (char **)malloc(combinations_size * sizeof(char*));//开辟字符串数组的指针空间
	//力扣上char*为8个字节，所以之前直接写乘4时一直报错
	backtrack(0);
	return combinations;
}

int main(){
	char digits[] = "23456789";
	int returnSize = 0;
	char ** ret = letterCombinations(digits, &returnSize);
	int i = 0;
	while(i < returnSize){
		puts(ret[i]);
		i++;
	}
	printf("%d", returnSize);
	return 0;
}