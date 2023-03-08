#include<stdio.h>
#include<malloc.h>
int row[9][9] = {0};//�����
int col[9][9] = {0};//�����
int subboard[3][3][9] = {0};//����ӿ�
int valid = 0;//��ǵõ��������Ƿ���Ч
void DFS(char board[][9], int i, int j){
	char temp;//��ȡ��ǰҪ����ĵ�Ԫ���ַ�
	int digit = 1;
	if(i == 9){
		valid = 1;
		return;
	}
	temp = board[i][j];//��һ�������ڶ���temp��ʱ����У�����i���ܻ�Խ��
	if(temp != '.'){
		if(j != 8){
			j++;
		}
		else{
			i++;
			j = 0;
		}//������һ��Ҫ����ĵ�Ԫ������
		DFS(board, i, j);
	}//�����Ϊ�գ�������
	else{
		for(digit = 0; !valid && digit < 9; digit++){
			if(!row[i][digit] && !col[j][digit] && !subboard[i / 3][j / 3][digit]){
				board[i][j] = digit + '1';
				row[i][digit] = 1;
				col[j][digit] = 1;
				subboard[i / 3][j / 3][digit] = 1;
				if(j != 8){
					j++;
				}
				else{
					i++;
					j = 0;
				}//������һ��Ҫ����ĵ�Ԫ������
				DFS(board, i, j);
				if(j == 0){
					j = 8;
					i--;
				}
				else{
					j--;
				}//���ԭ��������
				if(!valid){
					board[i][j] = '.';
					row[i][digit] = 0;
					col[j][digit] = 0;
					subboard[i / 3][j / 3][digit] = 0;
				}//��һ�������û�ҵ��⣬�Ž��лָ�
			}//��������ֶ����ظ�
		}//��1��ʼ��,ǰ���ǻ�û�еõ���Ч�Ľ�
	}

}
void solveSudoku(char board[][9], int boardSize, int* boardColSize){
	int i = 0;//��                   
	int j = 0;//��
	char temp = 0;//�洢��ǰ����λ�õ��ַ�
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(subboard, 0, sizeof(subboard));
	valid = 0;//��һϵ�и�ֵ��Ϊ�����������ж�ÿ�����������������ʱ��ȫ�ֱ�����ֵ������һ����������������ֵ����Ҫ�ٴγ�ʼ��
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			temp = board[i][j];
			if(temp == '.') continue;//���û���������֣��򲻽��д���
			else{
				row[i][temp - '1'] = 1;//֮�����Ǽ���1��������Ϊ���������ֲ��Ǵ�0��ʼ���Ǵ�1��ʼ
				col[j][temp - '1'] = 1;
				subboard[i / 3][j / 3][temp - '1'] = 1;
			}
		}
	}//��һ���������¼���������е�����
	DFS(board, 0, 0);//����
}
int main(){
	char board[9][9] = {{'.','.','9','7','4','8','.','.','.'},
						{'7','.','.','.','.','.','.','.','.'},
						{'.','2','.','1','.','9','.','.','.'},
						{'.','.','7','.','.','.','2','4','.'},
						{'.','6','4','.','1','.','5','9','.'},
						{'.','9','8','.','.','.','3','.','.'},
						{'.','.','.','8','.','3','.','2','.'},
						{'.','.','.','.','.','.','.','.','6'},
						{'.','.','.','2','7','5','9','.','.'}};

	solveSudoku(board, 0, 0);
	return 0;

}