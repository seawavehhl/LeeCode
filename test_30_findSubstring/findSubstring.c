#include<stdio.h>
#include<malloc.h>
#include<string.h>
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
	int max = 100;//����������󳤶ȵĳ�ʼֵ
	int *ret = (int*)malloc(sizeof(int) * max);//Ϊ�������鿪���ڴ�ռ�
	int i = 0;//s�е�ѭ������
	int j = 0;//ÿһ���е�ѭ������
	int k = 0;//words��ѭ������
	int length = strlen(words[0]);//words��ÿ�����ʵĳ���
	char *tag = (char*)calloc(wordsSize, sizeof(char));//�������ÿһ�ֲ�����words�е��Ӵ��Ƿ��ù�
	*returnSize = 0;
	for(i = 0; i + wordsSize * length - 1 < (int)strlen(s); i++){
		memset(tag, 1, wordsSize);//�������1
		for(j = 0; j < wordsSize * length; j += length){
			k = 0;
			while(k < wordsSize){
				if(tag[k] == 1 && strncmp(s + i + j, words[k], length) == 0){
					tag[k] = 0;
					break;//�ɹ���words���ҵ�
				}
				else{
					k++;
				}
			}//�����Ƚ�words�е��Ӵ�
			if(k == wordsSize){
				break;
			}//��ʱ˵����words���Ҳ�����Ӧ���Ӵ�������ѭ��
		}//ÿ���ƶ�һ�������Ӵ�,ÿһ�αȽ�s�е��Ӵ�ʱ����Ҫ����words�еĵ��ʣ���Ҫ��k��Ϊ0
		if(j == wordsSize * length){
			if(*returnSize > max){
				max += 200;
				ret = (int*)realloc(ret, max);
			}
			ret[(*returnSize)++] = i;
		}//���ȫ���ҵ�
	}//ÿ�������ƶ�һ���Ӵ��ĳ���
	return ret;
}

int main(){
	char s[] ="lingmindraboofooowingdingbarrwingmonkeypoundcake";
	char *words[] = {"fooo","barr","wing","ding","wing"};
	int returnSize = 0;
	int wordsSize = sizeof(words) / sizeof(words[0]);
	int *ret = NULL;
	int i = 0;
	ret = findSubstring(s, words, wordsSize, &returnSize);
	for(i = 0; i < returnSize; i++){
	 printf("%d\n", ret[i]);
	}
	return 0;
}