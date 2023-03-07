#define bool int
#define true 1
#define false 0
#include<stdio.h>
#include<malloc.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize){
	int row[9][9] = {0};//记录行
	int col[9][9] = {0};//记录列
	int subboard[3][3][9] = {0};//记录每个子块
	int i = 0;//行的循环变量
	int j = 0;//列的循环变量
	char temp = 0;//为了方便，每次将board中要检查的数字先放进去
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			temp = board[i][j];
			if(temp == '.') continue;//如果没有填入数字，则跳过
				if(row[i][temp - '1'] == 0 && col[j][temp - '1'] == 0 && subboard[i / 3][j / 3][temp - '1'] == 0){
					row[i][temp - '1'] = 1;
					col[j][temp - '1'] = 1;
					subboard[i / 3][j / 3][temp - '1'] = 1;
				}//如果都没出现过，全部置1
				else 
					return false;
		}
	}//遍历检查
	return true;
}