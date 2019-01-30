#include "structure.h"

void retriveAllRecords()
{
    FILE *db;
if((db = fopen(OUTPUT,"r")) == NULL)
{
    perror("DataBaseFile : ");
    exit(1);
}

printf("Reading all records: \n");
while(fread(&store, sizeof(struct student_info), 1, db))
{

    printf ("\n\tName = %s addr = %s \n\tRollNo: %s \n\tPCM: %.2f, %.2f and %.2f \n\t Total Marks: %.2f avg Marks: %.2f",store.name, store.addr, store.rollNo, store.physics,
    store.chemistry, store.maths, store.totalMarks, store.avgMarks); 
    printf("\n\t Result: ");
    if(store.result)
        printf("Pass\n");
    else
        printf("Fail\n");
}

}