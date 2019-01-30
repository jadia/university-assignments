#include "structure.h"
#include "structure.h"
void retriveRollnoRecord()
{
    FILE *getOne;
    if ((getOne = fopen(OUTPUT, "r")) == NULL)
    {
        perror("DataBaseFile : ");
        exit(1);
    }
    printf("Roll no to search for?\n");
    char getRoll[15];
    scanf("%s", getRoll);
    bool flag = true;
    while (fread(&store, sizeof(struct student_info), 1, getOne))
    {
        if (!strcmp(getRoll, store.rollNo))
        {
            printf("RECORD FOUND! \n");
            printf("\n\tName = %s %s addr = %s \n\tRollNo: %s \n\tPCM: %.2f, %.2f and %.2f \n\t Total Marks: %.2f avg Marks: %.2f", store.fname, store.lname, store.addr, store.rollNo, store.physics,
                   store.chemistry, store.maths, store.totalMarks, store.avgMarks);
            printf("\n\t Result: ");
            if (store.result)
                printf("Pass\n");
            else
                printf("Fail\n");
            flag = false;
            break;
        }
    }
        if(flag)
            printf("\n\t Record NOT FOUND!");
    fclose(getOne);
        /** holding screen */
    printf("\n Enter 'q' to go back: ");
    scanf(" %c", &hodor);
}