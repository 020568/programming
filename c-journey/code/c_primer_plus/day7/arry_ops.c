#include <stdio.h>
#define ROWS 3
#define COLS 4
void sum_cols(int arry[][COLS],int rows);
void sum_rows(int [][COLS],int);
int sum(int (*arry)[COLS],int rows);
int main(void)
{
	int arry[ROWS][COLS]=
	{
		{2,4,6,8},
		{3,5,7,9},
		{12,10,8,6}
	};
	sum_rows(arry,ROWS);
	sum_cols(arry,ROWS);
	printf("%d", sum(arry,ROWS));
}

void sum_rows(int arry[][COLS],int rows)//the sum of row
{
	int r=0;
	int c=0;
	int total;
	for(r;r<rows;r++)
	{
		total=0;
		for(c;c<COLS;c++)
		{
			total+=arry[r][c];	
		}
		printf("The sum of rows %d is :  %d. \n",r+1,total);
	}
	
}
//The transfer function parameter cannot be omitted
void sum_cols(int arry[][COLS],int rows)//the sum of column
{
	int r=0;
	int c=0;
	int total;
	for(c=0;c<COLS;c++)
	{
		total=0;
		for(r=0;r<rows;r++)
		{
			total+=arry[r][c];	
		    
		}
		printf("The sum of columns %d is : %d. \n",c+1,total);

	}
	
}

int sum(int arry[][COLS], int rows)
{
	int r;
	int c;
	int total;
	for(r=0;r<rows;r++)
		for(c=0;c<COLS;c++)
		    total += arry[r][c];	
	return total;
}





