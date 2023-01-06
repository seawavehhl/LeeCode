#include<stdio.h>
#include<limits.h>
#include<math.h>
int reverse(int x){
	int i = 0;//控制循环次数
	int temp = 0;//临时变量;
	int ret = 0;//结果
	int op = 0;//表示是整数还是负数
	if(x < 0) op = 1;//标记为负数
	else x = -x;//统一变为负数来计算因为负数范围更大
	while(x < 0){
		temp = x % 10;//取出最低位（负数取模运算结果仍为负数）
		x /= 10;//将x右移一位
		if(INT_MIN - temp <= ret) ret += temp;//如果ret加上temp大于最小整数，则相加,否则返回0
		else return 0;
		if(INT_MIN / 10 <= ret && x < 0) ret *= 10;//如果x还有剩余的位数，且ret乘2后大于超过最小整数，则将ret乘10，进入下一轮循环
		else if(INT_MIN / 10 > ret && x < 0) return 0;//如果x还有剩余位数，且ret乘2超过最大整数，则返回0;
		//除以二运算取整方向为绝对值更小的方向
	}//依次取出各位并计算
	if(op) return ret;
	else{
		if(ret < -INT_MAX) 
			return 0;
		else return 
			-ret;
	}
}
int main(){
	int x = -123;
	int y = reverse(x);
	printf("%d",y);
	return 0;
}