#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * right;
  struct node * left;
};
struct node * root = NULL;

struct node* findMax(struct node * temp) {
  if (temp == NULL) return NULL;
  else if (temp -> right == NULL) return temp;
  else return findMax(temp -> right);
}
struct node * Delete(struct node * root, int data) {
  if (root == NULL) {
    printf("node not Found!");
    return root;
  } else if (data > root -> data) {
    root -> right = Delete(root -> right, data);
  } else if (data < root -> data) {
    root -> left = Delete(root -> left, data);
  } else {
    struct node * temp;
    if (root -> left && root -> right) //two children
    {
      temp = findMax(root -> left);
      root -> data = temp -> data;
      root -> left = Delete(root -> left, root -> data);
    } else if (root -> left != NULL && root -> right == NULL) //one child
    {
      temp = root;
      root = root -> left;
      free(temp);

      printf("Deleted Successfully!");
    } else if (root -> right != NULL && root -> left == NULL) //one child
    {
      temp = root;
      root = root -> right;
      free(temp);
      printf("Deleted Successfully!");
    } else //zero child
    {
      temp = root;
      free(temp);
      root = NULL;
      temp = NULL;
      printf("Deleted Successfully!");
    }
  }
  return root;
}
struct node * insert(struct node * temp, struct node * nn, int data) {
  if (temp == NULL) {
    temp = nn;
    return temp;
  } else if (data > temp -> data) {
    temp -> right = insert(temp -> right, nn, data);
    return temp;
  } else {
    temp -> left = insert(temp -> left, nn, data);
    return temp;
  }
}
void preorder(struct node * temp) {
  if (temp != NULL) {
    printf("%d -> ", temp -> data);
    preorder(temp -> left);
    preorder(temp -> right);
  }
}
void inorder(struct node * temp) {
  if (temp != NULL) {
    inorder(temp -> left);
    printf("%d -> ", temp -> data);
    inorder(temp -> right);
  }
}
void postorder(struct node * temp) {
  if (temp != NULL) {
    postorder(temp -> left);
    postorder(temp -> right);
    printf("%d -> ", temp -> data);
  }
}
int main() {
  int choice, n, count = 0;
  struct node * nn = NULL;
  while (1) {
    printf("\n1.insert\n2.display\n3.Delete\n4.Exit\n");
    printf("enter your choice : ");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      nn = (struct node * ) malloc(sizeof(struct node));
      printf("enter the data : ");
      scanf("%d", & n);
      nn -> data = n;
      nn -> left = NULL;
      nn -> right = NULL;
      root = insert(root, nn, n);
      printf("inserted successfully!!\n");
      break;
    case 2:
      printf("preorder : ");
      preorder(root);
      printf("\nInorder : ");
      inorder(root);
      printf("\npostorder : ");
      postorder(root);
      printf("\n------------\n");
      break;
    case 3:
      printf("enter the data to delete : ");
      scanf("%d", & n);
      root = Delete(root, n);
      break;
    case 4:
        return 0;
    default:
      printf("Invalid choice!!");
    }
  }
  return 0;
}
