#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
	int key;
	struct Node *left, *right;
}Node;

Node* create_node(int key)
{
	Node* root_node;
	root_node = (Node*)calloc(sizeof(Node), 1);
	root_node->key = key;
	root_node->right = NULL;
	root_node->left = NULL;
	return root_node;
}

void key_search(Node **root, int key)
{

	Node* temp = *root;
	if (*root == NULL)
	{
		*root = create_node(key);
		printf("Added 1st Node");
		return;
	}

	do
	{
		if (key == temp->key)
		{	
			printf("Key Found\n");
			return;
		}

		// if (temp->left != NULL && temp->right !=NULL)
		// 	break;

		if (key > temp->key)
		{
			if (temp->right == NULL) break;
			temp = temp->right;
		}
		else
		{
			if (temp->left == NULL) break;
			temp = temp->left;
		}

	}while(1);
	
	// Inserting if not found
	if (key < temp->key)
		temp->left = create_node(key);
	else
		temp->right = create_node(key);
	printf("Key %d Inserted\n", key);
}

void print_inorder(Node* root)
{
	if (root != NULL)
	{
		print_inorder(root->left);
		printf("%d  ", root->key);
		print_inorder(root->right);
	}
}

void print_preorder(Node* root)
{
	if (root != NULL)
	{
		printf("%d  ", root->key);
		print_preorder(root->left);
		print_preorder(root->right);
	}

}

void print_postorder(Node* root)
{
	if (root != NULL)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		printf("%d  ", root->key);
	}
}

int main()
{

	Node *root_node = NULL;
	
	key_search(&root_node, 5);
	key_search(&root_node, 5);
	key_search(&root_node, 8);
	key_search(&root_node, 6);
	key_search(&root_node, 8);
	key_search(&root_node, 6);

	print_inorder(root_node);printf("\n");
	print_preorder(root_node);printf("\n");
	print_postorder(root_node);printf("\n");


	return 0;
}
