#include<stdio.h>
#include<limits.h>
#define bool int
#define true 1
#define false 0
bool isPalindrome(int x){
	int x1 = x;//临时变量，初值为x;
	int temp = 0;//临时变量，记录每次循环中x1的最低位
	int final = 0;//最终转换后的结果，如果和x相同则返回true;
	if(x < 0) return false;//如果x为负数，则不是回文数
	while(x1){
		temp = x1 % 10;
		if(INT_MAX - temp >= final) final += temp;
		else return false;
		x1 /= 10;
		if(x1 > 0){
			if(INT_MAX / 10 >= final) final *= 10;
			else return false;
		}
	}//逐位转换
	if(final == x) return true;
	else return false;
}
int main(){
	int x = 1001;
	bool y = isPalindrome(x);
	printf("%d", y);
	return 0;
}