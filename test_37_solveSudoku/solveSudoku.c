#include<stdio.h>
#include<malloc.h>
int row[9][9] = {0};//标记行
int col[9][9] = {0};//标记列
int subboard[3][3][9] = {0};//标记子块
int valid = 0;//标记得到的数组是否有效
void DFS(char board[][9], int i, int j){
	char temp;//读取当前要处理的单元的字符
	int digit = 1;
	if(i == 9){
		valid = 1;
		return;
	}
	temp = board[i][j];//这一步不能在定义temp的时候进行，否则i可能会越界
	if(temp != '.'){
		if(j != 8){
			j++;
		}
		else{
			i++;
			j = 0;
		}//更新下一个要处理的单元的坐标
		DFS(board, i, j);
	}//如果不为空，则跳过
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
				}//更新下一个要处理的单元的坐标
				DFS(board, i, j);
				if(j == 0){
					j = 8;
					i--;
				}
				else{
					j--;
				}//变回原来的坐标
				if(!valid){
					board[i][j] = '.';
					row[i][digit] = 0;
					col[j][digit] = 0;
					subboard[i / 3][j / 3][digit] = 0;
				}//这一步如果还没找到解，才进行恢复
			}//如果该数字都不重复
		}//从1开始试,前提是还没有得到有效的解
	}

}
void solveSudoku(char board[][9], int boardSize, int* boardColSize){
	int i = 0;//行                   
	int j = 0;//列
	char temp = 0;//存储当前数独位置的字符
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(subboard, 0, sizeof(subboard));
	valid = 0;//这一系列赋值是为了满足力扣中对每个测试用例逐个调用时，全局变量的值会变成上一个测试用例用完后的值，需要再次初始化
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			temp = board[i][j];
			if(temp == '.') continue;//如果没有填入数字，则不进行处理
			else{
				row[i][temp - '1'] = 1;//之所以是减‘1’，是因为数独的数字不是从0开始，是从1开始
				col[j][temp - '1'] = 1;
				subboard[i / 3][j / 3][temp - '1'] = 1;
			}
		}
	}//第一遍遍历，记录数组中已有的数字
	DFS(board, 0, 0);//回溯
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