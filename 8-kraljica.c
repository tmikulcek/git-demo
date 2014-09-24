#include <stdio.h>

int board[8][8];
int set;
int skip[8][8];

void queens();
void setQueen(int row, int column);
void removeQueen();
int square(int row, int column, int i, int j);
void printResult();

int main()
{
	int i, j;
	
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			board[i][j] = 0;
			skip[i][j] = 0;
		}
	set = 0;
	
	queens();
	printResult();
	return 0;
}

void queens()
{
	int column, foundSpot;
	
	while(set < 8)
	{
		foundSpot = 0;
		
		for (column = 0; column < 8; column++)
		{
			if (board[set][column] == 0 && skip[set][column] == 0)
			{
				setQueen(set, column);
				foundSpot = 1;
				break;
			}
		}
		
		if (!foundSpot)
			removeQueen();
	}
}

void setQueen(int row, int column)
{
	int i, j;
	
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{
			if (i == row || j == column || square(row, column, i, j))
				board[i][j]++;
		}
		
	board[row][column] = 10;
	set++;
	printf("set queen number %d to column %d\n", set, column + 1);
}

void removeQueen()
{
	int row, column, columnQueens;
	set--;
	
	for (column = 0; column < 8; column++)
	{
		if (board[set][column] == 10)
		{
			board[set][column] = 0;
			skip[set][column] = 1;
			columnQueens = column;
			break;
		}
	}
	
	for (row = 0; row < 8; row++)
		for (column = 0; column < 8; column++)
			if ((row == set || column == columnQueens || square(set, columnQueens, row, column)) && board[row][column] > 0)
				board[row][column]--;
			
	for (column = 0; column < 8; column++)
		skip[set + 1][column] = 0;
	
	printf("removed queen number %d\n", set + 1);
}

void printResult()
{
	int row, column;
	
	for (row = 0; row < 8; row++)
	{
		for (column = 0; column < 8; column++)
		{
			if (board[row][column] != 10)
				printf("_ ");
			else
				printf("K ");
		}
		printf("\n");
	}
}

int square(int row, int column, int i, int j)
{
	int absoluteI, absoluteJ;
	
	absoluteI = row - i;
	if (absoluteI < 0)
		absoluteI = 0 - absoluteI;
	
	absoluteJ = column - j;
	if (absoluteJ < 0)
		absoluteJ = 0 - absoluteJ;
		
	if (absoluteI == absoluteJ)
		return 1;
	else
		return 0;
}
