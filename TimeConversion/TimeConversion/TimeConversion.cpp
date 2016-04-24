// TimeConversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<iostream>

/*Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:0000:00:00 on a 24-hour clock. 
        Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock. 

		1. 12:00:00AM -> 00:00:00
		2. 12:00:00PM -> 
*/

int _tmain(int argc, _TCHAR* argv[])
{
	char hr12[20] = { 0 };
	int hh = 0, mm = 0, ss = 0;
	char AmPm[5] = { 0 };
	char szhh[5] = { 0 };

	gets(hr12);

	sscanf(hr12, "%2d:%2d:%2d%2s", &hh,&mm,&ss,&AmPm);

	if (strcmp(AmPm, "PM") == 0)
	{
		if (hh < 12)
			hh += 12;
		else if (hh == 12) { //keep 12 as it is
		}
		else 
			std::cout << "\ninvalid\n";

	}
	else if (strcmp(AmPm, "AM") == 0){
		if (hh == 12){
			strcpy(szhh, "00:");
		}
		
			
	}
	

	return 0;
}

