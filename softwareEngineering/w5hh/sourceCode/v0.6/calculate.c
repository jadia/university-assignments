void calculate(struct student_info *store)
{
	store->totalMarks = store->physics+store->chemistry+store->maths;
	store->avgMarks = store->totalMarks/3;
	if(store->totalMarks < 150)
		store->result = false;
	else
		store->result = true;
}