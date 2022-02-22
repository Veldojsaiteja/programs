#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left, * right;
};
struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}
struct node* insertLevelOrder(int arr[], struct node* root,
					int i, int n)
{
	if (i < n)
	{
		struct node* temp = newNode(arr[i]);
		root = temp;

		root->left = insertLevelOrder(arr,
				root->left, 2 * i + 1, n);

		root->right = insertLevelOrder(arr,
				root->right, 2 * i + 2, n);
	}
	return root;
}
void inOrder(struct node* root)
{
	if (root != NULL)
	{
		inOrder(root->left);
	  printf("%d  ",root->data);
		inOrder(root->right);
	}
}
void preOrder(struct node* root)
{
	if (root != NULL)
	{
    printf("%d  ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(struct node* root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
    printf("%d  ",root->data);
	}
}

int main()
{
  int n;
  printf("enter no of elements : ");scanf("%d",&n);
  int arr[n];
  printf("enter the elements : ");
	for(int i = 0; i<n; i++)
      scanf("%d",&arr[i]);
	struct node* root = insertLevelOrder(arr, root, 0, n);
  printf("inorder : ");
	inOrder(root);
  printf("\npreorder : ");
	preOrder(root);
  printf("\npostorder : ");
	postOrder(root);
  return 0;
}
