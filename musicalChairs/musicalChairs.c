#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define INPUTFILE "inputFile.txt"

typedef struct node{
  int data;
  struct node *next;
} NODE;

int count = 0;

void main()
{
  void enqueue(NODE **, int);
  void dequeue(NODE **, int);
  void readQueue(NODE *);
  int randomGenerate(int);
  //taking input from the file

  FILE *fp;
  if((fp = fopen(INPUTFILE, "r")) == NULL)
    {
      perror("InputFile ");
      exit(1);
    }

  int n; // number of elements
  int buffer; // var to hold elements comming from the file

  NODE *head = NULL;

  fscanf(fp, "%d", &n);
 printf("The number of elements are: %d \n", n);

  for (int i = 0; i < n; i++)
    {
      fscanf(fp, "%d", &buffer);
      enqueue(&head,buffer);
    }

  printf("The elements are: ");

  NODE *trace = head; // another var to move in the queue

  // Reading all the elements of the queue.

  readQueue(head);

  // generating random number
  int elementsLeft = n;
  for(int j = 1; j < n; j++)
    {
  int unfortunateGuy;
  unfortunateGuy = randomGenerate(elementsLeft);

  printf("\n The unfortunateGuy is : %d \n", unfortunateGuy+1);

  // moving to the unfortunate guy.

  /*
  trace = head;
  for(int i = 0; i < unfortunateGuy; i++)
    {
    trace = trace->next;
    }
  */

  // deleting that element and freeing the memory.
  dequeue(&head, unfortunateGuy);
  count = 0;
  readQueue(head);
  elementsLeft--;
    }
  printf("\n The winner is : %d \n", head->data);
}

void enqueue(NODE **ptr, int element)
  {
    if(*ptr == NULL)
      {
	//	printf("\n The queue is empty.Inserting first element. : %d \n", element);
	NODE *new = (NODE*) malloc(sizeof(NODE));
	new->data = element;
	new->next = NULL;
	*ptr = new;
	return;
      }
    else if((*ptr)->next == NULL)
      {
	//	printf("\n Only one element present. Adding element. : %d \n", element);
	NODE *new = (NODE*) malloc(sizeof(NODE));
	(*ptr)->next = new;
	new->data = element;
	new->next = NULL;
	return;
      }
    else if((*ptr) != NULL && (*ptr)->next != NULL)
      {
	//	printf("\n Seems like there are already elements in the queue! Adding : %d \n", element);
	NODE *traceEnd = *ptr;
	while(traceEnd->next != NULL)
	  traceEnd = traceEnd->next;
	NODE *new = (NODE*) malloc(sizeof(NODE));
	traceEnd->next = new;
	new->data = element;
	new->next = NULL;
	return;
      }
    printf("Enqueue Failed! You should die! ");
  }


void dequeue(NODE **ptr, int position)
{
  NODE *traceEnd = *ptr;
  NODE *prev = NULL;
  if(position == 0)
    *ptr = (*ptr)->next;
 else //moving to unfortunate guy
   {
     for(int i = 0; i < position; i++)
    {
    prev = traceEnd;
    traceEnd = traceEnd->next;
    }
  prev->next = traceEnd->next;
   }
  free(traceEnd);
}

void readQueue(NODE *trace)
{
    while(trace != NULL)
    {
      printf("%d ", trace->data);
      trace = trace->next;
      count++;
    }
    printf("\n Total no of elements left: %d \n", count);
}

int randomGenerate(int n)
{
  srand(time(NULL));
  return(rand() % n);
}
