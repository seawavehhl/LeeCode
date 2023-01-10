#include<stdio.h>
#include<string.h>
#define bool int
#define true 1
#define false 0
int match(char a, char b){
	if(a == b || b == '.') return 1;
	return 0;
}//ƥ�亯��
bool isMatch(char * s, char * p){
	int slen = strlen(s);
	int plen = strlen(p);//��������ַ�������
	int f[21][31] = {false};//������ݣ�f[i][j] == 1��ʾs�е���i���ַ����Ӵ���p�е�j���ַ����Ӵ�ƥ��
	int i = 0, j = 0;//ѭ������
	f[0][0] = true;//���ַ���Ĭ��ƥ�䣬���������±���ַ�λ����ͬ
	while(i < slen){
		while(j < plen){
			if(p[j] != '*'){
				if(match(s[i], p[j])){
					f[i+1][j+1] = f[i][j];
				}//���ƥ��
			}//���p��Ҫ��Ե��ַ�����ĸ����'.'
			else if(p[j] == '*'){
				if(i == 0) f[i][j+1] = f[i][j-1];//����aa��a*ƥ��������һ���߽�����
				if(match(s[i], p[j-1])){
					if(f[i][j+1] || f[i+1][j-1]) f[i+1][j+1] = true;//if������'*'ƥ��0���ַ�����ƥ�����ַ������
				}//���'*'ǰ��һ���ַ���s�е��ַ�ƥ��
				else{
					f[i+1][j+1] = f[i+1][j-1];
				}//���'*'ǰ��һ���ַ���s�е��ַ���ƥ��
			}//���Ҫƥ����ַ���'*'
			j++;
		}
		j = 0;
		i++;
	}//ƥ�����
	if(f[slen][plen]) return 1;//��������ַ���ƥ��
	return 0;//�����ƥ��
}

int main(){
	char s[] = "aab";
	char p[] = "c*a*b";
	int ret = isMatch(s, p);
	printf("%d", ret);
	return 0;
}