#include<stdio.h>
#include<malloc.h>
#include<string.h>
char * countAndSay(int n){
	int max1 = 100;//定义last初始数组长度
	int max2 = 100;//定义当前数组初始长度
	char *last = (char*)calloc(max1, sizeof(char));//用来保存上一个序列
	char *ret = (char*)calloc(max2, sizeof(char));//用来保存当前的序列
	int len = 1;//用来统计每一轮中每个数字出现的次数
	int length1 = 0;//记录上一个字符数组的长度
	int length2 = 0;//记录当前字符数组的长度
	int i = 0;//循环变量
	char num = 0;//目前要统计个数的数字
	int j = 0;//每一轮统计的循环变量
	ret[0] = '1';
	ret[1] = 0;//赋初始值
	if(n == 1) return ret;
	for(i = 1; i < n; i++){
		length2 = strlen(ret);//计算要放入last字符数组中的长度
		if(length2 >= max1){
			while(length2 >= max1){
				max1 += 200;
			}
			last = (char*)realloc(last, max1);
		}//如果太长，则需要对last进行扩容，这里要考虑字符串的末尾0
		strcpy(last, ret);//把当前字符串保存到last数组中
		length1 = length2;
		length2 = 0;
		for(j = 0; j < length1; j++){
			len = 1;//对每一个数字都要初始化
			num = last[j];
			while(j + 1 < length1 && last[j] == last[j + 1]){
				j++;//相同元素去重
				len++;
			}
			if(length2 + 2 >= max2){
				while(length2 + 2 >= max2){
					max2 += 200;
				}
				ret = (char*)realloc(ret, max2);
			}//如果数组溢出，要扩容，每一次添加的数字肯定只是两个，还要考虑末尾的0
			ret[length2++] = len + '0';
			ret[length2++] = num;
			ret[length2] = 0;
		}//逐个统计
	}
	return ret;
}

int main(){
	int n = 16;
	char *x = countAndSay(n);
	puts(x);
	printf("%d",strlen(x));
	return 0;

}