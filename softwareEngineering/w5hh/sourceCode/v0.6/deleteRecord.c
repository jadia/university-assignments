#include "structure.h"
#define NEW "output.new.dat"
void deleteRecord()
{
    FILE *delOne, *newOne;
    if ((delOne = fopen(OUTPUT, "r")) == NULL)
    {
        perror("DataBaseFile : ");
        exit(1);
    }
    if ((newOne = fopen(NEW, "w")) == NULL)
    {
        perror("NewDataBaseFile : ");
        exit(1);
    }

    printf("Roll no to delete?\n");
    char getRoll[15];
    bool flag = true;
    scanf("%s", getRoll);
    while (fread(&store, sizeof(struct student_info), 1, delOne))
    {
        if (!strcmp(getRoll, store.rollNo))
        {
            flag = false;
            printf("RECORD FOUND! Deleting it.\n");
            printf("\n\tName = %s %s addr = %s \n\tRollNo: %s \n\tPCM: %.2f, %.2f and %.2f \n\t Total Marks: %.2f avg Marks: %.2f", store.fname, store.lname, store.addr, store.rollNo, store.physics, store.chemistry, store.maths, store.totalMarks, store.avgMarks);
            printf("\n\t Result: ");
            if (store.result)
                printf("Pass\n");
            else
                printf("Fail\n");
        }
        else
            fwrite (&store, sizeof(struct student_info), 1, newOne);
    }
    if(flag)
        printf("RECORD NOT FOUND!");
    remove(OUTPUT);
    rename(NEW,OUTPUT);
    fclose(delOne);
    fclose(newOne);
        /** holding screen */
    printf("\n Enter 'q' to go back: ");
    scanf(" %c", &hodor);
}