/*
Program to insert, calculate and retrieve student records.
Author: Nitish Jadia
Date: 2019-01-17
Version: v0.6
Changelog:
		v0.6:
			Moving from file input to user input
			prompt if record not available
		v0.5:
			1. delete a record
		v0.4:
			1. retrive records based on rollNo
		v0.3:
			1. switch case
			2. modular program
		v0.2:
			1. Made output.txt -> output.dat
			2. validation to input added.
			3. pass/fail added.
		v0.1:
			1. read and write from and to the file added.
			2. initial commit.
*/

/*Header files*/
#include <stdio.h>
#include <stdlib.h>  // exit()
#include <stdbool.h> // bool data structure
#include <string.h>
#include "structure.h"
#include "calculate.c"
#include "validation.c"
#include "uploadRecords.c"
#include "retriveAllRecords.c"
#include "retriveRollnoRecord.c"
#include "deleteRecord.c"

/* main */
int main()
{
	/* Reading file for input*/
	FILE *ofp; // inputFilePointer , outputFilePointer

	if ((ofp = fopen(OUTPUT, "a")) == NULL)
	{
		perror("OutputFile : ");
		exit(1);
	}

	int choice;
	while (true)
	{
		printf("\e[1;1H\e[2J");
		printf("\n \t STUDENT DATABASE SYSTEM");
		printf("\n\nWhat do you wish to do? \n");
		printf("\t1.) Insert records.\n\t2.) Retrive All records\n\t3.) Retrive Record of a specific Roll no. \n\t4.) Delete a record\n\t5.) Exit \n\t");
		printf("[1-5]: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			uploadRecords(ofp);
			break;

		case 2:
			retriveAllRecords();
			break;
		case 3:
			retriveRollnoRecord();
			break;
		case 4:
			deleteRecord();
			break;
		case 5:
			exit(0);
		default:
			break;
		}
	}
}