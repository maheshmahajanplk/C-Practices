// Sherlock_Decent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int power(int x, unsigned int y)
{
	if (y == 0)
		return 1;
	else if (y % 2 == 0)
		return power(x, y / 2)*power(x, y / 2);
	else
		return x*power(x, y / 2)*power(x, y / 2);

}

void getStringPowerSet(int set_size,vector<string> &vPowerSet)
{
	/*set_size of power set of a set with set_size
	n is (2**n -1)*/
	unsigned int pow_set_size = power(2, set_size);
	unsigned int counter, j;

	/*Run from counter 000..0 to 111..1*/
	for (counter = 0; counter < pow_set_size; counter++)
	{
		string LocalString;
		for (j = 0; j < set_size; j++)
		{
			/* Check if jth bit in the counter is set
			If set then pront jth element from set */
			if (counter & (1 << j))
				LocalString.append("5");
			else
				LocalString.append("3");
		}
		vPowerSet.push_back(LocalString);
		
	}
}

/*Driver program to test printPowerSet*/
int main()
{
	char set[] = { '3', '5'};
	vector<string> vPowerSet;
	getStringPowerSet(3,vPowerSet);

	for (std::vector<string>::const_iterator i = vPowerSet.begin(); i != vPowerSet.end(); ++i)
		std::cout << *i << endl;
	
	getchar();
	return 0;
}