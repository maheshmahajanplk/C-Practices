// AngryTeacher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


/*int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int IsNegative(int ArrivalTime){
	if (ArrivalTime & (1 << 31)){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int t;
	cin >> t;
	vector<string> Output;
	for (int a0 = 0; a0 < t; a0++){
		int n;
		int k;
		int counter = 0;
		cin >> n >> k;
		vector<int> a(n);
		for (int a_i = 0; a_i < n; a_i++){
			cin >> a[a_i];

			if (IsNegative(a[a_i]) || (a[a_i] == 0))
				counter++;
		}
		if (counter >= k)
			Output.push_back("YES");
		else
			Output.push_back("NO");
	}

	for (unsigned int i = 0; i < Output.size(); i++)
	{
		cout << Output[i] << endl;
	}
	return 0;
}