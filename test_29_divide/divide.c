#include<stdio.h>
#include<math.h>

int divide(int dividend, int divisor){
	int ret = 0;//返回的结果
	int temp1 = dividend;//被除数临时变量
	int temp2 = divisor;//除数临时变量
	if(dividend == -pow(2,31) && divisor == -1){
		return pow(2,31) - 1;
	}//超出范围
	if(divisor == 1){
		return dividend;
	}
	if(divisor == -1){
		return -dividend;
	}
	if(dividend != -pow(2,31)){
		temp1 = -abs(dividend);	
	}//正负数转换时abs函数会越界，但pow函数不会越界
	if(divisor != -pow(2,31)){
		temp2 = -abs(divisor);		
	}
	while(temp1 <= temp2){
		temp1 -= temp2;
		ret--;
	}//不断相减
	if(dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0){
		return -ret;
	}//符号为正
	else{
		return ret;
	}//符号为负
}
int main(){
	int dividend = -pow(2,31);
	int divisor = 2;
	int ret = divide(dividend, divisor);
	printf("%d", ret);
	return 0;
}
