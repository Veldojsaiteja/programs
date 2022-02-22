#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
  int data;
  struct node *next;
};
struct node *head = NULL;
void push(int max, int *top) {
  int n;
  if( (*top) == max - 1) {
    printf("stack overflow!!\n");
  } else {
    printf("enter the element : ");
    scanf("%d", &n);
    struct node * newnode = (struct node * ) malloc(sizeof(struct node));
    if (head == NULL) {
      newnode -> data = n;
      newnode -> next = NULL;
      head = newnode;
      (*top)++;
      printf("Pushed successfully!!\n");
    } else {
      newnode -> data = n;
      newnode -> next = head;
      head = newnode;
      (*top)++;
      printf("Pushed successfully!!\n");
    }

  }
}
void pop(int * top) {
  if ((*top) == -1) {
    printf("stack underflow!!\n");
  }
  else if((*top) == 0)
  { head = NULL;
    (*top)--;
    printf("Poped successfully!!\n");
  }
  else {
    struct node *temp = head;
     head = head -> next;
    free(temp);
    (*top)--;
    printf("Poped successfully!!\n");
  }

}
void display(int *top) {
  struct node *temp = head;
  if ((*top) == -1) {printf("the list is empty!!\n");}
  else {
     printf("the elements are : ");
    while (temp != NULL) {
      printf(" %d", temp -> data);
      temp = temp -> next;
    }

  }
}
int top_of_stack()
{
return (head->data);
}
int main() {
  int top = -1, max, ch;
  printf("Enter size of Stack:");
  scanf("%d", &max);
  if (max <= 0) printf("Invalid Size!");
  else {
    while (1) {
      printf("\n--------------------\n");
      printf("1.) PUSH \n");
      printf("2.) POP \n");
      printf("3.) DISPLAY \n");
      printf("4.) TOP OF STACK \n");
      printf("5.) EXIT \n");
      printf("Enter your choice :");
      scanf("%d", & ch);
      switch (ch) {
      case 1:
        push(max, &top);
        break;
      case 2:
        pop(&top);
        break;
      case 3:
        display(&top);
        break;
      case 4:
        if (top!=-1) printf("top of the stack element is  : %d",top_of_stack());
        else printf("Stack is Empty!");
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid input!");
        break;
      }
    }
  }
  getch();
  return 0;
}
