//header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define INPUTFILE "inputFile.txt"

typedef struct node{
  int data;
  struct node *next;
} node;

bool validation(char input)
{

}


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

  int n; // number of elements
  int buffer; // var to hold elements comming from the file
  int testCases;
  int unfortunateGuy;
  fscanf(fp,"%d", &testCases);
while(testCases)
{
  fscanf(fp, "%d", &n);
  printf("\n---------------------\nThe number of elements are: %d \n \n", n);

  node *front = NULL;
  node *rear = NULL;

  for (int i = 0; i < n; i++)
  {
    fscanf(fp, "%d", &buffer);
    enqueue(&front,&rear, buffer);
  }

  printf("The elements are: ");

  // Reading all the elements of the queue.

  readQueue(front,rear);

  int elementsLeft = n;
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
  printf("\nThe winner is : %d \n", front->data);
  testCases--;
}
}
