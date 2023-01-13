#include<stdio.h>
#include<string.h>
/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
int romanToInt(char * s){
	int nums[] =   {1000, 900, 500,  400, 100,  90,  50,   40,  10,    9,   5,   4,    1};//数字数组
	char *chars[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};//字符数组
	int len = 0;//保存每个罗马字符的长度
	int num = 0;//返回变量
	int i = 0;//字符集的循环变量
	int j = 0;//字符串s的循环变量
	int key = 1;//1代表继续循环检测当前罗马数字
	for(i = 0; i < 13; i++){
		key = 1;//key在循环外置1
		while(key){
			j = 0;//每开始一轮比较,j置零
			len = strlen(chars[i]);//计算当前需要比较罗马字符的长度
			while(len > 0 && s[j] == chars[i][j]){
				len--;
				j++;
			}//比较每个罗马字符
			if(len == 0){
			num += nums[i];//匹配成功
			s = s + strlen(chars[i]);//匹配成功，字符串起始位置向后移动
			key = 1;
			}//如果是一个罗马字符
			else{
				key = 0;
			}
		}//如果字符比较成功，则试图比较s的下一个字符
	}//从大的罗马字符开始转换
	return num;
}
int main(){
	char s[] = "III";
	int num = romanToInt(s);
	printf("%d", num);
	return 0;

}
