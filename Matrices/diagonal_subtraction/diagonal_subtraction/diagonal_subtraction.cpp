// diagonal_subtraction.cpp : Defines the entry point for the console application.
//This code asked in HackerRank.com

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>

#define COL 3
#define ROW 3

int getDiagonalSubtraction(int a[][COL])
{
	int pri_diagonal_sum = 0;
	int sec_diagonal_sum = 0;
	int sub=0;

	for (int x = 0; x < ROW; x++){
		for (int y = 0; y < COL; y++){

			if (x == y)
			{
				pri_diagonal_sum += a[x][y];
				//printf("\n pri_diagonal_sum : %d", pri_diagonal_sum);
			}
			
			if (x + y == (COL-1) ) //sizeof matrix = COL=ROW
				sec_diagonal_sum += a[x][y];
			}
	}

	sub = abs(pri_diagonal_sum - sec_diagonal_sum);

	return sub;

}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[ROW][COL];

	printf("Enter matrix of order 3x3:");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			scanf_s("%d", &a[i][j]);
		}
		
	}
	printf("\n Entered Matrix is : \n");
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}

	int res=getDiagonalSubtraction(a);
	
	printf("\nsubtraction=%d\n", res);

	return 0;
}

