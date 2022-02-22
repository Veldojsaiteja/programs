#include<stdio.h>

#include<stdlib.h>

struct node {
  int data;
  struct node * next;
};
struct node * front = NULL;
struct node * rear = NULL;

void enqueue(int data) {
  struct node * newnode = (struct node * ) malloc(sizeof(struct node));
  newnode -> data = data;
  newnode -> next = NULL;
  if (front == NULL && rear == NULL) {
    front = newnode;
    rear = newnode;
  } else {
    rear -> next = newnode;
    rear = newnode;
  }
  printf("inserted successfully!!");
}
void dequeue() {
  if ((front == NULL && rear == NULL))
    printf("queue is empty!!");
  else {
    if (front == rear) {
      front = NULL;
      rear = NULL;
    } else front = front -> next;
    printf("deleted successfully!!");

  }

}
void display() {
  if ((front == NULL && rear == NULL))
    printf("queue is empty!!");
  else {
    struct node * temp = front;
    printf("\nThe Elements are : ");
    while (temp != NULL) {
      printf(" %d", temp -> data);
      temp = temp -> next;
    }
  }
}
void peek_front() {
  if ((front == NULL && rear == NULL))
    printf("queue is empty!!");
  else {
    printf("the front element is : %d", front -> data);
  }

}
void peek_rear() {
  if ((front == NULL && rear == NULL))
    printf("queue is empty!!");
  else {
    printf("the rear element is : %d", rear -> data);
  }
}
int main() {
  int n, choice, input;
  while (1) {
    printf("\n---------------------------\n");
    printf("1.enqueue\n2.dequeue\n3.DISPLAY\n4.front element\n5.rear element\n6.EXIT");
    printf("\nenter your choice : ");
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      printf("enter the element : ");
      scanf("%d", & input);
      enqueue(input);
      break;
    case 2:
      dequeue();
      break;
    case 3:
      display();
      break;
    case 4:
      peek_front();
      break;
    case 5:
      peek_rear();
      break;
    case 6:
      return 0;
      break;
    default:
      printf("Invalid operation!!");
      break;
    }
  }
}
