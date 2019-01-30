/* structure defination */
#ifndef STRUCTURE_H
#define STRUCTURE_H

struct student_info
{
	char fname[20];
	char lname[20];
	char addr[40];
	char rollNo[15];
	float physics, chemistry, maths, totalMarks, avgMarks;
	bool result;
} store;

/*#defines*/
#define OUTPUT "output.dat"
char hodor;
#endif