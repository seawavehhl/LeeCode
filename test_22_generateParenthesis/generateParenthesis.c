#include<stdio.h>
#include<malloc.h>
#include<string.h>
int left = 0;//�������������
char **ret;//���ر���
char *temp;//��ʱ����ÿһ������ƥ��Ľ��
int size;//Ҫ���ɵ����Ŷ���
int max = 20;//ret������ʼ��
int sizes;//���е����Ŷ����±�

void backtrack(int num){
	if(num == size * 2){
		if(sizes < max){
			ret[sizes] = (char *)malloc(sizeof(char) * size * 2 + 1);
			strcpy(ret[sizes],temp);
			sizes++;
		}//�����������
		else{
			max += 20;
			ret = (char **)realloc(ret, sizeof(char *) * max);
			ret[sizes] = (char *)malloc(sizeof(char) * size * 2 + 1);
			strcpy(ret[sizes],temp);
			sizes++;
		}//���ݲ����
	}//�ճ�һ��
	else{
		if(left < size){
			temp[num] = '(';
			temp[++num] = 0;
			left++;
			backtrack(num);//����
			num--;
			left--;
		}//�����������Ŀû�����������
		if(num - left < left){
			temp[num] = ')';
			temp[++num] = 0;
			backtrack(num);
			num--;
		}//�����������С�����������������������
	}//�����δ�ճ�һ��
}
char ** generateParenthesis(int n, int* returnSize){
	size = n;
	ret = (char **)malloc(sizeof(char *) * max);
	sizes = *returnSize = 0;
	temp = (char *)malloc(sizeof(char) * size * 2 + 1);
	backtrack(0);//����
	*returnSize = sizes;
	return ret;
}

int main(){
	int n = 14;
	int returnSize = 0;
	char **ret = NULL;
	int i = 0;
	ret = generateParenthesis(n, &returnSize);
	/*while(i < returnSize){
		puts(ret[i]);
		i++;
	}*/
	printf("%d\n", returnSize);
	return 0;
}