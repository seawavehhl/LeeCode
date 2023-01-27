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
}stack;//����ջ�ṹ
 
stack creatstack(){
	stack st;
	st.length = 0;
	st.max = 5000;
	st.nums = (int *)malloc(sizeof(int) * st.max);
	return st;
}//����ջ

int pop(stack *st, int *e){
	if((*st).length != 0){
		*e = (*st).nums[--(*st).length];
		return true;
	}//���ջ�ǿ�
	else return false;
}//��ջ����

void push(stack *st, int e){
	if((*st).length != (*st).max){
		(*st).nums[(*st).length++] = e;
	}//���ջ����
	else{
		(*st).max += 5000;
		(*st).nums = (int *)realloc((*st).nums, sizeof(int) * (*st).max);
		(*st).nums[(*st).length++] = e;
	}//���ջ����������
}//��ջ����

bool isValid(char * s){
	stack st = creatstack();
	int i = 0;//s��ѭ������
	int len = strlen(s);
	int e;//���մ�ջ�е���������
	for(i = 0; i < len; i++){
		if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
			push(&st, s[i]);//��ջ
		}
		else{
			if(!pop(&st, &e) || (e == '(' && s[i] != ')') || (e == '[' && s[i] != ']') || (e == '{' && s[i] !='}')) return false;//����ջ�ջ��߲�ƥ���򷵻�false
		}
	}
	if(st.length == 0) return true;//ջ�գ�����true
	else return false;//��������δƥ�䣬����false
}