// Perm_Comb_Num.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/*int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}*/
int power(int x, unsigned int y)
{
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return power(x, y / 2)*power(x, y / 2);
	else
		return x*power(x, y / 2)*power(x, y / 2);

}

void printPowerSet(char *set, int set_size)
{
	/*set_size of power set of a set with set_size
	n is (2**n -1)*/
	unsigned int pow_set_size = power(2, set_size);
	int counter, j;

	/*Run from counter 000..0 to 111..1*/
	for (counter = 0; counter < pow_set_size; counter++)
	{
		for (j = 0; j < set_size; j++)
		{
			/* Check if jth bit in the counter is set
			If set then pront jth element from set */
			if (counter & (1 << j))
				printf("5");//printf("%c", set[j]);
			else
				printf("3");
		}
		printf("\n");
	}
}

/*Driver program to test printPowerSet*/
int main()
{
	char set[] = { '3', '5' };
	printPowerSet(set, 4);

	getchar();
	return 0;
}