#include<stdio.h>
#include<string.h>
#include<malloc.h>
/*数字转换
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
char * intToRoman(int num){
	int nums[] =  {1000, 900, 500,  400,  100,  90,  50,   40,  10,    9,   5,   4,    1};//与下面的字符一一对应
	char *chars[] = {"M", "CM", "D", "CD",  "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};//保留除法运算后的值;
	char *ret = (char *)calloc(40, 1);//返回字符串指针
	int i = 0;//循环变量
	for(i = 0; i < 13; i++){
		while(num - nums[i] >= 0){
			num = num - nums[i];
			strncat(ret, chars[i], 2);
		}//从高位向地位转换
	}//对各个字符依次进行转换
	return ret;
}
int main(){
	int num = 900;
	char *ret = intToRoman(num);
	puts(ret);
	return 0;
}