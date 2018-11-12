#include<stdio.h>
#include<stdlib.h>

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

void main()
{

	FILE *fp;
	if((fp = fopen(INPUTFILE, "r")) == NULL)
	{
		perror("InputFile:");
		exit(1);
	}

	int n; // number of elements
	fscanf(fp,"%d", &n);

	int i;
	int buffer[n];
	for(i = 0; i<n; i++)
	{
		fscanf(fp,"%d", &buffer[i]);
	}
	
	struct node *tree = NULL;
	tree = insertNode(tree, buffer[0]);

	for(i = 1; i<n; i++)
	{
		insertNode(tree, buffer[i]);
	}

	// printing

	printf("\n PreOrder: ");
	preorder(tree);
	printf("\n InOrder: ");
	inorder(tree);
	printf("\n PostOrder: ");
	postorder(tree);

}	
