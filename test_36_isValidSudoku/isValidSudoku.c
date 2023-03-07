#define bool int
#define true 1
#define false 0
#include<stdio.h>
#include<malloc.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
	int row[9][9] = {0};//��¼��
	int col[9][9] = {0};//��¼��
	int subboard[3][3][9] = {0};//��¼ÿ���ӿ�
	int i = 0;//�е�ѭ������
	int j = 0;//�е�ѭ������
	char temp = 0;//Ϊ�˷��㣬ÿ�ν�board��Ҫ���������ȷŽ�ȥ
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			temp = board[i][j];
			if(temp == '.') continue;//���û���������֣�������
				if(row[i][temp - '1'] == 0 && col[j][temp - '1'] == 0 && subboard[i / 3][j / 3][temp - '1'] == 0){
					row[i][temp - '1'] = 1;
					col[j][temp - '1'] = 1;
					subboard[i / 3][j / 3][temp - '1'] = 1;
				}//�����û���ֹ���ȫ����1
				else 
					return false;
		}
	}//�������
	return true;
}