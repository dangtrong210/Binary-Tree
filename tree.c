#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
	int data;
	struct NODE *left;
	struct NODE *right;
} NODE;

NODE *create(int value)
{
	NODE *new = (NODE *)malloc(sizeof(NODE));
	new->data = value;
	new->left = new->right = NULL;
	return new;
}

NODE *insert(NODE *root, int value)
{
	if (root == NULL)
	{
		return create(value);
	}
	if (root->data > value)
	{
		root->left = insert(root->left, value);
	}
	else
		root->right = insert(root->right, value);
	return root;
}

struct NODE *findMinNode(struct NODE *node)
{
	struct NODE *current = node;
	while (current && current->left != NULL)
	{
		current = current->left;
	}
	return current;
}

struct NODE *delNode(struct NODE *root, int value)
{
	if (root == NULL)
	{
		return root;
	}
	if (root->data > value)
		root->left = delNode(root->left, value);
	else if (root->data < value)
	{
		root->right = delNode(root->right, value);
	}
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			return NULL;
		}
		else if (root->left == NULL)
		{
			struct NODE *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct NODE *temp = root->left;
			free(root);
			return temp;
		}
		struct NODE *temp = findMinNode(root->right);
		root->data = temp->data;
		root->right = delNode(root->right, temp->data);
	}
	return root;
}

void print(NODE *root)
{
	if (root != NULL)
	{
		print(root->left);
		printf("%d ", root->data);
		print(root->right);
	}
}

int main()
{
	NODE *root = NULL;
	int value, n;
	printf("Nhap vao so Node: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Gia tri %d: ", i + 1);
		scanf("%d", &value);
		root = insert(root, value);
	}

	printf("Cay sau khi duoc tao: ");
	print(root);

	printf("\nNhap vao gia tri can xoa: ");
	scanf("%d", &value);
	root = delNode(root, value);
	printf("Cay sau khi xoa: ");
	print(root);
}