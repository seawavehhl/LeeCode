#include<stdio.h>
#include<string.h>

#include<stdio.h>
#include<string.h>
#include<malloc.h>
char * multiply(char * num1, char * num2){
	char *ret = (char*)malloc(sizeof(char) * 1000);//定义返回数组的初始大小
	int i = 0;//定义循环变量;
	int j = 0;
	int length3 = 0;//定义返回数组中的下标变量
	int k = 0;//记录了每一轮从下标何处开始填入数字
	int length1 = strlen(num1);//计算两个输入字符串的长度
	int length2 = strlen(num2);
	int next = 0;//保留进位信息
	int num = 0;//保留当前位得到的总和的信息
	for(i = length1 - 1; i >= 0; i--){
		next = 0;//初始，进位置0
		for(j = length2 - 1; j >= 0; j--){
			if(k < length3){
				num = (num1[i] - '0') * (num2[j] - '0') + (ret[k] - '0') + next;
			}//获取当前位，需要分类讨论
			else{
				num = ((num1[i] - '0') * (num2[j] - '0') + next);
				length3++;//超出已有位数，长度要增加
			}
			ret[k++] = (num % 10) + '0';
			next = num / 10;
		}
		if(next != 0){
			ret[length3++] = next + '0';
		}//如果还有进位，则直接赋值
		k = length1 - i;	
	}

	for(i = 0; i < length3 / 2; i++){
		num = ret[i];
		ret[i] = ret[length3 - 1 - i];
		ret[length3 - 1 - i] = num;
	}//首尾交换
	ret[length3] = 0;//末尾置0
	if(ret[0] == '0') ret[1] = 0;//排除乘数为0，输出了多个0的情况
	return ret;
}

int main(){
	char num1[] = "0";
	char num2[] = "33";
	char *ret = multiply(num1, num2);
	puts(ret);
	return 0;
}