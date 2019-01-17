/*
Program to insert, calculate and retrieve student records.
Author: Nitish Jadia
Date: 2019-01-15
Version: v0.1
*/

/*Header files*/
#include<stdio.h>
#include<stdlib.h> // exit()
#include<stdbool.h> // bool data structure


/*#defines*/
#define INPUT "input.txt"
#define OUTPUT "output.txt"

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
		fscanf(ifp, "%s", store.name);
		fscanf(ifp, "%s", store.addr);
		fscanf(ifp, "%s", store.rollNo);
		fscanf(ifp, "%f", &store.physics);
		fscanf(ifp, "%f", &store.chemistry);
		fscanf(ifp, "%f", &store.maths);
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
		scanf("%c", &choice);
		if (choice != 'y')
		{
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

	printf("Reading file: \n");
	while(fread(&store, sizeof(student_info), 1, db)) 
        printf ("name = %s addr = %s rollNo: %s %lf %lf %lf %lf %lf\n",store.name, store.addr, store.rollNo, store.physics,
		store.chemistry, store.maths, store.totalMarks, store.avgMarks); 


}