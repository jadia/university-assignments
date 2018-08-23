#include<stdio.h>

int CalcPower(int a,int b)
{
  int powervar=1;
  for(int i=0;i<b;i++)
   powervar*=a;
  return powervar;
}

void SortElements(int c[],int a[],int b[],int n)
{
   int i, j,temp;
   for (i=0;i<(n-1);i++)
    {
      for (j=0;j<n-i-1;j++)
       {
      	if(c[j] < c[j+1])
         {
           temp=c[j];
           c[j]=c[j+1];
           c[j+1]=temp;

           temp=b[j];
           b[j]=b[j+1];
           b[j+1]=temp;

           temp=a[j];
           a[j]=a[j+1];
           a[j+1] = temp;
      	}
       }
    }
}

void CalcBiggestNumber(int a[],int n)
{
  int digit,count,maxdigit=0;
  int b[n],c[n],i,j;

  for(i=0;i<n;i++)
   {
     int digit=a[i];
     count=0;
     while(digit!=0)
      {
      	digit=digit/10;
        count++;
      }
     b[i]=count;

     if(count>maxdigit)
      	maxdigit=count;
   }
  maxdigit++;
  long long int big=0;

  for(int i=0;i<n;i++)
   {
     c[i]=a[i];
     digit=b[i];
     while(digit<maxdigit)
      {
	c[i]=(c[i]*(CalcPower(10,b[i])))+a[i];
	digit=b[i]+digit;
      }

    while(digit!=maxdigit)
      {
        c[i]=c[i]/10;
        digit--;
      }
   }

 SortElements(c,a,b,n);
 big=a[0];
 for(i=1;i<n;i++)
  {
    big=(big*(CalcPower(10,b[i])))+a[i];
  }

printf("\n\nBiggest Number: %lld",big);
}

void main()
{
  int i,n,k,m;
  float f;
  char check [10];
  FILE *fp;

  fp=fopen("BiggestNumber.txt","r+");
  fscanf(fp,"%d",&k);

  for(int j=0;j<k;j++)
   {
     printf("\nTestCase: %d\n",j+1);

     fscanf(fp,"%d",&m);
     int a[15];
  for(i=0;i<m;i++)
  {
     fscanf(fp,"%s",check);
     printf("\n %d element : %s",i,check);

     if(!sscanf(check, "%f", &f))
        {
           printf("\n\n Please enter a valid input!\n");
           i--;
        }
    else
    {
      n=f;
      if(f-n>0)
       {
         printf("\n\n Input is invalid!\n");
         i--;
       }

      else if(n<0)
       {
         printf("\n\n Invalid Input! \n");
         i--;
       }

     else
      {
        a[i]=n;
      }
     }
    }

    printf("\n\nThe array is : ");
    for(i=0;i<m;i++)
      printf("%d  ",a[i]);

    CalcBiggestNumber(a,m);

    printf("\n\n");
   }
}
