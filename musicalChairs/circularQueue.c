//Practicing circular Queue
/*
Notes: We won't use front just work using rear.
*/
#include<stdio.h>
#include<stdlib.h>

#define INPUTFILE "inputFile.txt"

typedef struct node{
  int data;
  struct node *next;
} node;

int count = 0;

void enqueue(node **front, node **rear, int element)
{
  if(*front == NULL && *rear == NULL)
  {
    printf("\n The queue is empty.Inserting first element. : %d \n", element);
    *rear = (node*) malloc(sizeof(node));
    (*rear)->data = element;
    (*rear)->next = NULL;
    *front = *rear;
    return;
  }
  else if (*front == *rear)//else if((*front)->next == NULL)
  {
    printf("\n Only one element present. Adding element. : %d \n", element);
    *rear = (node*) malloc(sizeof(node));
    (*front)->next = *rear;
    (*rear)->data = element;
    (*rear)->next = *front;
    return;
  }
  else if(*front != *rear)//else if((*front) != NULL && (*front)->next != NULL)
  {
    printf("\n Seems like there are already elements in the queue! Adding : %d \n", element);
    node *new = (node*) malloc(sizeof(node));
    (*rear)->next = new;
    new->data = element;
    new->next = NULL;
    *rear = new;
    (*rear)->next = *front;
    return;
  }
  printf("Enqueue Failed! You should die! ");
}

void readQueue(node *front, node *rear)
{
  node *temp = front;
    while(temp != rear)
    {
      printf("%d ", temp->data);
      temp = temp->next;
      count++;
    }
    printf("%d",temp->data);
    count++;
    printf("\n Total no of elements left: %d \n", count);
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

void main()
{
  printf("Simple program to implement Circular Queue. \n");

  /* Taking input from the file */

  FILE *fp;
  if((fp = fopen(INPUTFILE, "r")) == NULL)
  {
    perror("InputFile ");
    exit(1);
  }

  int n; // number of elements
  int buffer; // var to hold elements comming from the file

  fscanf(fp, "%d", &n);
  printf("The number of elements are: %d \n", n);

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
  printf("\n The position from where you want to read the data? \n ");
  int position;
  scanf("%d",&position);
  circularRead(front,position);
}
