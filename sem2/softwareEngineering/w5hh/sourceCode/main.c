/*
Program to insert, calculate and retrieve student records.
Author: Nitish Jadia
Date: 2019-01-15
Version: v0.2
Changelog:
		v0.2:
			1. Made output.txt -> output.dat
			2. validation to input added.
			3. pass/fail added.
		v0.1:
			1. read and write from and to the file added.
			2. initial commit.
*/

/*Header files*/
#include<stdio.h>
#include<stdlib.h> // exit()
#include<stdbool.h> // bool data structure


/*#defines*/
#define INPUT "input.txt"
#define OUTPUT "output.dat"

/* structure defination */
struct student_info
{
	char name[20];
	char addr[40];
	char rollNo[15];
	float physics, chemistry, maths, totalMarks, avgMarks;
	bool result;
};

typedef struct student_info student_info;


/* functions */
void calculate(student_info *store)
{
	store->totalMarks = store->physics+store->chemistry+store->maths;
	store->avgMarks = store->totalMarks/3;
	if(store->totalMarks < 150)
		store->result = false;
	else
		store->result = true;
}

bool input_validation(student_info *store, FILE **ifp, FILE **ofp)
{
	char buffer[40];
	
	fscanf(*ifp, "%s", store->name);
	fscanf(*ifp, "%s", store->addr);
	fscanf(*ifp, "%s", store->rollNo);
	
	fscanf(*ifp, "%s", buffer);
	if(sscanf(buffer,"%f",&store->physics) == 0)
	{
		printf("Returning false1 \n");
		return false;
	}
	else if( store->physics > 100 || store->physics < 0)
	{
		printf("Invalid value. Please enter value from 0-100");
		return false;
	}
	fscanf(*ifp, "%s", buffer);
	if(sscanf(buffer,"%f",&store->chemistry) == 0)
	{
		printf("Returning false2 \n");
		return false;
	}
		else if( store->chemistry > 100 || store->chemistry < 0)
	{
		printf("Invalid value. Please enter value from 0-100");
		return false;
	}
	fscanf(*ifp, "%s", buffer);
	if(sscanf(buffer,"%f",&store->maths) == 0)
	{
		printf("Returning false3 \n");
		return false;
	}
		else if( store->maths > 100 || store->maths < 0)
	{
		printf("Invalid value. Please enter value from 0-100");
		return false;
	}
	return true;
	// fscanf(ifp, "%s", store->name);
	// fscanf(ifp, "%s", store->addr);
	// fscanf(ifp, "%s", store->rollNo);
	// fscanf(ifp, "%f", &store->physics);
	// fscanf(ifp, "%f", &store->chemistry);
	// fscanf(ifp, "%f", &store->maths);
}

/* main */
int main()
{
/* Reading file for input*/
	FILE *ifp, *ofp; // inputFilePointer , outputFilePointer
	if((ifp = fopen(INPUT,"r")) == NULL)
	{
		perror("InputFile : ");
		exit(1);
	}

	if((ofp = fopen(OUTPUT,"w+")) == NULL)
	{
		perror("OutputFile : ");
		exit(1);
	}

	student_info store;
	/* storing to database*/
	bool addMore = true;
	char choice = 'n';
	while(addMore)
	{
		/* input_validation is false if input is invalid, so try again.*/
		while(!input_validation(&store, &ifp, &ofp))
		{
			printf("\nPlease enter valid input.");
		}
		calculate(&store);
		printf("Data: %s:%s:%s:%f:%f:%f:%f:%f", store.name, store.addr, store.rollNo, store.physics,
		store.chemistry, store.maths, store.totalMarks, store.avgMarks);
		/*
		size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
		ptr - This is pointer to array of elements to be written
		size -  This is the size in bytes of each element to be written
		nmemb - This is the number of elements, each one with a size of size bytes
		stream - This is the pointer to a FILE object that specifies an output stream
		*/
		fwrite (&store, sizeof(student_info), 1, ofp);
		if(fwrite != 0)  
        	printf(" contents to file written successfully !\n"); 
    	else 
        	printf("\nError writing file !\n"); 
		
		printf("\nDo you wish to add more records? [y/n] ");
		scanf(" %c", &choice);
		printf("\nYour choice: %c\n", choice);
		if (choice != 'y')
		{
			printf("Making choice false.");
			addMore = false;
		}
	}

    // close file 
    fclose (ofp);
	fclose (ifp);
	FILE *db;
	if((db = fopen(OUTPUT,"r")) == NULL)
	{
		perror("DataBaseFile : ");
		exit(1);
	}

	printf("Reading all records: \n");
	while(fread(&store, sizeof(student_info), 1, db))
	{

        printf ("\n\tName = %s addr = %s \n\tRollNo: %s \n\tPCM: %lf, %lf and %lf \n\t Total Marks: %lf avg Marks: %lf",store.name, store.addr, store.rollNo, store.physics,
		store.chemistry, store.maths, store.totalMarks, store.avgMarks); 
		printf("\n\t Result: ");
		if(store.result)
			printf("Pass\n");
		else
			printf("Fail\n");
	}

}