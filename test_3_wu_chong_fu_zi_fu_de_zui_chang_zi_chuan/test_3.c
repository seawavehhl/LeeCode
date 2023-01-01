#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring(char * s){
	int strlength = strlen(s);
	int max = 0;//记录最大子串长度
	int length = 0;//记录当前子串长度
	int tag[128] = {0};//记录每个字符是否出现
	int i = 0, j = 0;//i指向子串第一个字符，j指向子串最后一个字符;
	while(j < strlength){
		if(tag[s[j]] == 0){
			tag[s[j]] = 1;//字符未出现过，则标记
			length++;
			j++;
			max = max > length ? max : length;//取最大值
		}
		else{
			while(s[i] != s[j]){
				tag[s[i]] = 0;//字符出现过，则前面的标记全部置0
				i++;
				length--;//当前子串长度依次减1
			}
			i++;//从重复的字符下一个开始查找
			j++;
		}
	}
	return max;
}

int main(){
	char s[] = "abcdddefgg";
	int i = 0;
	printf("%d", lengthOfLongestSubstring(s));
	return 0;
}
