/*1a. Write a program generating atleast 10 random numbers,
storing it into a text file-1.
1b. Read the text file-1 generated above and copy the details
from text file-1 to text file-2(generate a new file).
by Nitish Jadia 18MCMT13 */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
  int random, num;
  FILE *fp;

  if ((fp = fopen("file-1.txt","w")) == NULL)
  {
    printf("Error! Opening file in write mode!");

    // Program exits if file pointer returns NULL.
    exit(1);
  }
  srand(time(0)); // seeding the random function
  int i = 10;
  while(i)
  {

    random = rand() % 1000; // limiting random value to 1000

    fprintf(fp,"%d ",random);

    i--;
  }
  fclose(fp);


  if ((fp = fopen("file-1.txt","r")) == NULL)
  {
    printf("Error! Opening file in read mode!");

    exit(1);
  }

  i = 10;
  while(i)
  {
    fscanf(fp, "%d", &num);
    i--;
    printf("Value of n = %d \n", num);
  }
  fclose(fp);

}
