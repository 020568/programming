#include <stdio.h>
#include <stdlib.h>
int check(int** mat,int row,int col,int num);
int solve(int** mat,int row,int col);
// the size of mat is known
int check(int** mat,int row,int col,int num)
{
	for(row=0;row<9;row++)
	{
		if(mat[row][col]==num)
			return 0;
	}
	for(col=0;col<9;col++)
	{
		if(mat[row][col]==num)
			return 0;
	}
	
	int srow=row-(row%3);
	int scol=col-(col%3);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(mat[i+srow][j+scol]==num)
				return 0;
		}
	}
	return 1;
}

int solve(int** mat,int row,int col)
{
	if(row==8&&col==9)
	{
		return 1;
	}
	
	if(col==9)
	{
		row++;
		col=0;
	}
	
	if(mat[row][col]!=0)
	{
		return solve(int** mat,int row,int col+1);
	}
	
	for(int num=1;num<=9;num++)
	{
		if(check(mat,row,col,num))
		{
			mat[row][col]=num;
			if(sovle(mat,row,col+1))
				return 1;
			mat[row][col]=0;
		}
	}
	return 0;
}


int main() 
{
    // A standard 9x9 Sudoku board (0 represents empty cells)
    int mat[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudokuRec(mat, 0, 0)) {
        // Print the solved board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
















