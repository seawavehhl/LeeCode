#include<string.h>
#include<stdlib.h>
#include<stdio.h>
char * convert(char * s, int numRows){
	char temp[1001][1001] = {0};//�洢ÿһ�е��ַ�
	int i = 0;//�к�
	int j = 0;//���е��±�
	int j1 = 0,j2 = 0;//��һ�к����һ�е��±굥������
	int len = strlen(s);
	int n = 1;//������¼�ѱ������ַ���
	int key = 1;//key == 0 ʱ���������¼�¼�ַ���key == 1ʱ���������ϼ�¼�ַ�
	char * ret = NULL;//�����ַ���
	if(numRows == 1) return s;//���ֻ��һ�У�ֱ�ӷ���
	for(n = 0; n < len; n++){
		if(i == 0){
			temp[i][j1] = s[n];//��0�е���ʹ��j1Ϊ�б�
			j1++;
			key = !key;
			if(n != 0) j++;
		}
		else if(i == numRows - 1){
			temp[i][j2] = s[n];//���һ�е���ʹ��j2Ϊ�б�
			j2++;
			key = !key;
			j++;
		}
		else temp[i][j] = s[n];//jΪ�����й����б�
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
	}//�ռ�����
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