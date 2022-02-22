#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node {
  int data;
  struct node * next;
};
struct node * head;

int countnodes() {
  int count = 0;
  struct node * temp = head;
  while (temp != NULL) {
    temp = temp -> next;
    count++;
  }
  return count;
}
void insertion_at_beg() {
  int n;
  printf("enter the data : ");
  scanf("%d", & n);
  struct node * newnode = (struct node * ) malloc(sizeof(struct node));
  if (head == NULL) {
    head = newnode;
    newnode -> data = n;
    newnode -> next = NULL;
  } else {
    newnode -> data = n;
    newnode -> next = head;
    head = newnode;
  }
  printf("Inserted successfully!!");
}
void insertion_at_end() {
  int n;
  struct node * temp = head;
  printf("enter the data : ");
  scanf("%d", & n);
  struct node * newnode = (struct node * ) malloc(sizeof(struct node));
  if (head == NULL) {
    head = newnode;
    newnode -> data = n;
    newnode -> next = NULL;
  } else {
    while (temp -> next != NULL)
      temp = temp -> next;
    newnode -> data = n;
    newnode -> next = NULL;
    temp -> next = newnode;
  }
  printf("Inserted successfully!!");
}
void insertion_at_pos(int pos) {
  int n, count = 1;
  struct node * temp = head;
  printf("enter the data : ");
  scanf("%d", & n);
  struct node * newnode = (struct node * ) malloc(sizeof(struct node));
  while (count < pos - 1) {
    temp = temp -> next;
    count++;
  }
  newnode -> data = n;
  newnode -> next = temp -> next;
  temp -> next = newnode;
  printf("Inserted successfully!!");
}
void display() {
  if (countnodes() == 0) printf("The list is empty!!");
  else {
    printf("\nThe values in the linked list is :");
    struct node * temp = head;
    while (temp != NULL) {
      printf(" %d", temp -> data);
      temp = temp -> next;
    }
  }
}
void searchElement() {
  int n, count = 1, i = 1;
  struct node * temp = head;
  printf("enter the element you want to search : ");
  scanf("%d", & n);
  //struct node* newnode = (struct node*)malloc(sizeof(struct node));
  while (temp != NULL) {
    if (temp -> data == n) {
      printf("element found at position %d!!", i);
      count++;
      break;
    }
    i++;
    temp = temp -> next;
  }
  if (count == 1) printf("element not found!!");
}
void deletion_at_beg() {
  if (head == NULL)
    printf("wrong operation!!");
  else if(countnodes() == 1){ head = NULL; printf("Deleted successfully!!");}
  else{
    head = head -> next;
    printf("Deleted successfully!!");
  }
}
void deletion_at_end() {
  struct node * temp = head;
  int count = 1;
  if (head == NULL)
    printf("wrong operation!!");
  else if (countnodes() == 1){ head = NULL; printf("Deleted successfully!!");}
  else {
    while (count < countnodes() - 1) {
      temp = temp -> next;
      count++;
    }
    free((temp -> next));
    temp -> next = NULL;
    printf("Deleted successfully!!");
  }
}
void deletion_at_pos(int pos) {
  struct node * temp = head;
  int count = 1;
  while (count < pos - 1)
    temp = temp -> next;
  temp -> next = (temp -> next) -> next;
  free(temp -> next);
  printf("Deleted successfully!!");
}
int main() {
  int choice, pos;
  while (1) {
    printf("\n---------------------------\n");
    printf("1.insertion at beginning\n2.insertion at end\n3.insertion at position\n4.Display the elements\n5.count the nodes\n6.search the element\n7.deletion at beginning\n8.deletion at end\n9.deletion at position\n10.exit\n");
    printf("enter your choice : ");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      insertion_at_beg();
      break;
    case 2:
      insertion_at_end();
      break;
    case 3:
      printf("enter the position : ");
      scanf("%d", & pos);
      if (pos >= 1 && pos <= countnodes() + 1) {
        if (pos == 1) {
          insertion_at_beg();
          break;
        }
        if (pos == countnodes() + 1) {
          insertion_at_end();
          break;
        } else {
          insertion_at_pos(pos);
          break;
        }
      } else {
        printf("Invalid position\n");
        break;
      }
      case 4:
        display();
        break;
      case 5:
        printf("The total number nodes in SLL is : %d", countnodes());
        break;
      case 6:
        searchElement();
        break;
      case 7:
        deletion_at_beg();
        break;
      case 8:
        deletion_at_end();
        break;
      case 9:
        printf("enter the position : ");
        scanf("%d", & pos);
        if (pos >= 1 && pos <= countnodes() + 1) {
          if (pos == 1) {
            deletion_at_beg();
            break;
          }
          if (pos == countnodes() + 1) {
            deletion_at_end();
            break;
          } else {
            deletion_at_pos(pos);
            break;
          }
        } else {
          printf("invalid position!!");
          break;
        }
        case 10:
		getch();
          return 0;
        default:
          printf("Invalid choice!!");
          break;
    }
  }
 getch();
  return 0;
}
