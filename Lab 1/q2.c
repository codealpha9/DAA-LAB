#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int data;
	struct Node* next;
}Node;

void append(Node** head,int value)
{
	Node* temp = *head;
	Node* new = (Node*)calloc(1, sizeof(Node));
	new->data = value;
	if (temp == NULL)
	{	
		*head = new;
		return;
	}
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void print(Node* head)
{
	Node* temp = head;
	
	while(temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int n = 4, m = 4;
	// printf("Enter the number of Node: ");
	// scanf("%d", &n);

	// printf("Enter the number of Edges: ");
	// scanf("%d", &m)

	int **adj_matrix = (int**)calloc(n, sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		*(adj_matrix+i) = (int*)calloc(n, sizeof(int*));
	}

	char c;
	for(int i = 0; i < n; i++)
	{

		for(int j = i+1; j < n; j++)
		{
			printf("Is Node %d connected to Node %d: ", i+1, j+1);
			scanf(" %c", &c);
			if (c == 'y')
			{	
				adj_matrix[i][j] = 1;
				adj_matrix[j][i] = 1;
			}
			else
			{
				adj_matrix[i][j] = 0;
				adj_matrix[j][i] = 0;
			}
		}
	}

	// Printing the Adjacency Matrix
	printf("Adjacency Matrix:");
	for(int i=0; i < n; i++)
	{
		for (int j=0; j <n; j++)
		{
			printf("%d  ", adj_matrix[i][j]);
		}
		printf("\n");
	}
	
	// Generating Adjacency List
	Node** adj_list = (Node**)calloc(n, sizeof(Node*));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (adj_matrix[i][j] == 1)
			{
				append(adj_list+i, j+1);
			}
		}
	}

	printf("Adjacency List:\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d : ", i+1);
		print(*(adj_list+i));
	}

	return 0;
}
