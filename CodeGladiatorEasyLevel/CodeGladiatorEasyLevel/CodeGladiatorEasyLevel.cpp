// CodeGladiatorEasyLevel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

typedef struct height{
	int feet, inch;
}Height;

int compare(Height a, Height b){ //0 - arg1 & arg2 are same  1 -  arg1 is greater  2 - arg2 is greater
	if ((a.feet > b.feet) && (a.inch>b.inch))
		return 1;
	else if ((a.feet > b.feet) && (a.inch < b.inch))
		return 1;
	else if ((a.feet == b.feet) && (a.inch == b.inch))
		return 0;
	else if ((a.feet == b.feet) && (a.inch > b.inch))
		return 1;
	else if ((a.feet == b.feet) && (a.inch < b.inch))
		return 2;
	else
		return 2;
}
int getInterchangebles(char *input1[], int input2)
{
	int i=0, j=0, k=0, l=0;
	char szFeet[MAX] = { "" }, szInch[MAX] = { "" };
	Height arr[MAX];
	int interchangable = 0;

	for (i = 0; i < input2; i++)
	{
		k = 0; l = 0;
		for (j = 0; input1[i][j]; j++)
		{
			if (j > 1)
			{
				szInch[l] = input1[i][j]; l++;
			}
			else if (input1[i][j] == '#')
				continue;
			else
				szFeet[k] = input1[i][j]; k++;
		}
		szFeet[k] = '\0';
		szInch[l] = '\0';

		arr[i].feet = atoi(szFeet);
		arr[i].inch = atoi(szInch);

		if (arr[i].feet >= 4 && arr[i].feet <= 7 && arr[i].inch >= 0 && arr[i].inch <= 11){} //remined to validate scored becomes 40/100
		else
		 return -1;
	}
	
	for (i = 0; i < input2; i++)
	{
			for (j = i + 1; j < input2; j++)
			{
				if (compare(arr[i], arr[j]) == 1) //first element is  greater...
					interchangable++;
			}
	}
				
	return interchangable;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *heights[10] = { "5#11", "5#11", "7#9", "5#11", "5#1" };
	int res = getInterchangebles(heights, 5);
	printf("   %d   \n", res);
	return 0;
}

