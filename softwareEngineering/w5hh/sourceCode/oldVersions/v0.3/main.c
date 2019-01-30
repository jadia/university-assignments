/*
Program to insert, calculate and retrieve student records.
Author: Nitish Jadia
Date: 2019-01-15
Version: v0.3
Changelog:
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
#include "structure.h"
#include "calculate.c"
#include "validation.c"
#include "uploadRecords.c"
#include "retriveAllRecords.c"

// /*#defines*/
// #define INPUT "input.txt"
// #define OUTPUT "output.dat"

/* main */
int main()
{
	/* Reading file for input*/
	FILE *ifp, *ofp; // inputFilePointer , outputFilePointer

	if ((ifp = fopen(INPUT, "r")) == NULL)
	{
		perror("InputFile : ");
		exit(1);
	}

	if ((ofp = fopen(OUTPUT, "w+")) == NULL)
	{
		perror("OutputFile : ");
		exit(1);
	}

	int choice;
	while (true)
	{
		printf("\n\nWhat do you wish to do? \n");
		printf("\t1.) Insert records.\n\t2.)Retrive All records\n\t3.) Exit ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			uploadRecords(ifp, ofp);
			break;

		case 2:
			retriveAllRecords();
			break;
		case 3:
			exit(0);
		default:
			break;
		}
	}
}