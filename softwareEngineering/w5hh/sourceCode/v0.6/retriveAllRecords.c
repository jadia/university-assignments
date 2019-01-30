#include "structure.h"

void retriveAllRecords()
{
    FILE *db;
    if ((db = fopen(OUTPUT, "r")) == NULL)
    {
        perror("DataBaseFile : ");
        exit(1);
    }
    printf("\e[1;1H\e[2J");
    printf("Reading all records: \n");
    while (fread(&store, sizeof(struct student_info), 1, db))
    {
        printf("\n\tName = %s %s \n\taddr = %s \n\tRollNo: %s \n\tPCM: %.2f, %.2f and %.2f \n\t Total Marks: %.2f avg Marks: %.2f", store.fname, store.lname, store.addr, store.rollNo, store.physics, store.chemistry, store.maths, store.totalMarks, store.avgMarks);
        printf("\n\t Result: ");
        if (store.result)
            printf("Pass\n");
        else
            printf("Fail\n");
    }
    /** holding screen */
    printf("\n Enter 'q' to go back: ");
    scanf(" %c", &hodor);
    fclose(db);
}