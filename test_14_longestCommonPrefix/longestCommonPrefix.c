#include<stdio.h>
#include<string.h>
#include<malloc.h>
char * longestCommonPrefix(char ** strs, int strsSize){
	int i = 0;//�ַ��������ѭ������
	int j = 0;//ÿ���ַ�����ָ��
	char *ret = (char*)calloc(strlen(strs[0]) + 1, 1);//�����洢��󹫹�ǰ׺���ַ���,����ǰ׺�϶����ڻ��������ַ���
	strcpy(ret, strs[i]);
	while(i < strsSize){
		j = 0;
		while(ret[j] != 0 && ret[j] == strs[i][j]){
			j++;
		}//���̵�ǰ�ǰ׺
		ret[j] = 0;//����ǰ׺
		i++;
	}//��ǰ�濪ʼ�����Ƚ��ַ�����ǰ׺
	return ret;
}
int main(){
	char *strs[] = {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
					"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
	char *ret = longestCommonPrefix(strs, sizeof(strs)/4);
	puts(ret);
	return 0;
}