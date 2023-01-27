#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define bool int
#define true 1
#define false 0
typedef struct stack{
	int length;
	int max;
	int *nums;
}stack;//定义栈结构
 
stack creatstack(){
	stack st;
	st.length = 0;
	st.max = 5000;
	st.nums = (int *)malloc(sizeof(int) * st.max);
	return st;
}//创建栈

int pop(stack *st, int *e){
	if((*st).length != 0){
		*e = (*st).nums[--(*st).length];
		return true;
	}//如果栈非空
	else return false;
}//出栈操作

void push(stack *st, int e){
	if((*st).length != (*st).max){
		(*st).nums[(*st).length++] = e;
	}//如果栈不满
	else{
		(*st).max += 5000;
		(*st).nums = (int *)realloc((*st).nums, sizeof(int) * (*st).max);
		(*st).nums[(*st).length++] = e;
	}//如果栈满，则扩容
}//入栈操作

bool isValid(char * s){
	stack st = creatstack();
	int i = 0;//s的循环变量
	int len = strlen(s);
	int e;//接收从栈中弹出的数据
	for(i = 0; i < len; i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			push(&st, s[i]);//入栈
		}
		else{
			if(!pop(&st, &e) || (e == '(' && s[i] != ')') || (e == '[' && s[i] != ']') || (e == '{' && s[i] !='}')) return false;//出现栈空或者不匹配则返回false
		}
	}
	if(st.length == 0) return true;//栈空，返回true
	else return false;//还有括号未匹配，返回false
}