// CodeGladiator1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct CirArr{
	int index;
	int ballPass;
	struct CirArr *next;
	struct CirArr *prev;
}CIRARR;

/*void CreateCirArr(CIRARR **start,int size){
	start = NULL;
	CIRARR *temp = NULL;
	int i = 1;
	while (i <= size){
		if (*start == NULL)
		{
			temp = *start = new CirArr();
			start->index = i;
			start->prev = NULL; //later should point to last node...
			start->next = NULL;
		}
		else{
			temp->next = new CirArr();
			temp->next->index = i;
			temp->next->prev = temp;
			temp->next->next = NULL;
			temp = temp->next;

			if (i == size){ //making it circular...
				temp->next = start;
				start->prev = temp;
			}
				
		}
		i++;
	}
}
*/

int _tmain(int argc, _TCHAR* argv[])
{
	CIRARR *start = NULL;
	int size,L,M;
	int move = 0;
	cin >> size;
	cin >> M;
	cin >> L;

	//CreateCirArr(&head, size);
	start = NULL;
	CIRARR *ptr1=NULL,*ptr2 = NULL;
	int i = 1;


	while (i <= size){
		if (start == NULL)
		{
			start = new CirArr();
			start->index = i;
			start->prev = NULL; //later should point to last node...
			start->next = NULL;
		}
		else{
			if (ptr1 == NULL)
			{
				ptr1 = start;
			}
			ptr1->next = new CirArr();
			ptr2 = ptr1->next;
			ptr2->index = i;
			ptr2->prev = ptr1;
			ptr2->next = NULL;
			ptr1 = ptr2;
			ptr2 = ptr2->next;

			if (i == size){ //making it circular...
				ptr1->next = start;
				start->prev = ptr1;
				ptr1 = NULL;
			}

		}
		i++;
	}

	cout << "\nCircular linked list created....." << endl;
	//print entered list

	for (CIRARR *temp = start; temp->index < (size+1) || temp->next !=start ; temp = temp->next)
	{
		cout << temp->index << "->";
	}
	/*int BallPass = 0;
	/*-----------Logic start here--------*/
	/*while (BallPass < M){

		temp = start;
		temp->ballPass = 1;
	}*/

	i = 0;
	CIRARR * ptr=NULL;

	cout << "\nDeleting CIRARR...." << endl;

	//deleting CirArr
	while (i < size){

		ptr = start;
		ptr1 = start->next;
		ptr2 = start->prev;

		ptr->next = NULL;
		ptr->prev = NULL;

		if (ptr1)
		ptr1->prev = NULL;
		
		if (ptr2)
		ptr2->next = NULL;

		start = ptr1;
		
		delete ptr;
		i++;
	}

	
	return 0;
}

