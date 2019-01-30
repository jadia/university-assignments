bool input_validation(struct student_info *store, FILE **ofp)
{
	char buffer[40];
	printf("\nEnter credentials...");
	printf("\n[first name]");
	scanf("%s", store->fname);
	printf("\n[Last name]");
	scanf("%s", store->lname);
	printf("\n[City]");
	scanf("%s", store->addr);
	printf("\n[Roll no]");
	scanf("%s", store->rollNo);
	printf("\n[Physics marks]");
	scanf("%s", buffer);
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
	printf("\n[Chemistry marks]");
	scanf("%s", buffer);
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
	printf("\n[Maths marks]");
	scanf("%s", buffer);
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
}
