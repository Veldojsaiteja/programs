#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node * prev;
  struct node * next;
};
struct node * head = NULL, * tail = NULL;

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
    tail = newnode;
    newnode -> data = n;
    newnode -> next = NULL;
    newnode -> prev = NULL;
  } else {
    newnode -> data = n;
    newnode -> next = head;
    newnode -> prev = NULL;
    head = newnode;

  }
  printf("\n--------------------\nInserted successfully!!\n--------------------\n");
}
void insertion_at_end() {
  int n;
  struct node * temp = head;
  printf("enter the data : ");
  scanf("%d", & n);
  struct node * newnode = (struct node * ) malloc(sizeof(struct node));
  if (head == NULL) {
    head = newnode;
    tail = newnode;
    newnode -> data = n;
    newnode -> next = NULL;
    newnode -> prev = NULL;
  } else {
    temp = tail;
    newnode -> data = n;
    newnode -> next = NULL;
    temp -> next = newnode;
    newnode -> prev = temp;
    tail = newnode;
  }
  printf("\n--------------------\nInserted successfully!!\n--------------------\n");
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
  temp -> next -> prev = newnode;
  newnode -> prev = temp;
  printf("\n--------------------\nInserted successfully!!\n--------------------\n");
}
void display() {
  if (countnodes() == 0) printf("\n--------------------\nThe list is empty!!\n--------------------\n");
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
  int n, count = 1, i =1;
  struct node * temp = head;
  printf("enter the element you want to search : ");
  scanf("%d", & n);
  //struct node* newnode = (struct node*)malloc(sizeof(struct node));
  while (temp != NULL) {
    if (temp -> data == n) {
      printf("\n--------------------\nelement found at position %d!!\n--------------------\n", i);
      count++;
      break;
    }
    i++;
    temp = temp -> next;
  }
  if (count == 1) printf("\n--------------------\nelement not found!!\n--------------------\n");
}
void deletion_at_beg() {
  if (countnodes() == 0) printf("\n--------------------\nwrong operation!!\n--------------------\n");
  else if (countnodes() == 1) {
    free(head);
    head = NULL;
    free(tail);
    tail = NULL;
    printf("\n--------------------\nDeleted Successfully!!\n--------------------\n");
  } else {
    struct node * temp = head;
    head = head -> next;
    free(temp);
    printf("\n--------------------\nDeleted successfully!!\n--------------------\n");
  }
}
void deletion_at_end() {
  //struct node* temp = head;
  //if(head == NULL)
  // printf("wrong operation!!");
  //else if(countnodes()==1) {free(head);free(tail);head = NULL; tail = NULL;}
  //else{
  //struct node* temp = tail;
  //tail->prev->next = NULL;
  //tail = tail->prev;
  //free(temp);
  //}
  if (countnodes() == 0) printf("\n--------------------\nwrong operation!!\n--------------------\n");
  else if (countnodes() == 1) {
    free(head);
    head = NULL;
    free(tail);
    tail = NULL;
    printf("\n--------------------\nDeleted Successfully!!\n--------------------\n");
  } else {
    struct node * temp = tail;
    tail -> prev -> next = NULL;
    tail = tail -> prev;
    free(temp);
    printf("\n--------------------\nDeleted Successfully!!\n--------------------\n");
  }
}
void deletion_at_pos(int pos) {
  int n, count = 1;
  struct node * temp = head;
  while (count < pos - 1) {
    temp = temp -> next;
    count++;
  }
  struct node * c = temp -> next;
  temp -> next = temp -> next -> next;
  temp -> next -> prev = temp;
  free(c);

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
        printf("\n--------------------\nInvalid position\n--------------------\n");
        break;
      }
      case 4:
        display();
        break;
      case 5:
        printf("\n--------------------\nThe total number nodes in SLL is : %d\n--------------------\n", countnodes());
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
        //printf("Nodes : %d\n", countnodes());
        if (pos >= 1 && pos <= countnodes() + 1) {
          if (pos == 1) {
            deletion_at_beg();
            break;
          }
          if (pos == countnodes()) {
            deletion_at_end();
            break;
          } else {
            deletion_at_pos(pos);
            break;
          }
        } else
          printf("\n--------------------\nwrong operation\n--------------------\n");
        break;
      case 10:
        getch();
        return 0;
      default:
        printf("\n--------------------\nInvalid choice!!\n--------------------\n");
        break;
    }
  }
  getch();
  return 0;
}
