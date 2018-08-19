//List all the comparisions and Swaps from the out_* files.

#include<stdio.h>
#include<stdlib.h>

void ReadData(char *file_name)
{
  FILE *fp;
  if((fp = fopen(file_name, "r")) == NULL)
  {
    perror("ReadingFile:");
    exit(1);
  }
  FILE *collect_data;
  if((collect_data = fopen("READMEdata.txt", "a")) == NULL)
  {
    perror("AppendFile:");
    exit(1);
  }
  long int get_data;
  fprintf(collect_data,"\n\n%s\n",file_name);
    fprintf(collect_data,"Randomized QuickSort:\n");
  // fscanf(fp,"%ld",&get_data);
  // fprintf(collect_data,"Comparisions: %ld\n", get_data);
  // fscanf(fp,"%ld",&get_data);
  // fprintf(collect_data,"Swaps: %ld\n", get_data);
  //---------------------------------------------------------------

  fscanf(fp,"%ld",&get_data);
  fprintf(collect_data,"Comparisions \t\t\t\t Swaps:\n");
  fprintf(collect_data,"  %ld", get_data);
  fscanf(fp,"%ld",&get_data);
  fprintf(collect_data,"\t\t\t\t %ld", get_data);
  fclose(fp);
  fclose(collect_data);
}


void main()
{
  FILE *cleardata;
  if((cleardata = fopen("READMEdata.txt", "w")) == NULL)
  {
    perror("ClearFile:");
    exit(1);
  }
  fclose(cleardata);
  ReadData("out_asce100.txt");
  ReadData("out_asce1000.txt");
  ReadData("out_asce10000.txt");
  ReadData("out_asce100000.txt");
  ReadData("out_desc100.txt");
  ReadData("out_desc1000.txt");
  ReadData("out_desc10000.txt");
  ReadData("out_desc100000.txt");
  ReadData("out_rand100.txt");
  ReadData("out_rand1000.txt");
  ReadData("out_rand10000.txt");
  ReadData("out_rand100000.txt");
}
