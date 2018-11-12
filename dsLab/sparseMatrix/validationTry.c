#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INPUTFILE "inputFile.txt"
#define MAX_BUFFER 256
void main()
{
  FILE *fp;
  if((fp = fopen(INPUTFILE, "r")) == NULL)
  {
    perror("InputFile: ");
    exit(1);
  }

  int TestCases, noOfElements;
  fscanf(fp,"%d", &TestCases);

  char *input = (char*) malloc(MAX_BUFFER);

  while(TestCases)
  {
    fscanf(fp, "%d", &noOfElements);
    fgets(input, MAX_BUFFER, fp);
    char *trace = input;
    while(*trace != '\n')
    {
      printf("%c ", *trace);
      trace++;
    }
    TestCases--;
  }
}
