/*
Musical Chairs problem:
input:
<number of TestCases>
<number of elements>
<E1> <E2> <E3> ... <En>

output:
1. Remove an element randomly
2. show the output in circular fashion.
3. Announce the winner in the end.


This code accepts only positive integers.

The code handles the exections if floating point, characters and bigger numbers are given.
*/


//header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>

#define INPUTFILE "inputFile.txt"
#define BUFFER_SIZE 256

// Global variables

bool isSpace = false;

typedef struct node{
  int data;
  struct node *next;
} node;

void enqueue(node **front, node **rear, int element)
{
  if(*front == NULL && *rear == NULL) // if queue is empty
  {
    *rear = (node*) malloc(sizeof(node));
    (*rear)->data = element;
    (*rear)->next = NULL;
    *front = *rear;
    return;
  }
  else if (*front == *rear) // if only one node is present
  {
    *rear = (node*) malloc(sizeof(node));
    (*front)->next = *rear;
    (*rear)->data = element;
    (*rear)->next = *front;
    return;
  }
  else if(*front != *rear) // if more than one node is present
  {
    node *new = (node*) malloc(sizeof(node));
    (*rear)->next = new;
    new->data = element;
    new->next = NULL;
    *rear = new;
    (*rear)->next = *front;
    return;
  }
  printf("Enqueue Failed!");
  exit(1);
}

void readQueue(node *front, node *rear)
{
  node *temp = front;
  while(temp != rear)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("%d",temp->data);
}


void circularRead(node *front, int position)
{
  node *temp = front;
  for(int i = 0; i < position; i++)
  temp = temp->next;

  node *trace = temp;
  do
  {
    printf("%d ", trace->data);
    trace = trace->next;
  }while(trace != temp);
}

int findElement(node *front, int position)
{
  node *temp = front;
  for(int i = 0; i < position; i++)
  temp = temp->next;
  return(temp->data);
}


void dequeue(node **front, node **rear, int position)
{
  if(*front != *rear)
  {
    node *temp = *front;
    node *prev = *front;
    if(!position)
    {
      // if 0th position given to remove
      *front = (*front)->next;
      (*rear)->next = *front;
      free(temp);
      return;
    }
    while(position)
    {
      prev = temp;
      temp = temp->next;
      position--;
    }
    if(temp == *rear)
    {
      // if last position given to remove
      prev->next = *front;
      free(*rear);
      *rear = prev;
      return;
    }
    //removing the node
    prev->next = temp->next;
    free(temp);
    return;
  }
  else
  printf("Trying to dequeue last node too.!");
  exit(1);
}


int randomGenerate(int n)
{
  srand(time(NULL));
  return(rand() % n);
}

int sizeOfQueue(node *front, node *rear)
{
  int count = 0;
  node *temp = front;
  while(temp != rear)
  {
    temp = temp->next;
    count++;
  }
  return(++count);
}

bool validationOfn(long long int *n)
{
  if(*n < INT_MAX)
  return true;
  else
  return false;
}


bool validationOfArr(char *ptr)
{
  while(*ptr != '\0')
  {
    if(*ptr == '.')
    {
      printf("Floating point not allowed!\n");
      return false;
    }
    if(!isdigit(*ptr))
    {
      printf("Invalid input.\n");
      return false;
    }
    ptr++;
  }
  return true;
}

/*--------------------------
main program
-------------------------- */

void main()
{
  /* Taking input from the file */

  FILE *fp;
  if((fp = fopen(INPUTFILE, "r")) == NULL)
  {
    perror("InputFile ");
    exit(1);
  }

  long long int n; // number of elements
  int buffer; // var to hold elements comming from the file
  int testCases;
  int count = 1; // to show testcase number
  int unfortunateGuy; // element to be removed
  char *arr = (char *) malloc(BUFFER_SIZE); // where the element will be stored
  fscanf(fp,"%d", &testCases);
  while(testCases)
  {
    printf("\n\n\t***TestCase: %d ***\n\n", count);
    fscanf(fp, "%lld", &n);
    if(!validationOfn(&n)) // checking the size of n.
    {
      printf("\nNumber of elements exceeded the limit.\n");
      testCases--;
      //fgets to read past the array below the n to reach next testcase
      fgets(arr, BUFFER_SIZE, fp);
      fgets(arr, BUFFER_SIZE, fp);
      for(int i = 0; i <BUFFER_SIZE; i++) //making all values of buffer to NULL.
      arr[i] = '\0';
      count++;
      continue;
    }
    printf("\nThe number of elements are: %lld \n\n", n);

    node *front = NULL;
    node *rear = NULL;
    bool invalidInput = false;
    for (int i = 0; i < n; i++)
    {
      fscanf(fp, "%s", arr);
      if(!validationOfArr(arr))
      {
        printf("Only positive integers are allowed. \n");
        //exit(1);
        invalidInput = true;
        continue;
      }
      if(invalidInput)
      continue;
      buffer = atoi(arr);
      if(buffer == -1)
      {
        invalidInput = true;
        printf("Size of element more than limit.\n");
        continue;
      }
      enqueue(&front,&rear, buffer);
    }
    if(invalidInput) // cleanup
    {
      for(int i = 0; i <BUFFER_SIZE; i++) //making all values of buffer to NULL.
      arr[i] = '\0';
      count++;
      testCases--;
      continue; // skip further code because the element earlier was invalid
    }
    printf("The elements are: ");

    // Reading all the elements of the queue.

    readQueue(front,rear);

    int elementsLeft = n; // no of elements left
    for(int j = 1; j < n; j++)
    {
      unfortunateGuy = randomGenerate(elementsLeft);
      printf("\n\nQueue: ");
      readQueue(front, rear);
      printf("\nKicking out: %d \n", findElement(front,unfortunateGuy));


      // deleting that element and freeing the memory.
      dequeue(&front,&rear, unfortunateGuy);

      circularRead(front, unfortunateGuy);
      printf("\nThe size of queue now: %d", sizeOfQueue(front, rear));
      elementsLeft--;
    }
    printf("\n\n ### The winner is : %d ###\n\n", front->data);
    for(int i = 0; i < BUFFER_SIZE; i++)
    arr[i] = '\0';
    count++;
    testCases--;
  }
}
