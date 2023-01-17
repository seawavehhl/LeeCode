#include<stdio.h>
#include<string.h>
#include<malloc.h>
char *chars[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int digits_size;//���ֳ���
int *return_size;//���ص��ַ�������
char *combination;//�ݴ�һ����ϵ�����
char **combinations;//��󱣴����з����ַ��ı���
char *temp_digits;//�������������ȫ�ֱ���

void backtrack(int combination_size){
	int i = 0;//ÿ�����ֶ�Ӧ�ַ���ָ�����
	int len;//ÿ�����ֶ�Ӧ�ַ����ĳ���
	int num;//ÿ�����ֶ�Ӧ�ַ����ַ�ָ��
	if(combination_size == digits_size){
		combinations[*return_size] = (char *)malloc(digits_size + 1);//Ϊ����һ���ַ���ָ�뿪�ٿռ�
		strcpy(combinations[(*return_size)++], combination);//���õ�����ʱ�ַ���ϸ��Ƶ�Ŀ�Ŀռ���
	}//�������ֶ��������һ���ַ����õ�һ���ַ���
	else{
		len = strlen(chars[temp_digits[combination_size] - '0' - 1]);
		for(i = 0; i < len; i++){
			num = temp_digits[combination_size] - '0' - 1;
			combination[combination_size++] = chars[num][i];
			combination[combination_size] = 0;//����ַ�����һ�����0
			backtrack(combination_size);//����
			--combination_size;//�����ص��ò�
		}//ÿ���ַ��������
	}//��������ַ�û����ӣ���������
}
char ** letterCombinations(char * digits, int* returnSize){
	int combinations_size = 1;
	int i = 0;//ѭ������
	temp_digits = digits;//��ֵ��ȫ�ֱ���
	digits_size = strlen(digits);
	*returnSize = 0;
	return_size = returnSize;
	if(digits_size == 0){
		return NULL;
	}//�������Ϊ�գ�ֱ�ӷ��ؿ�ָ��
	for(i = 0; i < digits_size; i++){
		combinations_size *= 4;
	}//����ж��ٸ����
	combination = (char *)malloc(sizeof(char) * digits_size + 1);//������ʱ�ַ����Ŀռ�
	combinations = (char **)malloc(combinations_size * sizeof(char*));//�����ַ��������ָ��ռ�
	//������char*Ϊ8���ֽڣ�����֮ǰֱ��д��4ʱһֱ����
	backtrack(0);
	return combinations;
}

int main(){
	char digits[] = "23456789";
	int returnSize = 0;
	char ** ret = letterCombinations(digits, &returnSize);
	int i = 0;
	while(i < returnSize){
		puts(ret[i]);
		i++;
	}
	printf("%d", returnSize);
	return 0;
}