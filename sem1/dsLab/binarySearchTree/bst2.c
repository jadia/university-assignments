#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

#define INPUTFILE "inputFile.txt"

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node* createNode(int element)
{
	struct node* new = (struct node*)malloc(sizeof(struct node));
	new->data = element;
	new->left = NULL;
	new->right = NULL;
	return(new);
}

struct node* insertNode(struct node* tree, int element)
{
	if(tree == NULL)
	{
		return(createNode(element));
	}
	if(element > tree->data)
	tree->right = insertNode(tree->right, element);
	else
	tree->left = insertNode(tree->left, element);
}


void preorder(struct node* tree)
{
	// preorder print Root Left Right
	if(tree == NULL)
	return;
	printf("%d ", tree->data);
	preorder(tree->left);
	preorder(tree->right);
}

void inorder(struct node* tree)
{
	// inorder print Root Left Right
	if(tree == NULL)
	return;

	inorder(tree->left);
	printf("%d ", tree->data);
	inorder(tree->right);
}


void postorder(struct node* tree)
{
	// postorder print Root Left Right
	if(tree == NULL)
	return;
	postorder(tree->left);
	postorder(tree->right);
	printf("%d ", tree->data);
}

bool validation(char temp)
{
	if(isdigit(temp))
	return true;
	else
	return false;
}

void main()
{
	FILE *fp;
	if((fp = fopen(INPUTFILE, "r")) == NULL)
	{
		perror("InputFile:");
		exit(1);
	}

	int flag = 0; // to check if input was invalid
	int n; // number of elements
	int testCases;
	fscanf(fp,"%d", &testCases);
	while(testCases)
	{
		flag = 0;
		printf("flag value - %d \n", flag);
		fscanf(fp,"%d", &n);
		printf("Value of n: %d \n", n);
		int i;
		int buffer[n];
		char temp;
		char arr[256];
		for(i = 0; i<n; i++)
		{
			fscanf(fp,"%s", &temp);
			if(temp == ' ' || temp == '\0')
			{
				printf("Space encountered");
				continue;
			}
			if(validation(temp))
			{
				buffer[i] = temp - '0';
				printf("%d, %c - ", buffer[i], temp);
			}
			else
			{
				printf("Making flag true");
				flag = 1;
				printf("\nInvalid Input for %c", temp);
				break;
			}
		}
		if(flag)
		{
			testCases--;
			printf("\n Flag value - %d, Invoking continue at line 123", flag);
			continue;
		}
		struct node *tree = NULL;
		tree = insertNode(tree, buffer[0]); // initializing tree
		// now resume node insertion
		for(i = 1; i<n; i++)
		{
			insertNode(tree, buffer[i]);
			printf("Inserting a node: %d",i);
		}

		// printing

		printf("\n PreOrder: ");
		preorder(tree);
		printf("\n InOrder: ");
		inorder(tree);
		printf("\n PostOrder: ");
		postorder(tree);
		printf("\n");

		testCases--;
	}
	printf("We are out of while loop");
}
