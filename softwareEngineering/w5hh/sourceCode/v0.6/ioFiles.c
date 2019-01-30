/*#defines*/
#define INPUT "input.txt"
#define OUTPUT "output.dat"

void ioFiles()
{
	/* Reading file for input*/
	FILE *ifp, *ofp; // inputFilePointer , outputFilePointer
	if ((ifp = fopen(INPUT, "r")) == NULL)
	{
		perror("InputFile : ");
		exit(1);
	}

	if ((ofp = fopen(OUTPUT, "w+")) == NULL)
	{
		perror("OutputFile : ");
		exit(1);
	}
}