#include<stdio.h>
#include<stdlib.h>

#define INFINITY 999999

typedef struct adjacent
{
  int adjNode;
  int adjDist;
  adjacent *next;
};
typedef struct vertex
{
  int node;
  int minDistance;
  int relaxed;
};

void main()
{
  int noOfElements = 0;
  printf("Please enter number of nodes: \n");
  scanf("%d",&noOfElements);

  vertex vertexArray[noOfElements];

  
}
