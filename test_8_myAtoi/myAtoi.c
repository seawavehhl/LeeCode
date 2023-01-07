#include<limits.h>
int myAtoi(char * s){
	int i = 0;//循环变量
	int x = 0;//转换后的数字
	int op = 0;//标记正负
	int temp = 0;//用来暂存每一个要加上去的数
	int label = 0;//溢出标志
	while(s[i] == ' ') i++;
	if(s[i] == '-'){
		op = 1;
		i++;
	}
	else if(s[i] == '+') i++;//判定符号
	while(s[i] >= '0' && s[i] <= '9'){
		temp = (0 - (s[i] - '0'));
		if((op && INT_MIN - temp <= x) || (!op && -INT_MAX - temp <= x)){
		x += temp;//如果没超出负数的范围，则相加
		i++;
		}
		else{
			label = 1;//溢出
			break;
		}
		if(s[i] >= '0' && s[i] <= '9'){
			if((op && INT_MIN / 10 <= x) || (!op && -INT_MAX /10 <= x )) x *= 10;
			else{
				label = 1;//溢出
				break;
			}
		}
	}//如果是数字，则进行转换
	if(op){
		if(!label) return x;
		else return INT_MIN;
	}
	else{
		if(!label) return -x;
		else return INT_MAX;
	}
}