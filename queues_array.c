#include<stdio.h>

int rear = -1, front = -1;
void enqueue(int queue[], int data, int size) {
  if (front == size - 1 || rear == size - 1)
    printf("Queue is full!!");
  else {
    if (rear == -1) {
      front++;
      rear++;
    } else rear++;
    queue[rear] = data;
    printf("enqueued succesfully!!");
  }
}
void dequeue() {
  if ((front == -1 && rear == -1) || front == rear + 1)
    printf("queue is empty!!");
  else {
    front++;
    printf("dequeued successfully!!");
  }
}
void display(int queue[]) {
  if ((front == -1 && rear == -1) || front == rear + 1)
    printf("queue is empty!!");
  else {
    printf("Elements in queue is : ");
    for (int i = front; i <= rear; i++) {
      printf(" %d", queue[i]);
    }
  }
}
int peek_front(int queue[]) {
  if ((front == -1 && rear == -1) || front == rear + 1)
    printf("queue is empty!!");
  else
    printf("Front element is : %d", queue[front]);
}
int peek_rear(int queue[]) {
  if ((front == -1 && rear == -1) || front == rear + 1)
    printf("queue is empty!!");
  else
    printf("Rear element is : %d", queue[rear]);
}
int main() {
  int n, choice, input;
  printf("enter the size of queue : ");
  scanf("%d", & n);
  if (n <= 0) {
    printf("Invalid size !!\n");
  } else {
    int queue[n];
    while (1) {
      printf("\n---------------------------\n");
      printf("1.enqueue\n2.dequeue\n3.DISPLAY\n4.front element\n5.rear element\n6.EXIT");
      printf("\nenter your choice : ");
      scanf("%d", & choice);
      switch (choice) {
      case 1:
        printf("enter the element : ");
        scanf("%d", & input);
        enqueue(queue, input, n);
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display(queue);
        break;
      case 4:
        peek_front(queue);
        break;
      case 5:
        peek_rear(queue);
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
}
