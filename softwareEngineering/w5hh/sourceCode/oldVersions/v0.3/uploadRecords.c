//#include <stdio.h>
void uploadRecords(FILE *ifp, FILE *ofp)
{
	/* storing to database*/
	bool addMore = true;
	char yesOrno = 'n';
	while(addMore)
	{
		/* input_validation is false if input is invalid, so try again.*/
		while(!input_validation(&store, &ifp, &ofp))
		{
			printf("\nPlease enter valid input.");
		}
		calculate(&store);
		//printf("Data: %s:%s:%s:%f:%f:%f:%f:%f", store.name, store.addr, store.rollNo, store.physics,
		//store.chemistry, store.maths, store.totalMarks, store.avgMarks);
		/*
		size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
		ptr - This is pointer to array of elements to be written
		size -  This is the size in bytes of each element to be written
		nmemb - This is the number of elements, each one with a size of size bytes
		stream - This is the pointer to a FILE object that specifies an output stream
		*/
		fwrite (&store, sizeof(struct student_info), 1, ofp);
		if(fwrite != 0)  
        	printf(" contents to file written successfully !\n"); 
    	else 
        	printf("\nError writing file !\n"); 
		
		printf("\nDo you wish to add more records? [y/n] ");
		scanf(" %c", &yesOrno);
		printf("\nYour choice: %c\n", yesOrno);
		if (yesOrno != 'y')
		{
			printf("Making addMore false.");
			addMore = false;
		}
	}

    // close file 
    fclose (ofp);
	fclose (ifp);
}