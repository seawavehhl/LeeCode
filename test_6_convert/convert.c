#include<string.h>
#include<stdlib.h>
#include<stdio.h>
char * convert(char * s, int numRows){
	char temp[1001][1001] = {0};//存储每一行的字符
	int i = 0;//行号
	int j = 0;//各行的下标
	int j1 = 0,j2 = 0;//第一行和最后一行的下标单独保存
	int len = strlen(s);
	int n = 1;//用来记录已遍历的字符数
	int key = 1;//key == 0 时，从上往下记录字符，key == 1时，从下往上记录字符
	char * ret = NULL;//返回字符串
	if(numRows == 1) return s;//如果只有一行，直接返回
	for(n = 0; n < len; n++){
		if(i == 0){
			temp[i][j1] = s[n];//第0行单独使用j1为列标
			j1++;
			key = !key;
			if(n != 0) j++;
		}
		else if(i == numRows - 1){
			temp[i][j2] = s[n];//最后一行单独使用j2为列标
			j2++;
			key = !key;
			j++;
		}
		else temp[i][j] = s[n];//j为其它行共有列标
		if(!key){
			i++;
		}
		else{
			i--;
		}
	}
	ret = (char *)malloc(len + 1);
	n = 0;
	for(i = 0; i < numRows; i++){
		j = 0;
		while(temp[i][j] != 0) {
			ret[n] = temp[i][j];
			j++;
			n++;
		}
	}//收集各行
	ret[len] = 0;
	return ret;
}
int main(){
	char s[] = "qwert";
	int numRows = 2;
	char *ret = convert(s, numRows);
	puts(ret);
	return 0;
}