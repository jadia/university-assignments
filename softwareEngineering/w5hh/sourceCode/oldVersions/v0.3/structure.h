/* structure defination */
#ifndef STRUCTURE_H
#define STRUCTURE_H
struct student_info
{
	char name[20];
	char addr[40];
	char rollNo[15];
	float physics, chemistry, maths, totalMarks, avgMarks;
	bool result;
} store;

/*#defines*/
#define INPUT "input.txt"
#define OUTPUT "output.dat"

#endif