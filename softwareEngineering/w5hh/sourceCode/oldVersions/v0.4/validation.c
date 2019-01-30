bool input_validation(struct student_info *store, FILE **ifp, FILE **ofp)
{
	char buffer[40];
	
	fscanf(*ifp, "%s", store->name);
	fscanf(*ifp, "%s", store->addr);
	fscanf(*ifp, "%s", store->rollNo);
	
	fscanf(*ifp, "%s", buffer);
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
	fscanf(*ifp, "%s", buffer);
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
	fscanf(*ifp, "%s", buffer);
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
	// fscanf(ifp, "%s", store->name);
	// fscanf(ifp, "%s", store->addr);
	// fscanf(ifp, "%s", store->rollNo);
	// fscanf(ifp, "%f", &store->physics);
	// fscanf(ifp, "%f", &store->chemistry);
	// fscanf(ifp, "%f", &store->maths);
}
